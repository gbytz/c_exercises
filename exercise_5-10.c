/*
Exercise 5-10. Write the program expr, which evaluates a reverse Polish
expression from the command line, where each operator or operand is a separate
argument. For example,

    expr 2 3 4 + *

evaluates 2 * (3 + 4).
*/
#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 64

enum paramType
{
    INVALID,
    OPERATOR,
    OPERAND
};

void push(int operand);
int pop(void);
enum paramType get_op(const char *p, char *operator, int *operand);


int main(int argc, char *argv[])
{
    char operator = 0;
    int operand = 0;
    enum paramType type = INVALID;
    while(--argc > 0)
    {
        type = get_op(*++argv, &operator, &operand);
        switch(type)
        {
            case OPERAND:
                push(operand);
                break;
            case OPERATOR:
                switch(operator)
                {
                    case '+':
                        push(pop() + pop());
                    break;
                    case '-':
                        operand = pop();
                        push(pop() - operand);
                    break;
                    case '*':
                        push(pop() * pop());
                    break;
                    case '/':
                        operand = pop();
                        if(operand != 0)
                            push(pop() / operand);
                        else
                            printf("error: division by zero\n");
                    break;
                }
                break;
            case INVALID:
                printf("error: invalid operator or operand\n");
                break;
        }
    }
    int result = pop();
    printf("%d\n", result);
    return result;
}

int stack[STACK_SIZE];
int *stackp = stack;

void push(int operand)
{
    if(stackp < stack + STACK_SIZE)
        *stackp++ = operand;
    else
        printf("error: stack overflow\n");
}

int pop(void)
{
    if(stackp > stack)
        return *--stackp;
    else
        printf("error: stack is empty\n");
}

int is_operator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

enum paramType get_op(const char *p, char *operator, int *operand)
{
    while(*p == ' ')
        p++;

    if(!isdigit(*p) && !is_operator(*p))
    {
        return INVALID;
    }

    if(is_operator(*p))
    {
        *operator = *p++;
        if(*p != '\0')
            return INVALID;
        else
            return OPERATOR;
    }

    for(*operand = 0; isdigit(*p); p++)
        *operand = 10 * *operand + *p - '0';
    return OPERAND;
}
