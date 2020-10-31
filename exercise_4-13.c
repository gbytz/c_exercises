/*
Exercise 4-13. Write a recursive version of the function reverse(s) reverses the
string s in place.
*/
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_BYTES 128

void reverse(char s[]);

int main()
{
    char buffer[BUFFER_BYTES];
    while(get_word(buffer, BUFFER_BYTES) > 0)
    {
        printf("s: %s ", buffer);
        reverse(buffer);
        printf("reversed(s): %s\n", buffer);
    }
}

void reverse(char s[])
{
    static int i, j;

    if(s[i])
    {
        int c = s[i++];
        reverse(s);
        s[j++] = c;
    }

    if(i == j)
    {
        i = j = 0;
    }
}
