/*
Exercise 1-6. Verify that the expression getchar() != EOF is 0 or 1.
*/
#include <stdio.h>

void main()
{
    printf("%d\n", getchar() != EOF);
}
