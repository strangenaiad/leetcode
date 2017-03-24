char* reverseStr(char* s, int k) {
    int leng = strlen(s);
    int nWrote = 0;
    int half = k/2;

    while( nWrote<leng )
    {
        char *p = &s[nWrote];
        if( leng-nWrote>=k )
        {
            // reverse
            for( int j=0; j<half; j++ )
            {
                char ch = p[j];
                p[j] = p[k-1-j];
                p[k-1-j] = ch;
            }
            
            nWrote += k;
        }
        else
        {
            half = (leng-nWrote)/2;
            int end = leng-nWrote;
            
            // reverse
            for( int j=0; j<half; j++ )
            {
                char ch = p[j];
                //printf( __FILE__ "(%d): %d %c\n", __LINE__, nWrote+j, ch );
                
                p[j] = p[end-1-j];
                p[end-1-j] = ch;
            }
            
            nWrote += k;
        }

        if( leng-nWrote>=k )
        {
            nWrote += k;
        }
        else
        {
            break;
        }
    }
    

    
    return s;
}