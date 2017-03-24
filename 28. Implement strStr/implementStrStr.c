int strStr(char* haystack, char* needle) {
    int index=0;
    int leng = strlen(needle);
    int maxi = strlen(haystack)+1-leng;
    
    if( leng==0)
        return 0;

    for( index=0; index<maxi; index++ )
        if( haystack[index]==needle[0] && 0==memcmp( &haystack[index], needle, leng ) )
        {
            return index;
        }
    
    return -1;
}