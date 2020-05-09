/*
Exercise 3-2. Write a function escape(s, t) that converts characters like
newline and tab into visible escape sequences like \n and \t as it copies the
string t to s. Use a switch. Write a function for the other direction as well,
converting escape sequences into the real characters.
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char s[BUFFER_SIZE], u[BUFFER_SIZE];
    for(int i = 0; i < BUFFER_SIZE; ++i)
    {
        s[i] = '\0';
        u[i] = '\0';
    }

    char t[] =
    "		 \n"
    "	    \n"
    "	 		\n"
    "	\n"
    "		  \n"
    ;

    printf("t:\n %s\n", t);
    escape(s, t);
    printf("escape(s, t):\n %s\n", s);
    unescape(u, s);
    printf("unescape(u, s):\n %s\n", u);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for(i = j = 0; t[i] != '\0' && j < BUFFER_SIZE; ++i)
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
}

void unescape(char s[], char t[])
{
    int i, j;
    for(i = j = 0; t[i] != '\0' && j < BUFFER_SIZE; ++i)
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
}
