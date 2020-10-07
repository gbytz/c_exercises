/*
Exercise 4-2. Extend atof to handle scientific notation of the form 123.45e-6
where a floating-point number may be followed by e or E and an optionally signed
exponent.
*/
#include <ctype.h>
#include "io_utils.c"

#define BUFFER_SIZE 64

double atof(char s[]);

int main()
{
    char buffer[BUFFER_SIZE];
    while(get_word(buffer, BUFFER_SIZE))
    {
        printf("%e\n", atof(buffer));
    }
    return 0;
}

double atof(char s[])
{
    double result, val, power, e_power;
    int i, sign, e_sign, e_val;

    for(i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.')
    {
        i++;
    }
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    result = (sign * val / power);

    if(s[i] == 'e' || s[i] == 'E')
        i++;
    e_sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(e_val = 0; isdigit(s[i]); i++)
    {
        e_val = 10 * e_val + (s[i] - '0');
    }
    for(e_power = 1.0 ; e_val > 0; e_val--)
    {
        e_power *= 10.0;
    }

    return e_sign > 0 ? result * e_power : result / e_power;
}
