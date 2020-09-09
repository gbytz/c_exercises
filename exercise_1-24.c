/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This program is
hard if you do it in full generality.)
*/
#include <ctype.h>
#include <stdio.h>

int is_balanced(char match);
int isodigit(int arg);

int main()
{
    if(is_balanced(EOF))
    {
        printf("balanced\n");
    }
    else
    {
        printf("unbalanced\n");
    }
    return 0;
}

int is_balanced(char match)
{
    int balanced, c, d, e, f;
    balanced = 1;
    while(balanced && (c = getchar()) != match)
    {
        if(c == '/')
        {
            d = getchar();
            if(d == '/')
            {
                while((e = getchar()) != EOF && e != '\n')
                    ;
            }
            else if(d == '*')
            {
                while((e = getchar()) != EOF && (e != '/' || f != '*'))
                {
                    f = e;
                }
                balanced = e != EOF;
            }
        }
        else if(c == '\\' )
        {
            d = getchar();
            if(d == 'x')
            {
                e = getchar();
                f = getchar();
                balanced = isxdigit(e) && isxdigit(f);
            }
            else if(isodigit(d))
            {
                e = getchar();
                f = getchar();
                balanced = isodigit(e) && isodigit(f);
            }
            else
            {
                balanced = (d == 'a' || d == 'b' || d == 'f' || d == 'n'
                         || d == 'r' || d == 't' || d == 'v' || d == '\\'
                         || d == '\?' || d == '\'' || d == '\"');
            }
        }
        else if(c == '\'' || c == '\"')
        {
            while(((d = getchar()) != c || (e == '\\' && f != '\\')) && d != EOF)
            {
                f = e;
                e = d;
            }
            balanced = c == d;
        }
        else if(c == '(' || c == '[' || c == '{')
        {
            if(c == '(')
                d = ')';
            else if(c == '[')
                d = ']';
            else
                d = '}';
            balanced = is_balanced(d);
        }
        else
        {
            balanced = (c != ')' && c != ']' && c != '}' && c != EOF);
        }
    }
    return balanced;
}

int isodigit(int arg)
{
    return '0' <= arg && arg <= '7';
}
