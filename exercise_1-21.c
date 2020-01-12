/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for detab. When either a tab or a single blank would suffice to reach a
tab stop, which should be given preference?
*/
#include <stdio.h>

#define TAB_STOP 4

int main()
{
    int c, spaces, tabs;
    spaces = tabs = 0;
    while((c = getchar()) != EOF)
    {
        if(c == ' ')
        {
            ++spaces;
            if(spaces % TAB_STOP == 0)
            {
                ++tabs;
                spaces = 0;
            }
        }
        else
        {

            for( ; tabs > 0; --tabs)
                putchar('\t');

            for( ; spaces > 0; --spaces)
                putchar(' ');

            putchar(c);
        }
    }
    return 0;
}