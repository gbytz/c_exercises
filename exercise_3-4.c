/*
Exercise 3-4. In a two's complement number representation, our version of itoa
does not handle the largest negative number, that is, the value of n equal to
-(2^(wordsize-1)). Explain why not. Modify it to print that value correctly,
regardless of the machine on which it runs.
*/
#include <limits.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 12

void reverse(char s[]);
void itoa(int n, char s[]);

int main()
{
    int i;
    char buffer[BUFFER_SIZE];
    for(i = INT_MIN + 100; i >= INT_MIN; --i)
    {
        itoa(i, buffer);
        printf("i: %d\ta: %s\n", i, buffer);
        if(i == INT_MIN)
        {
            break;
        }
    }
    return 0;
}

void reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


void itoa(int n, char s[])
{
    int i, sign = 1;

    if(n < 0)
    {
        sign = -1;
    }

    i = 0;
    do
    {
        s[i++] = n % 10 * sign + '0';
    }
    while((n /= 10) != 0);

    if(sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
