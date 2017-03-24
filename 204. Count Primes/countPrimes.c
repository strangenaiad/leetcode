
const static unsigned int b32[] = 
                      { 0x01, 0x02, 0x04, 0x08
                      , 0x10, 0x20, 0x40, 0x80
                      , 0x0100, 0x0200, 0x0400, 0x0800
                      , 0x1000, 0x2000, 0x4000, 0x8000
                      , 0x010000, 0x020000, 0x040000, 0x080000
                      , 0x100000, 0x200000, 0x400000, 0x800000
                      , 0x01000000, 0x02000000, 0x04000000, 0x08000000
                      , 0x10000000, 0x20000000, 0x40000000, 0x80000000 };



int countPrimes(int n) {
    unsigned int *bits = (unsigned int*) calloc( 4, (n+31)/32 );

    int count = 0;
    int i;
    for( i=2; i<n; i++ )
    {
        if( 0==(bits[i>>5] & b32[i&31])) // prime
        {
            count++;
            
            int j=i;
            while( (j+=i)<n )
            {
                bits[j>>5] |= b32[j&31]; // not prime
            }
        }
    }
    
    free(bits);
    return count;
}