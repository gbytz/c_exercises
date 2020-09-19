/*
Exercise 3-3. Write a function expand(s1, s2) that expands shorthand notations
like a-z in the string s1 into the equivalent complete list abc...xyz in s2.
Allow for letters of either case and digits, and be prepared to handle cases
like a-b-c and a-zO-9 and -a-z. Arrange that a leading or trailing - is
taken literally.
*/
#include <ctype.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void expand(char s1[], char s2[]);

int main()
{
    char line_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];
    while(getline_(line_buffer, BUFFER_SIZE))
    {
        expand(line_buffer, dest_buffer);
        printf("%s", dest_buffer);
    }

    return 0;
}

int getline_(char buffer[], int length)
{
    int i, c;
    for(i = 0; i < length - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        buffer[i] = c;
    }

    if(c == '\n')
    {
        buffer[i++] = c;
    }

    buffer[i] = '\0';

    return i;
}

void expand(char s1[], char s2[])
{
    int i, j;
    for(i = j = 0; s1[i] != '\0'; i++)
    {
        if(isalnum(s1[i]))
        {
            if(s1[i + 1] == '-' && isalnum(s1[i + 2]) && s1[i] < s1[i + 2])
            {
                char c;
                for(c = s1[i]; c < s1[i + 2]; ++c)
                {
                    s2[j++] = c;
                }
                i++;
            }
            else
            {
                s2[j++] = s1[i];
            }
        }
        else
        {
            s2[j++] = s1[i];
        }
    }
    s2[j] = '\0';
}
