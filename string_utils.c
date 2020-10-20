#include <ctype.h>

int are_equal(const char s[], const char t[])
{
    int i;
    for(i = 0; s[i] != '\0' && t[i] != '\0' && s[i] == t[i]; ++i)
        ;
    return s[i] == t[i];
}

char* to_lower(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; ++i)
    {
        s[i] = tolower(s[i]);
    }
    return s;
}

char* to_upper(char s[])
{
    int i;
    for(i = 0; s[i] != '\0'; ++i)
    {
        s[i] = toupper(s[i]);
    }
    return s;
}

