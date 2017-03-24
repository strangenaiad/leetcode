int comp(const void*left, const void*right )
{
    return *(const int*)left - *(const int*)right;
}


void merge(int* nums1, int m, int* nums2, int n) {
    memcpy( &nums1[m], nums2, n*sizeof(int));
    qsort( nums1, m+n, sizeof(nums1[0]), comp );
}