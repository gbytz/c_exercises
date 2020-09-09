/*
Exercise 1-23. Write a program to remove all comments from a C program. Don't
forget to handle quoted strings and character constants properly. C comments do
not nest.
*/
#include <stdio.h>

int main()
{
    int c, d, e, f;
    while((c = getchar()) != EOF)
    {
        if(c == '/')
        {
            d = getchar();
            if(d == '/')
            {
                while((e = getchar()) != '\n')
                    ;
                putchar(e);
            }
            else if(d == '*')
            {
                while((e = getchar()) != '/' || f != '*')
                {
                    f = e;
                }
            }
            else
            {
                putchar(c);
                putchar(d);
            }
        }
        else
        {
            putchar(c);
        }
    }
}
