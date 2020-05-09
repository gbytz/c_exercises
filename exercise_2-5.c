/*
Exercise 2-5. Write the function any(s1, s2), which returns the first location
in the string s1 where any character from the string s2 occurs, or -1 if s1
contains no characters from s2. (The standard library function strpbrk does
the same job but returns a pointer to the location.)
*/
#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
    char source[] = "abcdefabcdefabcdefabcdefabcdefabcdef.";
    char filter[] = "%.;";
    printf("%d\n", any(source, filter));
    return 0;
}

int any(char s1[], char s2[])
{
    int i, j, k;
    k = -1;
    for(i = 0; s1[i] != '\0' && k == -1; ++i)
    {
        for(j = 0; s2[j] != '\0' && k == -1; ++j)
        {
            if(s1[i] == s2[j])
            {
                k = i;
            }
        }
    }
    return k;
}