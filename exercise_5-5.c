/*
Exercise 5-5. Write versions of the library functions strncpy, strncat, and
strncmp; which operate on at most the first n characters of their argument
strings. For example, strncpy(s, t, n) copies at most n characters of t to s.
Full descriptions are in Appendix B.
*/
#include <stddef.h>
#include <stdio.h>

#include "io_utils.c"

#define BUFFER_BYTES 64

// copy at most n characters of string ct to s; return s. Pad with '\0's if t
// has fewer than n characters.
char *strncpy(char *s, const char *ct, size_t n);

// concatenate at most n characters of string ct to s, terminate s with '\0';
// return s.
char *strncat(char *s, const char *ct, size_t n);

// compare at most n characters of string cs to string ct; return <0 if
// cs < ct, 0 if cs == ct, or >0 if cs > ct.
int strncmp(const char *cs, const char *ct, size_t n);

int main()
{
    char cs[BUFFER_BYTES];
    char ct[BUFFER_BYTES];
    char s[BUFFER_BYTES];
    size_t n = 5;
    while(get_word(cs, BUFFER_BYTES) > 0 && get_word(ct, BUFFER_BYTES) > 0)
    {
        printf("strncpy(s, cs: %s, n: %lu): %s\n", cs, n, strncpy(s, cs, n));
        printf("strncat(s, ct: %s, n: %lu): %s\n", ct, n, strncat(s, ct, n));
        printf("strncmp(cs: %s, ct: %s, n: %lu): %d\n", cs, ct, n, strncmp(cs, ct, n));
    }
    return 0;
}

char *strncpy(char *s, const char *ct, size_t n)
{
    char *u = s;
    while(n-- > 0 && ((*ct && (*s++ = *ct++)) || !(*s++ = '\0')))
        ;
    *s = '\0';
    return u;
}

char *strncat(char *s, const char *ct, size_t n)
{
    char *u = s;
    while(*s)
    {
        s++;
    }
    strncpy(s, ct, n);
    return u;
}

int strncmp(const char *cs, const char *ct, size_t n)
{
    while(n > 1 && *cs && *ct && *cs == *ct)
    {
        cs++;
        ct++;
        n--;
    }
    return (*cs - *ct) * n;
}
