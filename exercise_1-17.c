/*
Exercise 1-17. Write a program to print all input lines that are longer than 80
characters.
*/
#include <stdio.h>

#define LOWER_LIMIT 80
#define UPPER_LIMIT 1024

int getline_(char buffer[], int length);

int main()
{
    int len;
    char buffer[UPPER_LIMIT];
    while((len = getline_(buffer, UPPER_LIMIT)) > 0)
        if(len > LOWER_LIMIT)
            printf("%s", buffer);
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