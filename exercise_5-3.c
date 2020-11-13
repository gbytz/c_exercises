/*
Exercise 5-3. Write a pointer version of the function strcat that we showed
in Chapter 2: strcat(s, t) copies the string t to the end of s.
*/
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_SIZE 32

void str_cat(char *s, const char *t);

int main()
{
    char s[BUFFER_SIZE];
    char t[BUFFER_SIZE];
    while(get_word(s, BUFFER_SIZE) > 0 && get_word(t, BUFFER_SIZE) > 0)
    {
        printf("s: %s t: %s ", s, t);
        str_cat(s, t);
        printf("strcat(s, t): %s\n", s);
    }
    return 0;
}

void str_cat(char *s, const char *t)
{
    while(*s)
        s++;
    while(*s++ = *t++)
        ;
}
