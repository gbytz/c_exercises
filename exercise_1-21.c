/*
Exercise 1-21. Write a program entab that replaces strings of blanks by the
minimum number of tabs and blanks to achieve the same spacing. Use the same tab
stops as for detab. When either a tab or a single blank would suffice to reach a
tab stop, which should be given preference?
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void entab(int tab_stop, char s[], char t[]);

int main()
{
    char line_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];
    while(getline_(line_buffer, BUFFER_SIZE))
    {
        entab(4, line_buffer, dest_buffer);
        printf("%s", dest_buffer);
    }
    return 0;
}

int getline_(char buffer[], int length)
{
    int c, i;
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

void entab(int tab_stop, char s[], char t[])
{
    int i, j;
    for(i = 0, j = 0; s[i] == ' ' || s[i] == '\t'; ++i)
    {
        if(s[i] == ' ')
        {
            j += 1;
        }
        else
        {
            j += tab_stop - (j % tab_stop);
        }
    }

    int k = 0;
    int tabs = j / tab_stop;
    while(tabs > 0)
    {
        t[k++] = '\t';
        --tabs;
    }

    int spaces = j % tab_stop;
    while(spaces > 0)
    {
        t[k++] = ' ';
        --spaces;
    }

    while(s[i] != '\0')
    {
        t[k++] = s[i++];
    }
    t[k] = '\0';
}
