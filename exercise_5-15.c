/*
Exercise 5-15. Add the option -f to fold upper and lower case together, so that
case distinctions are not made during sorting; for example, a and A compare
equal.
*/
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000       /* max #lines to be sorted */
char *lineptr[MAXLINES];    /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void q_sort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(const char *, const char *);
int (*comp)(void *, void *);
int (*compare)(void *, void *);
int (*order)(void *, void *);
int reverse_compare(void *, void *);
int ignore_case_compare(void *, void *);

/* sort input lines */
int main(int argc, char *argv[])
{
    int nlines;         /* number of input lines read */
    int numeric = 0;    /* 1 if numeric sort */
    int reverse = 0;    /* 1 if reverse sort */
    int fold = 0;       /* 1 if ignore case */
    int c;
    while (--argc > 0 && (*++argv)[0] == '-')
    {
        while (c = *++argv[0])
        {
            switch(c)
            {
            case 'n':
                numeric = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                fold = 1;
                break;
            default:
                printf("sort: illegal option %c\n", c);
                argc = 0;
                break;
            }
        }
    }
    if((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        compare = (int (*)(void *, void*)) (numeric ? numcmp : strcmp);
        order = reverse ? reverse_compare : compare;
        comp = fold ? ignore_case_compare : order;
        q_sort((void **) lineptr, 0, nlines-1, comp);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}

#define MAXLEN 1000     /* max length of any input line */
int get_line(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete new line */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

int get_line(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n;
    } else
        return 0;
}

void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


/* q_sort: sort v[left]...v[right] into increasing order */
void q_sort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)   /* do nothing if array contains */
        return;          /* fewer than two elements */
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
        swap(v, left, last);
        q_sort(v, left, last-1, comp);
        q_sort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

#include <stdlib.h>
/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

int reverse_compare(void *a, void *b)
{
    return compare(b, a);
}

#include "string_utils.c"

int ignore_case_compare(void *a, void *b)
{
    char tmp_a[strlen(a)];
    char tmp_b[strlen(b)];
    return order(str_tolower(a, tmp_a), str_tolower(b, tmp_b));
}
