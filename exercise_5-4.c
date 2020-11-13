/*
Exercise 5-4. Write the function strend(s , t), which returns 1 if the string
t occurs at the end of the string s, and zero otherwise.
*/
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_SIZE 32

int strend(const char *s, const char *t);

int main()
{
    char s[BUFFER_SIZE];
    char t[BUFFER_SIZE];
    while(get_word(s, BUFFER_SIZE) > 0 && get_word(t, BUFFER_SIZE) > 0)
    {
        printf("s: %s t: %s strend(s, t): %d\n", s, t, strend(s, t));
    }
    return 0;
}

int strend(const char *s, const char *t)
{
    const char *u = t;
    while(*s)
    {
        while(*s != *u && *s)
        {
            s++;
        }
        while(*s == *u && *s && *u)
        {
            s++;
            u++;
        }
        if(*s == *u)
        {
            return 1;
        }
        else
        {
            u = t;
        }
    }
    return 0;
}
