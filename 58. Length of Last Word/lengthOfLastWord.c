int lengthOfLastWord(char* s) {
    int leng = strlen(s);
    
    while( leng>0 && s[leng-1]==' ' )
        leng--;
    
    if( leng<1 )
        return 0;
    
    int i;
    for( i=0; i<leng; i++ )
    {
        if( s[leng-i-1]==' ')
            return i;
    }

    return i;
}