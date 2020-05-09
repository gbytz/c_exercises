/*
Exercise 2-8. Write a function rightrot(x, n) that returns the value of the integer x rotated to the right by n bit positions.
*/
#include <stdio.h>

int rightrot(unsigned x, int n);

int main()
{
    int x = 0x01010010;
    int n;
    for(n = 0; n <= 32; ++n)
    {
        printf("n: %d\n", n);
        printf("x:              %#010X\n", x);
        printf("rightrot(x, n): %#010X\n", rightrot(x, n));
    }
    return 0;
}

int rightrot(unsigned x, int n)
{
    return (n ? x >> n | (x << (32 - n)): x);
}
