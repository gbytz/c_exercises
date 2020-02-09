/*
Exercise 1-24. Write a program to check a C program for rudimentary syntax
errors like unbalanced parentheses, brackets and braces. Don't forget about
quotes, both single and double, escape sequences, and comments. (This program is
hard if you do it in full generality.)
*/
#include <stdio.h>

int is_unbalanced(char match);

int main()
{

    if(is_unbalanced(EOF))
        printf("unbalanced\n");
    else
        printf("balanced\n");

    return 0;
}


int is_unbalanced(char match)
{
    int c, m, unbalanced, d, e, f;
    unbalanced = 0;
    while(!unbalanced && (c = getchar()) != match)
    {
        // Handle comments
        if(c == '/')
        {
            d = getchar();
            if(d == '/')
            {
                while((e = getchar()) != '\n');
            }
            else if(d == '*')
            {
                while((e = getchar()) != '/' || f != '*')
                {
                    f = e;
                }
            }
        }
        // Handle single quotes, double quotes and escape secuences
        else if(c == '\'' || c == '\"')
        {
            while(((d = getchar()) != c || (e == '\\' && f != '\\')) && d != EOF)
            {
                f = e;
                e = d;
            }
            unbalanced = c != d;
        }
        // Handle parentheses, brackets and braces
        else if(c == '(' || c == '[' || c == '{')
        {
            if(c == '(')
                m = ')';
            else if(c == '[')
                m = ']';
            else
                m = '}';
            unbalanced = is_unbalanced(m);
        }
        else
        {
            unbalanced = (c == ')' || c == ']' || c == '}' || c == EOF);
        }
    }
    return unbalanced;
}