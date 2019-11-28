/*
Exercise 1-8. Write a program to count blanks, tabs, and newline.
*/
#include <stdio.h>

void main()
{
    int c, n_blanks, n_tabs, n_newlines;

    n_blanks = n_tabs = n_newlines = 0;
    while((c = getchar()) != EOF)
        if(c == ' ')
            ++n_blanks;
        else if(c == '\t')
            ++n_tabs;
        else if(c == '\n')
            ++n_newlines;

    printf("blanks: %4d tabs: %4d newlines: %4d\n", n_blanks, n_tabs, n_newlines);
}