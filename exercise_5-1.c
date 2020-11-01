/*
Exercise 5-1. As written, getint treats a + or - not followed by a digit as a
valid representation of zero. Fix it to push such a character back on the input.
*/
#include <ctype.h>
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_BYTES 128

int getch(void);
void ungetch(int);
int getint(int *pn);

int main()
{
    char buffer[BUFFER_BYTES];
    int n;
    while(getint(&n) > 0)
    {
        printf("n: %d\n", n);
    }
    return 0;
}

/* getint: get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))    /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     /* it's not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if(!isdigit(c))
        {
            ungetch(c);
            ungetch(sign == -1 ? '-' : '+');
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
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


