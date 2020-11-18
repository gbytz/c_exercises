/*
Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
with pointers instead of array indexing. Good possibilities include getline
(Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4),
reverse (Chapter 3), and strindex and getop (Chapter 4).
*/
#include <stdio.h>
#include <ctype.h>

#define BUFFER_BYTES 1024

enum operation
{
    UNKNOWN,
    GET_LINE,
    REMOVE_TRAILING_BLANKS,
    REVERSE,
    DETAB,
    ENTAB,
    FOLD,
    STR_LEN,
    ATOI_2,
    HTOI,
    SQUEEZE_SC,
    STR_CAT,
    SQUEEZE_SS,
    ANY,
    ESCAPE,
    UNESCAPE,
    ATOI_3,
    EXPAND,
    ITOA_NS,
    ITOB,
    ITOA_NSW,
    STRINDEX,
    STRRINDEX,
    EXIT
};

int get_line(char *s, int buffer_size);
char *remove_trailing_blanks(char *s);
char *reverse(char *s);
char *detab(int tab_stop, const char *s, char *t);
char *entab(int tab_stop, const char *s, char *t);
char *fold(int width, const char *s, char *t);
int str_len(const char *s);
int atoi_2(const char *s);
int htoi(const char *s);
char *squeeze_sc(char *s, int c);
char *str_cat(char *s, const char *t);
char *squeeze_ss(char *s, const char *t);
char *any(char *s, const char *t);
char *escape(char *s, const char *t);
char *unescape(char *s, const char *t);
int atoi_3(const char *s);
char *expand(const char *s, char *t);
char *itoa_ns(int n, char *s);
char *itob(int n, char *s, int b);
char *itoa_nsw(int n, char *s, int w);
const char *strindex(const char *s, const char *t);
const char *strrindex(const char *s, const char *t);
enum operation getop(char *s);

int main()
{
    char buffer0[BUFFER_BYTES];
    char buffer1[BUFFER_BYTES];
    char buffer2[BUFFER_BYTES];

    enum operation type;
    while((type = getop(buffer0)) != EXIT)
    {
        switch(type)
        {
            case GET_LINE:
            {
                printf("Test int get_line(char *s, int buffer_size):\n");
                int line_size;
                while((line_size = get_line(buffer1, BUFFER_BYTES)) > 1)
                {
                    printf("Line size: %2d Line: %s\n", line_size, buffer1);
                }
                break;
            }
            case REMOVE_TRAILING_BLANKS:
            {
                printf("Test char *remove_trailing_blanks(char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s", remove_trailing_blanks(buffer1));
                }
                break;
            }
            case REVERSE:
            {
                printf("Test char *reverse(char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s", reverse(buffer1));
                }
                break;
            }
            case DETAB:
            {
                printf("Test char *detab(int tab_stop, const char *s, char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s", detab(4, buffer1, buffer2));
                }
                break;
            }
            case ENTAB:
            {
                printf("Test char *entab(int tab_stop, const char *s, char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s", entab(4, buffer1, buffer2));
                }
                break;
            }
            case FOLD:
            {
                printf("Test char *fold(int width, const char *s, char *t):\n");
                int n;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && sscanf(buffer1, "%d", &n) != EOF
                    && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf("%s", fold(n, buffer2, buffer1));
                }
                break;
            }
            case STR_LEN:
            {
                printf("Test int str_len(const char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%d\n", str_len(buffer1));
                }
                break;
            }
            case ATOI_2:
            {
                printf("Test int atoi_2(const char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%d\n", atoi_2(buffer1));
                }
                break;
            }
            case HTOI:
            {
                printf("Test int htoi(const char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%d\n", htoi(buffer1));
                }
                break;
            }

            case SQUEEZE_SC:
            {   printf("Test char *squeeze_sc(char *s, int c):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("Character to delete: ");
                    printf("%s", squeeze_sc(buffer1, getchar()));
                }
                break;
            }
            case STR_CAT:
            {
                printf("Test char *str_cat(char *s, const char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1 && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf("%s\n", str_cat(buffer1, buffer2));
                }
                break;
            }
            case SQUEEZE_SS:
            {
                printf("Test char *squeeze_ss(char *s, const char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1 && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf("%s\n", squeeze_ss(buffer1, buffer2));
                }
                break;
            }
            case ANY:
            {
                printf("Test char *any(char *s, const char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1 && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf(any(buffer1, buffer2) != NULL ? "found\n" : "not found\n");
                }
                break;
            }
            case ESCAPE:
            {
                printf("Test char *escape(char *s, const char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s\n", escape(buffer2, buffer1));
                }
                break;
            }
            case UNESCAPE:
            {
                printf("Test char *unescape(char *s, const char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s\n", unescape(buffer2, buffer1));
                }
                break;
            }
            case ATOI_3:
            {
                printf("Test int atoi_3(const char *s):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%d\n", atoi_3(buffer1));
                }
                break;
            }
            case EXPAND:
            {
                printf("Test char *expand(const char *s, char *t):\n");
                while(get_line(buffer1, BUFFER_BYTES) > 1)
                {
                    printf("%s", expand(buffer1, buffer2));
                }
                break;
            }
            case ITOA_NS:
            {
                printf("Test char *itoa_ns(int n, char *s):\n");
                int n;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && sscanf(buffer1, "%d", &n) != EOF)
                {
                    printf("%s\n", itoa_ns(n, buffer1));
                }
                break;
            }
            case ITOB:
            {
                printf("Test char *itob(int n, char *s, int b):\n");
                int n, m;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && sscanf(buffer1, "%d", &n) != EOF
                    && get_line(buffer2, BUFFER_BYTES) > 1 && sscanf(buffer2, "%d", &m) != EOF)
                {
                    printf("%s\n", itob(n, buffer1, m));
                }
                break;
            }
            case ITOA_NSW:
            {
                printf("Test char *itoa_nsw(int n, char *s, int w):\n");
                int n, m;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && sscanf(buffer1, "%d", &n) != EOF
                    && get_line(buffer2, BUFFER_BYTES) > 1 && sscanf(buffer2, "%d", &m) != EOF)
                {
                    printf("%s\n", itoa_nsw(n, buffer1, m));
                }
                break;
            }
            case STRINDEX:
            {
                printf("Test const char *strindex(const char *s, const char *t):\n");
                const char *s;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf((s = strindex(buffer1, buffer2)) != NULL ? "%s\n" : "\n", s);
                }
                break;
            }
            case STRRINDEX:
            {
                printf("Test const char *strrindex(const char *s, const char *t):\n");
                const char *s;
                while(get_line(buffer1, BUFFER_BYTES) > 1 && get_line(buffer2, BUFFER_BYTES) > 1)
                {
                    printf((s = strrindex(buffer1, buffer2)) != NULL ? "%s\n" : "\n", s);
                }
                break;
            }
            default:
            {
                printf("error: unknown command %s\n", buffer0);
                break;
            }
        }
    }
    return 0;
}

int get_line(char *s, int buffer_size)
{
    const char *t = s;
    int c;
    while(--buffer_size > 0 && (c = getchar()) != EOF && c != '\n')
    {
        *s++ = c;
    }
    if(c == '\n')
    {
        *s++ = c;
    }
    *s = '\0';
    return s - t;
}

char *remove_trailing_blanks(char *s)
{
    char* t = s;
    int w = 0;
    while(*s != '\0' && *s != '\n')
    {
        if(*s == ' ' || *s == '\t')
        {
            w++;
        }
        else
        {
            w = 0;
        }
        s++;
    }
    s -= w;
    if(s > t)
    {
        *s++ = '\n';
    }
    *s = '\0';
    return t;
}

char *reverse(char *s)
{
    char *t, *u;
    t = u = s;
    while(*s && *s != '\n')
    {
        s++;
    }
    if(*s == '\0' && s > u)
    {
        s--;
    }
    if(*s == '\n' && s > u)
    {
        s--;
    }

    for(char temp = '\0'; s > t; s--, t++)
    {
        temp = *s;
        *s = *t;
        *t = temp;
    }
    return u;
}

char *detab(int tab_stop, const char *s, char *t)
{
    int i = 0;
    while(*s != '\0')
    {
        if(*s != '\t')
        {
            *(t + i) = *s;
            i++;
        }
        else
        {
            do
            {
                *(t + i) = ' ';
                i++;
            }
            while((i % tab_stop) != 0);
        }
        s++;
    }
    *(t + i) = '\0';
    return t;
}

char *entab(int tab_stop, const char *s, char *t)
{
    char *u = t;
    int i;
    for(i = 0; *s == ' ' || *s == '\t'; s++)
    {
        if(*s == ' ')
        {
            i += 1;
        }
        else
        {
            i += tab_stop - (i % tab_stop);
        }
    }

    for(int tabs = i / tab_stop; tabs-- > 0; t++)
    {
        *t = '\t';
    }

    for(int spaces = i % tab_stop; spaces-- > 0; t++)
    {
        *t = ' ';
    }

    while(*t++ = *s++)
        ;

    return u;
}

char *fold(int width, const char *s, char *t)
{
    char *u = t;
    const char *s1 = 0;
    char *t1 = 0;
    int k = 0;
    while(*s)
    {
        if(*s == ' ' && k % width < width - 1)
        {
            s1 = s;
            t1 = t;
        }
        if(*s != '\n' && k % width == width - 1)
        {
            if(s1 != 0 && t1 != 0)
            {
                s = s1 + 1;
                t = t1 + 1;
                s1 = t1 = 0;
            }
            *t = '\n';
        }
        else
        {
            *t = *s;
            s++;
        }
        t++;
        k++;
    }
    *t = '\0';
    return u;
}

int str_len(const char *s)
{
    const char *t = s;
    while(*s)
    {
        s++;
    }
    return s - t;
}

int atoi_2(const char *s)
{
    int n = 0;
    while('0' <= *s && *s <= '9')
    {
        n = 10 * n + (*s++ - '0');
    }
    return n;
}

int htoi(const char *s)
{
    while(isspace(*s))
    {
        s++;
    }

    if(*s == '0')
    {
        s++;
    }

    int lower = tolower(*s);
    if(lower == 'x')
    {
        s++;
    }

    int n, term;
    n = 0;
    while(isxdigit(*s))
    {
        lower = tolower(*s);
        if(isdigit(lower))
        {
            term = lower - '0';
        }
        else
        {
            term  = lower - 'a' + 10;
        }
        n = 16 * n + term;
        s++;
    }
    return n;
}

char *squeeze_sc(char *s, int c)
{
    char *t,  *u;
    u = t = s;
    while(*s)
    {
        if(*s != c)
        {
            *t++ = *s;
        }
        s++;
    }
    *t = '\0';
    return u;
}

char *str_cat(char *s, const char *t)
{
    char *u = s;
    while(*s)
    {
        s++;
    }
    while(*s++ = *t++)
        ;
    return u;
}

char *squeeze_ss(char *s, const char *t)
{
    while(*t)
    {
        char *u, *v;
        u = v = s;
        while(*u)
        {
            if(*u != *t)
            {
                *v++ = *u;
            }
            u++;
        }
        *v = '\0';
        t++;
    }
    return s;
}

char *any(char *s, const char *t)
{
    char *u = NULL;
    while(*t && u == NULL)
    {
        char *v = s;
        while(*v && u == NULL)
        {
            if(*v == *t)
            {
                u = v;
            }
            v++;
        }
        t++;
    }
    return u;
}

char *escape(char *s, const char *t)
{
    char *u = s;
    while(*t)
    {
        switch(*t)
        {
            case '\n':
            {
                *u++ = '\\';
                *u++ = 'n';
                break;
            }
            case '\t':
            {
                *u++ = '\\';
                *u++ = 't';
                break;
            }
            default:
            {
                *u++ = *t;
                break;
            }
        }
        t++;
    }
    u = '\0';
    return s;
}

char *unescape(char *s, const char *t)
{
    char *u = s;
    while(*t)
    {
        if(*t == '\\')
        {
            t++;
            switch(*t)
            {
                case 'n':
                {
                    *u++ = '\n';
                    break;
                }
                case 't':
                {
                    *u++ = '\t';
                    break;
                }
                default:
                {
                    *u++ = *t;
                    break;
                }
            }
        }
        else
        {
            *u++ = *t;
        }
        t++;
    }
    *u = '\0';
    return s;
}

int atoi_3(const char *s)
{
    int n, sign;

    for(; isspace(*s); s++)
        ;
    sign = (*s == '-') ? -1 : 1;
    if(*s == '+' || *s == '-')
        s++;
    for(n = 0; isdigit(*s); s++)
        n = 10 * n + (*s - '0');
    return sign * n;
}

char *expand(const char *s, char *t)
{
    char *u = t;
    for(; *s; s++)
    {
        if(isalnum(*s) && *(s + 1) == '-' && isalnum(*(s + 2)) && *s < *(s + 2))
        {
            char c;
            for(c = *s; c < *(s + 2); ++c)
            {
                *u++ = c;
            }
            s++;
        }
        else
        {
            *u++ = *s;
        }
    }
    *u = '\0';
    return t;
}

char *itoa_ns(int n, char *s)
{
    int sign;
    if((sign = n) < 0)
        n = -n;
    char *u = s;
    do
    {
        *u++ = n % 10 + '0';
    }
    while((n /= 10) > 0);
    if(sign < 0)
        *u++ = '-';
    *u = '\0';
    return reverse(s);
}

char *itob(int n, char *s, int b)
{
    int sign = 1;
    if(n < 0)
    {
        sign = -1;
    }

    char *t = s;
    int i = 0;
    do
    {
        i = n % b * sign;
        if(i < 10)
        {
            *t++ = i + '0';
        }
        else
        {
            *t++ = i % 10 + 'A';
        }
    }
    while((n /= b) != 0);

    if(sign < 0)
    {
        *t++ = '-';
    }
    *t = '\0';
    return reverse(s);
}

char *itoa_nsw(int n, char *s, int w)
{
    int sign = 1;
    if(n < 0)
    {
        sign = -1;
    }

    char *t = s;
    do
    {
        *t++ = n % 10 * sign + '0';
        --w;
    }
    while((n /= 10) != 0);

    if(sign < 0)
    {
        *t++ = '-';
        --w;
    }

    for(int i = 0; i < w; ++i)
    {
        *t++ = ' ';
    }
    *t = '\0';
    return reverse(s);
}

const char *strindex(const char *s, const char *t)
{
    const char *u, *v;
    for(; *s; s++)
    {
        for(u = s, v = t; *v && *u == *v; u++, v++)
            ;
        if(v > t && *v == '\0')
        {
            return s;
        }
    }
    return NULL;
}

const char *strrindex(const char *s, const char *t)
{
    const char *u = s;
    const char *v = t;
    while(*s)
    {
        s++;
    }
    if(s > u)
    {
        s--;
    }
    while(*t)
    {
        t++;
    }
    if(t > v)
    {
        t--;
    }
    for(; s >= u; s--)
    {
        const char *w, *x;
        for(w = s, x = t; w > u && x > v && *w == *x; w--, x--)
            ;
        if(x == v && *w == *x)
        {
            return w;
        }
    }
    return NULL;
}

enum operation getop(char *s)
{
    printf
    (
        "Type the name of the function you want to test and press Enter:\n"
        "\tget_line\n"
        "\tremove_trailing_blanks\n"
        "\treverse\n"
        "\tdetab\n"
        "\tentab\n"
        "\tfold\n"
        "\tstr_len\n"
        "\tatoi_2\n"
        "\thtoi\n"
        "\tsqueeze_sc\n"
        "\tstr_cat\n"
        "\tsqueeze_ss\n"
        "\tany\n"
        "\tescape\n"
        "\tunescape\n"
        "\tatoi_3\n"
        "\texpand\n"
        "\titoa_ns\n"
        "\titob\n"
        "\titoa_nsw\n"
        "\tstrindex\n"
        "\tstrrindex\n"
        "\texit\n"
    );

    char *t = s;
    int c;
    while((*t = c = getchar()) == ' ' || c == '\t')
        ;
    *(++t) = '\0';
    t = s;
    if(isalnum(c))
    {
        while(isalnum(*(++t) = c = getchar()) || c == '_')
            ;
        if(strindex(s, "get_line") != NULL)
        {
            return GET_LINE;
        }
        else if(strindex(s, "remove_trailing_blanks") != NULL)
        {
            return REMOVE_TRAILING_BLANKS;
        }
        else if(strindex(s, "reverse") != NULL)
        {
            return REVERSE;
        }
        else if(strindex(s, "detab") != NULL)
        {
            return DETAB;
        }
        else if(strindex(s, "entab") != NULL)
        {
            return ENTAB;
        }
        else if(strindex(s, "fold") != NULL)
        {
            return FOLD;
        }
        else if(strindex(s, "str_len") != NULL)
        {
            return STR_LEN;
        }
        else if(strindex(s, "atoi_2") != NULL)
        {
            return ATOI_2;
        }
        else if(strindex(s, "htoi") != NULL)
        {
            return HTOI;
        }
        else if(strindex(s, "squeeze_sc") != NULL)
        {
            return SQUEEZE_SC;
        }
        else if(strindex(s, "str_cat") != NULL)
        {
            return STR_CAT;
        }
        else if(strindex(s, "squeeze_ss") != NULL)
        {
            return SQUEEZE_SS;
        }
        else if(strindex(s, "any") != NULL)
        {
            return ANY;
        }
        else if(strindex(s, "escape") != NULL)
        {
            return ESCAPE;
        }
        else if(strindex(s, "unescape") != NULL)
        {
            return UNESCAPE;
        }
        else if(strindex(s, "atoi_3") != NULL)
        {
            return ATOI_3;
        }
        else if(strindex(s, "expand") != NULL)
        {
            return EXPAND;
        }
        else if(strindex(s, "itoa_ns") != NULL)
        {
            return ITOA_NS;
        }
        else if(strindex(s, "itob") != NULL)
        {
            return ITOB;
        }
        else if(strindex(s, "itoa_nsw") != NULL)
        {
            return ITOA_NSW;
        }
        else if(strindex(s, "strindex") != NULL)
        {
            return STRINDEX;
        }
        else if(strindex(s, "strrindex") != NULL)
        {
            return STRRINDEX;
        }
        else if(strindex(s, "exit") != NULL)
        {
            return EXIT;
        }
    }
    return UNKNOWN;
}
