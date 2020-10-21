/*
Exercise 4-8. Suppose that there will never be more than one character of
pushback. Modify getch and ungetch accordingly.
*/
#include <stdio.h>

int getch(void);
void ungetch(int c);

int main()
{
    int c;
    while((c = getchar()) != EOF)
    {
        ungetch(c);
        putchar(getch());
    }
    return 0;
}

#define BUFSIZE 100

int buf = EOF;

int getch(void) /* get a (possibly pushed back) character */
{
    int c = buf != EOF ? buf : getchar();
    buf = EOF;
    return c;
}

void ungetch(int c) /* push character back on input */
{
    if (buf != EOF)
        printf("ungetch: too many characters\n");
    else
        buf = c;
}
