/*
Exercise 1-22. Write a program to "fold" long input lines into two or more
shorter lines after the last non-blank character that occurs before the n-th
column of input. Make sure your program does something intelligent with very
long lines, and if there are no blanks or tabs before the specified column.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void fold(int width, char s[], char t[]);

int main()
{
    char line_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];

    for(int i = 0; i < BUFFER_SIZE; ++i)
        dest_buffer[i] = '@';

    while(getline_(line_buffer, BUFFER_SIZE) > 0)
    {
        fold(80, line_buffer, dest_buffer);
        printf("%s", dest_buffer);
    }
    return 0;
}

int getline_(char buffer[], int length)
{
    int i, c;
    for(i = 0; i < length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        buffer[i] = c;
    }

    if(c == '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';

    return i;
}

void fold(int width, char s[], char t[])
{
    int i, j, k, l, m;
    i = j = k = l = m = 0;
    while(s[i] != '\0')
    {
        if(s[i] == ' ' && k % width != width - 1)
        {
            l = i;
            m = j;
        }

        t[j] = s[i];

        if(k % width == width - 1)
        {
            i = l;
            j = m;
            ++j;
            t[j] = '\n';
        }

        i++;
        j++;
        k++;
    }
    t[j] = '\0';
}
