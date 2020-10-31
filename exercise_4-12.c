/*
Exercise 4-12. Adapt the ideas of printd to write a recursive version of itoa;
that is, convert an integer into a string by calling a recursive routine.
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_BYTES 16

void itoa(int n, char s[]);

int main()
{
    char buffer[BUFFER_BYTES];

    for(int i = INT_MIN; i <= INT_MAX - 4096; i += 4096)
    {
        itoa(i, buffer);
        printf("i: %d itoa(i): %s\n", i, buffer);
    }
    return 0;
}

void itoa(int n, char s[])
{
    static int i;

    if(n < 10 && n > -10)
    {
        i = 0;
        if(n < 0)
        {
            s[i++] = '-';
        }
        s[i++] = abs(n % 10) + '0';
        s[i] = '\0';
    }
    else
    {
        itoa(n / 10, s);
        s[i++] = abs(n % 10) + '0';
        s[i] = '\0';
    }
}
