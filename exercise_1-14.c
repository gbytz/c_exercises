/*
Exercise 1-14. Write a program to print a histogram of the frequencies of dif-
ferent characters in its input
*/
#include <stdio.h>

#define CHAR_AMOUNT '~' - ' ' + 1

int main()
{
    int c, i, j;
    int ocurrences[CHAR_AMOUNT];

    // Wipe array
    for(i = 0; i < CHAR_AMOUNT; ++i)
        ocurrences[i] = 0;

    // Gather character frecuency data
    while((c = getchar()) != EOF)
        if(' ' <= c && c <= '~')
            ++ocurrences[c-' '];

    // Find maximum character ocurrences
    int max_ocurrences = -1;
    for(i = 0; i < CHAR_AMOUNT; ++i)
        if(ocurrences[i] >= max_ocurrences)
            max_ocurrences = ocurrences[i];

    // Draw histogram
    for(i = max_ocurrences; i >= 0; --i)
    {
        for(j = 0; j < CHAR_AMOUNT; ++j)
            if(ocurrences[j] > i)
                printf("%2s", "@");
            else
                printf("%2c", ' ');
        putchar('\n');
    }
    for(c = ' '; c <= '~'; ++c)
    {
        printf("%2c", c);
    }
    putchar('\n');
}