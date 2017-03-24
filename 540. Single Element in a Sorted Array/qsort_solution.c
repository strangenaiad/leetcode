int comp( const int*l, const int*r )
{
    //printf( "[%d,%d] [%d,%d]\n", l[0], l[1], r[0], r[1] );
    
    if( l[0]!=l[1] ) {
        if( r[0]!=r[1] )
            return l[0] - r[0];
        return -1;
    }
    else if( l[0]==l[1] ) {
        if( r[0]!=r[1] )
            return 1;
        return l[0]-r[0];
    }

    return 1;
}


int singleNonDuplicate(int* nums, int numsSize) {
    qsort( nums, (numsSize+1)/2, sizeof(nums[0])+sizeof(nums[0]), (int (*)(const void*,const void*)) comp );
    
    return nums[0];
}