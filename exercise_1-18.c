/*
Exercise 1-18. Write a program to remove trailing blanks and tabs from each line
of input, and to delete entirely blank lines.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
int remove_trailing_blanks(char line[]);

int main()
{
    int len;
    char buffer[BUFFER_SIZE];

    while(getline_(buffer, BUFFER_SIZE) > 0)
    {
        len = remove_trailing_blanks(buffer);
        if(len > 0)
            printf("%s", buffer);
    }
    return 0;
}

int getline_(char buffer[], int length)
{
    int c, i;
    for(i = 0; i < length-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        buffer[i] = c;

    if(c == '\n')
    {
        buffer[i] = c;
        ++i;
    }
    buffer[i] = '\0';

    return i;
}

/* remove_trailing_blanks: removes trailing blanks from a C string */
int remove_trailing_blanks(char line[])
{
    int i, w;

    i = w = 0;
    while(line[i] != '\0' && line[i] != '\n')
    {
        if(line[i] == ' ' || line[i] == '\t')
            ++w;
        else
            w = 0;
        ++i;
    }

    i = i - w ;
    if(i > 0)
    {
        line[i] = '\n';
        i++;
    }
    line[i] = '\0';

    return i;
}
