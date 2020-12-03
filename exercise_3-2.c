/*
Exercise 3-2. Write a function escape (s, t) that converts characters like
newline and tab into visible escape sequences like \n and \ t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char line_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];
    while(getline_(line_buffer, BUFFER_SIZE))
    {
        escape(dest_buffer, line_buffer);
        unescape(line_buffer, dest_buffer);
        printf("%s", line_buffer);
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
        buffer[i] = c;
        ++i;
    }

    buffer[i] = '\0';

    return i;
}

void escape(char s[], char t[])
{
    int i, j;
    for(i = j = 0; t[i] != '\0'; ++i)
    {
        switch(t[i])
        {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = '\0';
}

void unescape(char s[], char t[])
{
    int i, j;
    for(i = j = 0; t[i] != '\0'; ++i)
    {
        if(t[i] == '\\')
        {
            ++i;
            switch(t[i])
            {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
        }
        else
        {
            s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
