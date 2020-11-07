/*
Exercise 5-2. Write getfloat, the floating-point analog of getint. What
type does getfloat return as its function value?
*/
#include <ctype.h>
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_BYTES 128

int getfloat(float *pn);

int main()
{
    char buffer[BUFFER_BYTES];
    float n;
    while(getfloat(&n) != 0)
    {
        printf("n: %f\n", n);
    }
    return 0;
}

int getch(void);
void ungetch(int c);

int getfloat(float *pn)
{
    int c;
    while(isspace(c = getch()))
        ;
    if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);
        return 0;
    }

    float sign = (c == '-') ? -1.0f : 1.0f;
    if(c == '+' || c == '-')
    {
        c = getch();
        if(!isdigit(c))
        {
            ungetch(c);
            ungetch(sign == -1.0f ? '-' : '+');
            return 0;
        }
    }
    for(*pn = 0.0f; isdigit(c); c = getch())
        *pn = 10.0f * *pn + (c - '0');

    if(c == '.')
        c = getch();
    float power;
    for(power = 1.0f; isdigit(c); c = getch())
    {
        *pn = 10.0f * *pn + (c - '0');
        power *= 10.0f;
    }

    *pn *= sign / power;
    if(c != EOF)
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
