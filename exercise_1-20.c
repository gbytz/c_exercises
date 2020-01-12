/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of tab
stops, say every n columns. Should n be a variable or a symbolic parameter?
*/
#include <stdio.h>

#define TAB_STOP 4

int main()
{
    int c, col, spaces;
    col = 0;
    while((c = getchar()) != EOF)
    {
        if(c == '\t')
        {
            for(int spaces = TAB_STOP - (col % TAB_STOP); spaces > 0; --spaces)
            {
                putchar(' ');
                ++col;
            }
        }
        else if(c == '\n')
        {
            putchar(c);
            col = 0;
        }
        else
        {
            putchar(c);
            ++col;
        }
    }
    return 0;
}