/*
Exercise 4-5. Add access to library functions like sin, exp, and pow. See
<math.h> in Appendix B, Section 4.
*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h> /* for atof() */

#include "string_utils.c"

#define MAXOP 100 /* max size of operand or operator */
#define UNKNOWN '0'
#define NUMBER '1' /* signal that a number was found */
#define SIN '2'
#define EXP '3'
#define POW '4'

int getop(char []);
void push(double);
double pop(void);
void clear(void);

/* reverse Polish calculator */
int main()
{
    int type;
    double op1, op2;
    char s[MAXOP];
    while ((type = getop(s)) != EOF)
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
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            op1 = pop();
            printf("\t%.8g\n", op1);
            push(op1);
            break;
        case 'd':
            op1 = pop();
            push(op1);
            push(op1);
            break;
        case 's':
            op2 = pop();
            op1 = pop();
            push(op2);
            push(op1);
            break;
        case 'c':
            clear();
            break;
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            op1 = pop();
            if(op1 == 0.0 && op2 <= 0 || op1 < 0.0 && ceil(op2) != op2)
                printf("pow: invalid operands\n");
            else
                push(pow(op1, op2));
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
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

void clear(void)
{
    sp = 0;
    val[sp++] = 0.0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isalnum(c) && c != '.' && c != '-')
        return c;       /* not a number */

    i = 0;
    if(isalpha(c))
    {
        while(isalpha(s[++i] = c = getch()))
            ;
        s[i] = '\0';

        if(c != EOF)
        {
            ungetch(c);
        }

        if(i == 1)
        {
            return s[0];
        }
        else if(are_equal(s, "sin"))
        {
            return SIN;
        }
        else if(are_equal(s, "exp"))
        {
            return EXP;
        }
        else if(are_equal(s, "pow"))
        {
            return POW;
        }
        else
        {
            return UNKNOWN;
        }
    }

    if(c == '-' && !isdigit(s[++i] = c = getch()))
    {
        ungetch(c);
        return '-';
    }
    if (isdigit(c))     /* collect integer part */
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')        /* collect fraction part */
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


#define BUFSIZE 100

char buf[BUFSIZE];  /*buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
