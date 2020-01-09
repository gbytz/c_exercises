/*
Exercise 1-13. Write a program to print a histogram of the lengths of words in
its input. It is easy to draw the histogram with the bars horizontal; a vertical
orientation is more challenging
*/
#include <stdio.h>

#define IN 1
#define OUT 2
#define MAX_LENGTH 32

int main()
{
    int i, c, state, word_lenght, j;
    int lengths[MAX_LENGTH];

    // Wipe array
    for(i = 0; i < MAX_LENGTH; ++i)
        lengths[i] = 0;

    // Gather word length data
    state = OUT;
    word_lenght = 0;
    while((c = getchar()) != EOF)
        if(c != ' ' && c != '\t' && c != '\n')
        {
            state = IN;
            ++word_lenght;
        }
        else if (state == IN)
        {
            ++lengths[word_lenght-1];
            word_lenght = 0;
            state = OUT;
        }

    // Find maximum word length
    int max_count = -1;
    for(i = 0; i < MAX_LENGTH; ++i)
        if(lengths[i] >= max_count)
            max_count = lengths[i];

    // Draw histogram
    for(i = max_count; i >= 0; --i)
    {
        for(j = 0; j < MAX_LENGTH; ++j)
            if(lengths[j] > i)
                printf("%3s", "[]");
            else
                printf("%3c", ' ');
        putchar('\n');
    }

    for(i = 0; i < MAX_LENGTH; ++i)
        printf("%3d", i+1);
    putchar('\n');
}