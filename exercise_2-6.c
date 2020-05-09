/*
Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with the n
bits that begin at position p set to the rightmost n bits of y, leaving the
other bits unchanged.
*/
#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
    unsigned x = 0xFFFFFFFF;
    unsigned y = 0x00000000;

    int p, n;
    for(p = 0; p < 32; ++p)
    {
        for(n = 0; n <= p + 1; ++n)
        {
            printf("p: %d\n", p);
            printf("n: %d\n", n);
            printf("x:                   %#010X\n", x);
            printf("y:                   %#010X\n", y);
            printf("setbits(x, p, n, y): %#010X\n", setbits(x, p, n, y));
        }
    }
    return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned mask = n ? (~0U >> 32 - n) << (p + 1 - n) : 0;
    return (x & ~mask) | (y & mask);
}
