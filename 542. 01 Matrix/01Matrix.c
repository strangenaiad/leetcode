/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

struct Pos {
    int index;
    int dist;
};


struct Pos queue[900000] = {0};
int        qi = 0;
int        qn = 0;


void testScore( int rows, int cols, int**result ) {
    
    int      dist = 0;
    int      index = 0;


    
    
    while( qi<qn ) {
        index = queue[qi].index;
        int row = index/cols;
        int col = index%cols;
        dist = queue[qi].dist;
        //printf( __FILE__ "(%d): %d/%d %d [%d][%d] %d\n", __LINE__, qi, qn, index, row, col, dist );


        qi++;
        if( qi==qn ) {
            qi = qn = 0;
        }

        if( result[row][col]>=0 && dist>result[row][col] )
            continue;
            
        //if( result[row][col]>=0 && dist-1>result[row][col] )
        //    continue;

        if( result[row][col] > dist || result[row][col]<0 )
            result[row][col] = dist;

        // UP
        if( row>0 ) {
            queue[qn].index = index-cols;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // RIGHT
        if( col+1<cols ) {
            queue[qn].index = index+1;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // DOWN
        if( row+1<rows ) {
            queue[qn].index = index+cols;
            queue[qn].dist = dist+1;
            qn++;
        }
        
        // LEFT
        if( col>0 ) {
            queue[qn].index = index-1;
            queue[qn].dist = dist+1;
            qn++;
        }
    }
}


int** updateMatrix(int** matrix, int matrixRowSize, int *matrixColSizes, int** columnSizes, int* returnSize) {
    int **result = (int**) calloc( matrixRowSize, sizeof(int*));

    *columnSizes = (int*) calloc( matrixRowSize, sizeof(int));
    *returnSize  = matrixRowSize;
    
    int row, col;
    for( row=0; row<matrixRowSize; row++  ) {
        result[row] = (int*) calloc( matrixColSizes[row], sizeof(int));

        (*columnSizes)[row] = matrixColSizes[row];
        
        for( col=0; col<matrixColSizes[row]; col++ ) {
            result[row][col] = -1;
        }
    }

    //#pragma omp parallel for
    for( row=0; row<matrixRowSize; row++ ) {
        for( col=0; col<matrixColSizes[row]; col++ ) {
            if( 0==matrix[row][col] ) {
                // 先把所有 0 起點放到 queue 裡面                
                result[row][col] = 0;
                queue[qn].index = row*matrixColSizes[row] + col;
                queue[qn].dist = 0;
                qn++;
                
            }
        }
    }
    
    // 從 queue 開始把迴圈跑完，分數就算完了
    testScore( matrixRowSize, matrixColSizes[0], result );
    return result;   
}