/*
Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers
instead of indexing.
*/

#include <stdio.h>

#define BUFFER_BYTES 16

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    int month;
    int day;

    for (int i = 1988; i <= 1990; i++)
    {
        for (int j = 0; j <= 13; j++)
        {
            for (int k = 0; k <= 31; k++)
            {
                printf("day_of_year(%d, %d, %d) = %d\n", i, j, k, day_of_year(i, j, k));
            }
        }
    }

    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 366; j++)
        {
            month_day(i, j, &month, &day);
            printf("month_day(%d, %d, month, day) = (%d, %d)\n", i, j, month, day);
        }
    }

    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;

    if(year < 1)
    {
        return 0;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    if(month < 1 || month > 12 || day < 1 || day > *(*(daytab + leap) + month))
    {
        return 0;
    }

    for (i = 1; i < month; i++)
        day += *(*(daytab + leap) + i);
    return day;
}

/* month_day: set month, day from day of year */
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    if(year < 1)
    {
        return -1;
    }

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    int days_sum = 0;
    for(i = 1; i <= 12; i++)
    {
        days_sum += *(*(daytab + leap) + i);
    }

    if(yearday < 1 || yearday > days_sum)
    {
        return -1;
    }

    for (i = 1; yearday > *(*(daytab + leap) + i); i++)
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
    return 0;
}
