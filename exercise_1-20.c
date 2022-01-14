/*
Exercise 1-20. Write a program detab that replaces tabs in the input with the
proper number of blanks to space to the next tab stop. Assume a fixed set of tab
stops, say every n columns. Should n be a variable or a symbolic parameter?
*/
#include <stdio.h>

#define BUFFER_SIZE 1024

int getline_(char buffer[], int length);
void detab(int tab_stop, char s[], char t[]);

int main()
{
    char line_buffer[BUFFER_SIZE];
    char dest_buffer[BUFFER_SIZE];
    while(getline_(line_buffer, BUFFER_SIZE) > 0)
    {
        detab(4, line_buffer, dest_buffer);
        printf("%s", dest_buffer);
    }
    return 0;
}

int getline_(char buffer[], int length)
{
    int c, i;
    for(i = 0; i < length-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        buffer[i] = c;

    if(c == '\n')
    {
        buffer[i] = c;
        ++i;
    }
    buffer[i] = '\0';

    return i;
}

void detab(int tab_stop, char s[], char t[])
{
    int i, j;
    i = j = 0;
    while(s[i] != '\0')
    {
        if(s[i] != '\t')
        {
            t[j] = s[i];
            j++;
        }
        else if(tab_stop > 0)
        {
            do
            {
                t[j] = ' ';
                j++;
            }
            while((j % tab_stop) != 0);
        }
        i++;
    }
    t[j] = '\0';
}
