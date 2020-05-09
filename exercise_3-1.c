/*
Exercise 3-1. Our binary search makes two tests inside the loop, when one
would suffice (at the price of more tests outside). Write a version with only
one test inside the loop and measure the difference in run-time.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int my_binsearch(int x, int v[], int n);

int main()
{
    int n = 1048576;
    int v[n];
    int i;
    for(i = 0; i < n; ++i)
    {
        v[i] = i;
    }

    srand(time(NULL));
    int x = rand() % n;
    printf("x: %d\n", x);

    clock_t begin, end;

    begin = clock();
    i = binsearch(x, v, n);
    end = clock();

    printf("binsearch time: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
    printf("i: %d\n", i);

    begin = clock();
    i = my_binsearch(x, v, n);
    end = clock();

    printf("my_binsearch time: %lf\n", (double)(end - begin) / CLOCKS_PER_SEC);
    printf("i: %d\n", i);

    return 0;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;  /* no match */
}

int my_binsearch(int x, int v[], int n)
{
    int low, high, mid, i;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while(low < high && v[mid] != x)
    {
        if(x < v[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    return v[mid] == x ? mid : -1 ;
}
