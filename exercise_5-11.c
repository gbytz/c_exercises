/*
Exercise 5-11. Modify the programs entab and detab (written as exercises in
Chapter 1) to accept a list of tab stops as arguments. Use the default tab set-
tings if there are no arguments.
*/
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define DEFAULT_TAB_STOP 4

int atoi(const char *p);
int parse_parameters(int ps_size, const char *ps[], int *tab_stops);
int get_line(int buffer_size, char *buffer);
int get_tabstop(int tab_stops_size, int *tab_stops, int line_number);
char *detab(int tab_stop, const char *read_buffer, char *write_buffer);
char *entab(int tab_stop, const char *read_buffer, char *write_buffer);

int main(int argc, char *argv[])
{
    int tab_stops[argc-1];
    int tab_stops_size = parse_parameters(argc, (const char **)argv, tab_stops);
    char read_buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];
    for(int line_number = 0; get_line(BUFFER_SIZE, read_buffer) > 0; ++line_number)
    {
        int tab_stop = get_tabstop(tab_stops_size, tab_stops, line_number);
        printf("%s", detab(tab_stop, read_buffer, write_buffer));
        //printf("%s", entab(tab_stop, read_buffer, write_buffer));
    }
}

int atoi(const char *p)
{
    while(*p == ' ')
        p++;

    if(*p != '+' && *p != '-' && !isdigit(*p))
    {
        printf("error: invalid parameter\n");
        return 0;
    }

    int sign = *p == '-' ? -1 : 1;
    if(*p == '+' || *p == '-')
        p++;

    int result;
    for(result = 0; isdigit(*p); p++)
    {
        result = 10 * result + (*p - '0');
    }
    return sign * result;
}

int parse_parameters(int ps_size, const char *ps[], int *tab_stops)
{
    int *tab_init = tab_stops;
    while(--ps_size > 0)
    {
        ps++;
        int tab_stop = atoi(*ps);
        if(tab_stop >= 0)
        {
            *tab_stops = tab_stop;
            tab_stops++;
        }
        else
        {
            return 0;
        }
    }
    return tab_stops - tab_init;
}

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

int get_tabstop(int tab_stops_size, int *tab_stops, int line_number)
{
    if(tab_stops_size > 0)
    {
        return tab_stops[line_number % tab_stops_size];
    }
    return DEFAULT_TAB_STOP;
}

char *detab(int tab_stop, const char *in, char *out)
{
    char *init_out = out;
    while(*in != '\0')
    {
        if(*in != '\t')
        {
            *out++ = *in;
        }
        else
        {
            do
            {
                *out++ = ' ';
            }
            while(((out - init_out) % tab_stop) != 0);
        }
        in++;
    }
    *out = '\0';
    return init_out;
}

char *entab(int tab_stop, const char *in, char *out)
{
    int whites = 0;
    while(*in == ' ' || *in == '\t')
    {
        if(*in == ' ')
        {
            whites += 1;
        }
        else
        {
            whites += tab_stop - (whites % tab_stop);
        }
        in++;
    }

    char *init_out = out;
    for(int tabs = whites / tab_stop; tabs-- > 0; out++)
    {
        *out = '\t';
    }

    for(int spaces = whites % tab_stop; spaces-- > 0; out++)
    {
        *out = ' ';
    }

    while(*out++ = *in++)
        ;

    return init_out;
}
