/*
Exercise 4-9. Our getch and ungetch do not handle a pushed-back EOF
correctly. Decide what their properties ought to be if an EOFis pushed back,
then implement your design.
*/
#include <stdio.h>

#define BUFFER_BYTES 128

int getch(void);
void ungetch(int c);

int main()
{
    int i, j, c;
    char buffer[BUFFER_BYTES];

    // Count characters in file, including EOF
    i = 0;
    do
    {
        ++i;
    }
    while((buffer[i-1] = getch()) != EOF);

    for(j = i-1  ; j >= 0; --j)
    {
        ungetch(buffer[j]);
    }

    for(j = 0; j < i; ++j)
    {
        c = getch();
        printf("c: %c d: %d\n", c, c);
    }

    return 0;
}

int buf[BUFFER_BYTES]; // buf of int instead of char
int bufp  = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if(bufp >= BUFFER_BYTES)
        printf("ungetch: too many characters");
    else
        buf[bufp++] = c;
}
