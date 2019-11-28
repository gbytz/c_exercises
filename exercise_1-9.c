/*
Exercise 1-9. Write a program to copy its input to its output, replacing each
string of one or more blanks by a single blank.
*/
#include <stdio.h>

void main()
{
    int c, previous_c;

    c = 0
    previous_c = EOF;
    while ((c = getchar()) != EOF)
    {
        if(c != ' ' || c != previous_c)
            putchar(c);
        previous_c = c;
    }
}