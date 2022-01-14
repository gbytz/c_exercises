/*
Exercise 1-19. Write a function reverse(s) that reverses the character string s.
Use it to write a program that reverses its input a line at a time.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void reverse(char s[]);

int main()
{
    char buffer[BUFFER_SIZE];

    while(getline_(buffer, BUFFER_SIZE) > 0)
    {
        reverse(buffer);
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

/* reverse: reverses the string s in place */
void reverse(char s[])
{
    int l, i;
    l = 0;
    while(s[l] != '\0')
        ++l;
    --l;

    if(s[l] == '\n')
        --l;

    for(i = 0; i < l; ++i, --l)
    {
        s[i] = s[i] + s[l];
        s[l] = s[i] - s[l];
        s[i] = s[i] - s[l];
    }
}