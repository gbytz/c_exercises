/*
Exercise 3-5. Write the function itob(n, s, b) that converts the integer n
into a base b character representation in the string s. In particular,
itob (n, s, 16) formats n as a hexadecimal integer in s.
*/
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 64

void itob(int n, char s[], int b);

int main()
{
    int i, j;
    char buffer[BUFFER_SIZE];
    for(i = 2; i < 20; ++i)
    {
        for(j = 1; j < 20; ++j)
        {
            itob(j, buffer, i);
            printf("b: %d n: %d s:%s\n", i, j, buffer);
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


void itob(int n, char s[], int b)
{
    int i, j, sign = 1;

    if(n < 0)
    {
        sign = -1;
    }

    i = 0;
    do
    {
        j = n % b * sign;
        if(j < 10)
        {
            s[i++] = j + '0';
        }
        else
        {
            s[i++] = j % 10 + 'A';
        }
    }
    while((n /= b) != 0);

    if(sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}
