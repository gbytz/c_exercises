/*
Exercise 4-14. Define a macro swap(t,x,y) that interchanges two argument of
type t. (Block structure will help.)
*/
#include <stdio.h>

#define swap(t, x, y) { t var = x; x = y; y = var; }

int main()
{
    unsigned char a = 1;
    unsigned char b = 2;
    unsigned int c = 3;
    unsigned int d = 4;
    unsigned long e = 5;
    unsigned long f = 6;
    signed char g = 7;
    signed char h = 8;
    signed int i = 9;
    signed int j = 10;
    signed long k = 11;
    signed long l = 12;
    float m = 13;
    float n = 14;
    double o = 15;
    double p = 16;

    printf("Before swap(t, x, y)\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %lu\n", e);
    printf("f: %lu\n", f);
    printf("g: %d\n", g);
    printf("h: %d\n", h);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("k: %ld\n", k);
    printf("l: %ld\n", l);
    printf("m: %g\n", m);
    printf("n: %g\n", n);
    printf("o: %g\n", o);
    printf("p: %g\n", p);

    swap(unsigned char, a, b);
    swap(unsigned int, c, d);
    swap(unsigned long, e, f);
    swap(signed char, g, h);
    swap(signed int, i, j);
    swap(signed long, k, l);
    swap(float, m, n);
    swap(double, o, p);

    printf("After swap(t, x, y)\n");
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %lu\n", e);
    printf("f: %lu\n", f);
    printf("g: %d\n", g);
    printf("h: %d\n", h);
    printf("i: %d\n", i);
    printf("j: %d\n", j);
    printf("k: %ld\n", k);
    printf("l: %ld\n", l);
    printf("m: %g\n", m);
    printf("n: %g\n", n);
    printf("o: %g\n", o);
    printf("p: %g\n", p);

    return 0;
}
