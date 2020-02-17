/*
Exercise 2-3. Write the function htoi(s), which converts a string of hexa-
decimal digits (including an optional 0x or 0X) into its equivalent integer
 value. The allowable digits are 0 through 9, a through f, and A through F.
*/

#include <stdio.h>
#include <ctype.h>

#define MAX_LINE 1024

int htoi(char s[]);

int main()
{
    int i, c;
    char buffer[MAX_LINE];

    for(i = 0; i < MAX_LINE - 1 && (c = getchar()) != '\n'; ++i)
        buffer[i] = c;
    buffer[i] = '\0';

    printf("htoi(s): %d\n", htoi(buffer));

    return 0;
}

int htoi(char s[])
{
    int i, n, term, lower;

    // Skip whitespace
    for(i = 0; isspace(s[i]); ++i);

    // Skip optional 0
    if(s[i] == '0')
        ++i;

    // Skip optional x or X
    lower = tolower(s[i]);
    if(lower == 'x')
        ++i;

    for(n = 0; isxdigit(s[i]); ++i)
    {
    	lower = tolower(s[i]);
        if(isdigit(s[i]))
            term = lower - '0';
        else
            term = lower - 'a' + 10;

        n = 16 * n + term;
    }
    return n;
}