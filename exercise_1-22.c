/*
Exercise 1-22. Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024
#define COLUMN_WIDTH 80

int getline_(char buffer[], int limit);
int fold(char line[], int length);

int main()
{
    int length;
    char buffer[BUFFER_SIZE];
    while((length = getline_(buffer, BUFFER_SIZE)) > 0)
    {
        if(length > COLUMN_WIDTH)
        {
            fold(buffer, length);
        }
        printf("%s", buffer);
    }

    return 0;
}

int getline_(char buffer[], int limit)
{
    int c, i;
    for(i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        buffer[i] = c;

    if(c == '\n')
    {
        buffer[i] = c;
        ++i;
    }
    buffer[i] = '\0';

    return i;
}

int fold(char line[], int length)
{
    int i, j, last_blank;
    for(i = 0; i < length; ++i)
    {
        if(line[i] == ' ' || line[i] == '\t')
        {
            last_blank = i;
        }

        if((i % COLUMN_WIDTH) == COLUMN_WIDTH-1)
        {
            if(last_blank == -1)
            {
                for(j = length; j >= i; --j)
                {
                    line[j+1] = line[j];
                }
                line[i] = '\n';
                ++length;
                line[length] = '\0';
            }
            else
            {
                line[last_blank] = '\n';
                last_blank = -1;
            }
        }
    }
}