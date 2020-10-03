#include <ctype.h>
#include <stdio.h>

int get_word(char b[], int b_size)
{
    int c, i;
    i = 0;
    while(--b_size > 0 && (c = getchar()) != EOF && isgraph(c))
    {
        b[i++] = c;
    }
    b[i] = '\0';
    return i;
}

int get_line(char b[], int b_size)
{
    int c, i;
    i = 0;
    while(--b_size > 0 && (c = getchar()) != EOF && c != '\n')
    {
        b[i++] = c;
    }
    if(c == '\n')
    {
        b[i++] = c;
    }
    b[i] = '\0';
    return i;
}
