/*
Exercise 1-16. Revise the main routine of the longest-line program so it will
correctly print the length of arbitrarily long input lines, and as much as
possible of the text.
*/
#include <stdio.h>

#define MAXLINE 1024 /* maximum input line size */

int getline_(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while ((len = getline_(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) {/* there was a line */
        printf("%d\n", max);
        printf("%s", longest);
    }

    return 0;
}

/* getline_: read a line into s, returns length */
int getline_(char s[], int lim)
{
    int c, i, j;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
    {
        if(i < lim-1) {
            s[i] = c;
            j = i;
        }
    }

    if (c == '\n') {
        ++j;
        s[j] = c;
    }
    s[j] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}