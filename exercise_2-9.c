/*
Exercise 2-9. In a two's complement number system, x &= (x-1) deletes the
rightmost 1-bit in x. Explain why. Use this observation to write a faster ver-
sion of bitcount.
*/
#include <stdio.h>

int bitcount(unsigned x);

int main()
{

    int x;
    for(int x = 0; x != 0xF; ++x)
    {
        printf("x:           %#010X\n", x);
        printf("bitcount(x): %010d\n", bitcount(x));
    }
    return 0;
}

int bitcount(unsigned x)
{
    int b;
    for(b = 0; x != 0; x &= (x-1), ++b);
    return b;
}
