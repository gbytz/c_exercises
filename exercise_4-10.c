/*
Exercise 4-10. An alternate organization uses getline to read an entire input
line; this makes getch and ungetch unnecessary. Revise the calculator to use
this approach.
*/
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#include "io_utils.c"

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0'
#define BUFFER_BYTES 1024

int getop(char []);
void push(double);
double pop(void);

char buffer[BUFFER_BYTES];
char buffer_i;


/* reverse Polish calculator */
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while(get_line(buffer, BUFFER_BYTES) > 0)
    {
        buffer_i = 0;
        while((type = getop(s)) != '\0')
        {
            switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+' :
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-' :
                op2 = pop();
                push(pop () - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
            }
        }
    }
    return 0;
}

#define MAXVAL 100      /* maximum depth of val stack */

int sp = 0;             /* next free stack position */
double val[MAXVAL];     /* value stack */

/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = buffer[buffer_i++]) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;       /* not a number */
    i = 0;
    if (isdigit(c))     /* collect integer part */
        while(isdigit(s[++i] = c = buffer[buffer_i++]))
            ;
    if(c == '.')        /* collect fraction part */
        while(isdigit(s[++i] = c = buffer[buffer_i++]))
            ;
    s[i] = '\0';
    buffer_i--;
    return NUMBER;
}
