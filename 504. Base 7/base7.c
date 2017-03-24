int base7[] = { 1
              , 7
              , 7*7
              , 7*7*7
              , 7*7*7*7
              , 7*7*7*7*7
              , 7*7*7*7*7*7
              , 7*7*7*7*7*7*7
              , 7*7*7*7*7*7*7*7
              , 7*7*7*7*7*7*7*7*7
              , 7*7*7*7*7*7*7*7*7*7
              , 7*7*7*7*7*7*7*7*7*7*7 };

char* convertToBase7(int num) {
    int leng = 0;
    static char ret[12] = {0};
    int signal = 1;
    if( num<0 )
    {
        num = -num;
        signal = -1;
        ret[leng++] = '-';
    }
    
    //printf( __FILE__ "(%d): %d\n", __LINE__, num );

    
    int  lv = 11;
    while( base7[lv] > num && lv>0 )
        lv--;

    while( lv>=0 )
    {
        int x = num/base7[lv];
        
        num -= base7[lv] * x;
        ret[leng] = x + '0';
        
        //printf( __FILE__ "(%d): num=%d, ret=%s\n", __LINE__, num, ret );
        leng++;
        lv--;
    }
    
    if( leng<1 || (leng<2 && signal<0) )
        ret[leng++] = '0';

    ret[leng] = 0;

    return ret;
}