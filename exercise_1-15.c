/*
Exercise 1-15. Rewrite the temperature conversion program of Section 1.2 to
use a function for conversion.
*/
#include <stdio.h>

#define LOWER 0     /* lower limit of table */
#define UPPER 300   /* upper limit of table */
#define STEP 20     /* step size */


float to_celsius(int fahr);

int main()
{
    int fahr;

    for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3.0d %6.1f\n", fahr, to_celsius(fahr));

    return 0;
}

float to_celsius(int fahr)
{
    return (5.0/9.0) * (fahr-32.0);
}