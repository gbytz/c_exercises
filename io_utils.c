#include <ctype.h>
#include <stdio.h>

void print_parameters(int argc, const char *argv[])
{
    printf("***** PARAMETERS *****\n");
    printf("argc:\t%d\n", argc);
    for(int i = 0; i <= argc; ++i)
    {
        printf("argv[%d]: %s\n", i, argv[i]);
    }
    printf("**********************\n");
}

int get_word(char b[], int b_size)
{
    int c, i;
    i = 0;
    while(--b_size > 0 && (c = getchar()) != EOF && isgraph(c))
    {
        b[i++] = c;
    }
    b[i] = '\0';
    return i;
}

int get_line(char b[], int b_size)
{
    int c, i;
    i = 0;
    while(--b_size > 0 && (c = getchar()) != EOF && c != '\n')
    {
        b[i++] = c;
    }
    if(c == '\n')
    {
        b[i++] = c;
    }
    b[i] = '\0';
    return i;
}
