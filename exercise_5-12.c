/*
Exercise 5-12. Extend entab and detab to accept the shorthand

    entab -m +n

to mean tab stops every n columns, starting at column m. Choose convenient
(for the user) default behavior.
*/
#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define DEFAULT_TAB_STOP 4
#define DEFAULT_COLUMN 0

int atoi(const char *p);
int parse_parameters(int ps_size, const char *ps[], int *tab_stop, int *column);
int get_line(int buffer_size, char *buffer);
char *detab(int tab_stop, int column, const char *read_buffer, char *write_buffer);
char *entab(int tab_stop, int column, const char *read_buffer, char *write_buffer);

int main(int argc, char *argv[])
{
    int tab_stop;
    int column;
    int success = parse_parameters(argc, (const char **)argv, &tab_stop, &column);
    if(!success)
    {
        printf("Usage: detab +m -n\n");
        return -1;
    }

    char read_buffer[BUFFER_SIZE];
    char write_buffer[BUFFER_SIZE];
    while(get_line(BUFFER_SIZE, read_buffer) > 0)
    {
        printf("%s", detab(tab_stop, column, read_buffer, write_buffer));
        // printf("%s", entab(tab_stop, column, read_buffer, write_buffer));
    }
    return 0;
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

int parse_parameters(int ps_size, const char *ps[], int *tab_stop, int *column)
{
    *tab_stop = DEFAULT_TAB_STOP;
    *column = DEFAULT_COLUMN;
    int i;
    while(--ps_size > 0)
    {
        ++ps;
        if(((*ps)[0] == '-' || (*ps)[0] == '+') && isdigit((*ps)[1]))
        {
            (*ps)++;
            int i = atoi(*ps);
            if((*ps)[-1] == '-')
            {
                *column = i;
            }
            else
            {
                *tab_stop = i;
            }
        }
        else
        {
            printf("error: illegal option \"%s\"\n", *ps);
            return 0;
        }
    }
    return 1;
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

char *detab(int tab_stop, int column, const char *in, char *out)
{
    char *init_out = out;
    while(*in != '\0')
    {
        if(*in != '\t' || ((out - init_out) < column))
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

char *entab(int tab_stop, int column, const char *in, char *out)
{
    char *init_out = out;
    while(out - init_out < column)
    {
        *out++ = *in++;
    }

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
