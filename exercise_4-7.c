/*
Exercise 4-7. Write a routine ungets(s) that will push back an entire string
onto the input. Should ungets know about buf and bufp, or should it just
use ungetch?
*/
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_BYTES 1024

int getch(void);
void ungets(char s[]);

int main()
{
    int c;
    char buffer[BUFFER_BYTES];
    get_line(buffer, BUFFER_BYTES);
    printf("pre buffer: %s\n", buffer);
    ungets(buffer);
    while((c = getch()) != EOF)
    {
        putchar(c);
    }

    return 0;
}

#define BUFSIZE 100

char buf[BUFSIZE];  /*buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; ++i)
    {
        ungetch(s[i]);
    }
}
