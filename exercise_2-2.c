/*
Exercise 2-2. Write a loop equivalent to the for loop above without using && or
||.
*/
#include <stdio.h>

#define MAX_LINE 1024

int main()
{
    int c, i, lim;
    char s[MAX_LINE];

    for(i = 0; ((i < lim-1) + ((c = getchar()) != '\n') + (c != EOF)) == 3; ++i)
        s[i] = c;

    return 0;
}
