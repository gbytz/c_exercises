/*
Exercise 5-13. Write the program tail, which prints the last n lines of its
input. By default, n is 10, let us say, but it can be changed by an optional
argument, so that

    tail -n

prints the last n lines. The program should behave rationally no matter how
unreasonable the input or the value of n. Write the program so it makes the
best use of available storage; lines should be stored as in the sorting program of
Section 5.6, not in a two-dimensional array of fixed size.
*/
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_LINES 10

int parse_parameters(int argc, const char *argv[]);
int read_lines(int max_lines, char *lines[]);
void write_lines(int max_lines, char *lines[], int lines_read);

int main(int argc, char *argv[])
{
    int n = parse_parameters(argc, (const char **) argv);
    if(n < 0)
    {
        printf("Usage: tail -n\n");
        return -1;
    }

    int lines_read;
    char *lines[n];
    for(int i = 0; i < n; ++i)
    {
        lines[i] = NULL;
    }

    if((lines_read = read_lines(n, lines)) > 0)
    {
        write_lines(n, lines, lines_read);
        return 0;
    }

    return -1;
}

int parse_parameters(int argc, const char *argv[])
{
    --argc;
    ++argv;
    if(argc > 0 && (*argv)[0] == '-')
    {
        (*argv)++;
        int n;
        if(isdigit((*argv)[0]) && (n = atoi((*argv))) > 0)
        {
            return n;
        }
        else
        {
            return -1;
        }
    }
    return DEFAULT_LINES;
}

#define BUFFER_SIZE 1024

int get_line(int buffer_size, char *buffer)
{
    char *init_buffer = buffer;
    char c = '\0';
    while(--buffer_size > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *buffer++ = c;
    }

    if(c == '\n')
    {
        *buffer++ = c;
    }

    *buffer = '\0';
    return buffer - init_buffer;
}

int save_line(int length, const char* read_buffer, int line_number, int max_lines, char *lines[])
{
    int index = line_number % max_lines;
    if(lines[index] != NULL)
    {
        free(lines[index]);
    }

    char *line;
    if((line = (char *) malloc(length + 1)) != NULL)
    {
        strcpy(line, read_buffer);
        lines[index] = line;
        return 1;
    }
    return 0;
}

int read_lines(int max_lines, char *lines[])
{
    char read_buffer[BUFFER_SIZE];
    int length = 0;

    int lines_read = 0;
    while((length = get_line(BUFFER_SIZE, read_buffer)) > 0)
    {
        if(!save_line(length, read_buffer, lines_read++, max_lines, lines))
        {
            return -1;
        }
    }
    return lines_read;
}

void write_lines(int max_lines, char *lines[], int lines_read)
{
    int init_line = lines_read - max_lines >= 0 ? lines_read - max_lines : 0;
    for(int i = init_line; i < lines_read && lines[i % max_lines] != NULL; ++i)
    {
        printf("%s", lines[i % max_lines]);
    }
}
