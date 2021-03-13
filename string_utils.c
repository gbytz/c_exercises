#include <ctype.h>

int str_equ(const char s[], const char t[])
{
    while(*s && *t && *s++ == *t++)
        ;
    return *s == *t;
}

char* str_map(const char *s, char *t, int (*func)(int))
{
    char *init_t = t;
    while(*t++ = (*func)(*s++))
        ;
    return init_t;
}

char* str_tolower(const char *s, char *t)
{
    return str_map(s, t, tolower);
}

char* str_toupper(const char *s, char *t)
{
    return str_map(s, t, toupper);
}

char* str_map_inplace(char *s, int (*func)(int))
{
    char *init_s = s;
    while(*s = (*func)(*s))
        s++;
    return init_s;
}

char* str_tolower_inplace(char *s)
{
    return str_map_inplace(s, tolower);
}

char* str_toupper_inplace(char *s)
{
    return str_map_inplace(s, toupper);
}
