/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Pos {
    int row;
    int col;
    int dist;
};

void cleanScore( int rows, int cols, int**score )
{
    for( int row=0; row<rows; row++ ) {
        for( int col=0; col<cols; col++ ) {
            score[row][col] = 0x80000000;
        }
    }
}


void testScore( int row, int col, int rows, int cols, int**score, int**result ) {
    struct Pos queue[20000] = {0};
    int        qi = 0;
    int        qn = 0;
    int      dist = 0;
    
    queue[qn].row = row;
    queue[qn].col = col;
    queue[qn].dist = 0;
    qn++;
    
    
    while( qi<qn ) {
        row = queue[qi].row;
        col = queue[qi].col;
        dist = queue[qi].dist;

        //printf( __FILE__ "(%d): %d/%d [%d][%d] %d\n", __LINE__, qi, qn, row, col, dist );

        qi++;
        if( qi==qn ) {
            qi = qn = 0;
        }


        if( result[row][col] > dist || result[row][col]<0 )
            result[row][col] = dist;

        // UP
        if( row>0 && score[row-1][col]&0x80000000 ) {
            score[row-1][col] &=~0x80000000;
            queue[qn].row = row-1;
            queue[qn].col = col;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // RIGHT
        if( col+1<cols && score[row][col+1]&0x80000000 ) {
            score[row][col+1] &=~0x80000000;
            queue[qn].row = row;
            queue[qn].col = col+1;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // DOWN
        if( row+1<rows && score[row+1][col]&0x80000000 ) {
            score[row+1][col] &=~0x80000000;
            queue[qn].row = row+1;
            queue[qn].col = col;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // LEFT
        if( col>0 && score[row][col-1]&0x80000000 ) {
            score[row][col-1] &=~0x80000000;
            queue[qn].row = row;
            queue[qn].col = col-1;
            queue[qn].dist = dist+1;
            qn++;
        }
    }
}



int** updateMatrix(int** matrix, int matrixRowSize, int *matrixColSizes, int** columnSizes, int* returnSize) {
    int **result = (int**) calloc( matrixRowSize, sizeof(int*));
    int **score  = (int**) calloc( matrixRowSize, sizeof(int*));
    *columnSizes = (int*) calloc( matrixRowSize, sizeof(int));
    *returnSize  = matrixRowSize;
    
    int row, col;

    for( row=0; row<matrixRowSize; row++  ) {
        result[row] = (int*) calloc( matrixColSizes[row], sizeof(int));
        score[row]  = (int*) calloc( matrixColSizes[row], sizeof(int));

        (*columnSizes)[row] = matrixColSizes[row];
        
        /*
        for( col=0; col<matrixColSizes[row]; col++ ) {
            //result[row][col] = -1;
            //score[row][col] = -1;
        }
        */
    }
    
    cleanScore( matrixRowSize, matrixColSizes[0], result );

    //#pragma omp parallel for
    for( row=0; row<matrixRowSize; row++ ) {
        for( col=0; col<matrixColSizes[row]; col++ ) {
            if( 0==matrix[row][col] ) {
                
                result[row][col] = 0;
                
                cleanScore( matrixRowSize, matrixColSizes[row], score );
                testScore( row, col, matrixRowSize, matrixColSizes[row], score, result );
            }
        }
    }

    return result;   
}
