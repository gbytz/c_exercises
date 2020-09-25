/*
Exercise 3-6. Write a version of itoa that accepts three arguments instead of
two. The third argument is a minimum field width; the converted number must
be padded with blanks on the left if necessary to make it wide enough.
*/
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 16

void reverse(char s[]);
void itoa(int n, char s[], int w);

int main()
{
    char buffer[BUFFER_SIZE];
    int i, j;
    for(i = -999999; i <= 999999; i += 111111)
    {
        for(j = 0; j <= 11; ++j)
        {
            itoa(i, buffer, j);
            printf("i: %d\tw: %d\ts:%s\n", i, j, buffer);
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


void itoa(int n, char s[], int w)
{
    int i, j, sign = 1;

    if(n < 0)
    {
        sign = -1;
    }

    i = 0;
    do
    {
        s[i++] = n % 10 * sign + '0';
        --w;
    }
    while((n /= 10) != 0);

    if(sign < 0)
    {
        s[i++] = '-';
        --w;
    }

    for(j = 0; j < w; ++j)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

