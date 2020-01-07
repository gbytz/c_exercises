/*
Exercise 1-12. Write a program that prints its input one word per line.
*/
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
    int c, state;

    state = OUT;

    while((c = getchar()) != EOF)
        if(c != ' ' && c != '\t' && c != '\n')
        {
            putchar(c);
            state = IN;
        }
        else if(state == IN)
        {
            putchar('\n');
            state = OUT;
        }
}