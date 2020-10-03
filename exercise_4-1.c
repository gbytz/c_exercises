/*
Exercise 4-1. Write the function strrindex(s, t), which returns the position
of the rightmost occurrence of t in s, or -1 if there is none.
*/
#include <stdio.h>
#include <string.h>
#include "io_utils.c"

#define BUFFER_SIZE 1024

int strrindex(char s[], char t[]);

int main()
{
    char s[BUFFER_SIZE];
    char t[BUFFER_SIZE];
    get_word(s, BUFFER_SIZE);
    get_word(t, BUFFER_SIZE);
    printf("s: %s\nt: %s\ni: %d\n", s, t, strrindex(s, t));
    return 0;
}

int strrindex(char s[], char t[])
{
    int result = -1;
    size_t ls, lt;
    if((ls = strlen(s)) > 0 && (lt = strlen(t)) > 0)
    {
        int i, j;
        for(i = ls - 1; i >= 0; --i)
        {
            for(j = lt - 1; j > 0 && i > 0 && s[i] == t[j]; --j, --i)
                ;

            if(j == 0 && s[i] == t[j])
            {
                result = i;
                break;
            }
        }
    }
    return result;
}
