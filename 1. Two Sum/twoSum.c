/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *ret = (int*) calloc( 2, sizeof(int));
    int x;
    int y;
    int delta;
    
    for( x=1; x<numsSize; x++ )
    {
        delta = target-nums[x];

        for( int y=0; y<x; y++ )
        {
            if( nums[y]==delta )
            {
                ret[0] = y;
                ret[1] = x;
                return ret;
            }
        }
    }
    
    return ret;
}