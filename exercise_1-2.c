/*
Exercise 1-2.Experiment to find out what happens when printf's string contains
\c, where c is some character not listed above.
*/
#include <stdio.h>

void main()
{
    printf("hello, world\x21\xA");
}
