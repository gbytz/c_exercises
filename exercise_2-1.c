#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    printf("****** From standard headers ******\n");
    printf("Signed:\n");
    printf("\tSCHAR_MIN: %d\n", SCHAR_MIN);
    printf("\tSCHAR_MAX: %d\n", SCHAR_MAX);
    printf("\tSHRT_MIN: %d\n", SHRT_MIN);
    printf("\tSHRT_MAX: %d\n", SHRT_MAX);
    printf("\tINT_MIN: %d\n", INT_MIN);
    printf("\tINT_MAX: %d\n", INT_MAX);
    printf("\tLONG_MIN: %ld\n", LONG_MIN);
    printf("\tLONG_MAX: %ld\n", LONG_MAX);

    printf("Unsigned:\n");
    printf("\tUCHAR_MAX: %u\n", UCHAR_MAX);
    printf("\tUSHRT_MAX: %u\n", USHRT_MAX);
    printf("\tUINT_MAX: %u\n", UINT_MAX);
    printf("\tULONG_MAX: %lu\n", ULONG_MAX);

    printf("Floating-point:\n");
    printf("\tFLT_MIN: %g\n", FLT_MIN);
    printf("\tFLT_MAX: %g\n", FLT_MAX);
    printf("\tDBL_MIN: %g\n", DBL_MIN);
    printf("\tDBL_MAX: %g\n", DBL_MAX);
    printf("\tLDBL_MIN: %Lg\n", LDBL_MIN);
    printf("\tLDBL_MAX: %Lg\n", LDBL_MAX);

    printf("****** By computation ******\n");
    printf("Signed:\n");
    printf("\tSCHAR_MIN: %hhd\n", -(char)((unsigned char) ~0 >> 1) - 1);
    printf("\tSCHAR_MAX: %d\n", (char)((unsigned char) ~0 >> 1));
    printf("\tSHRT_MIN: %d\n", -(short)((unsigned short) ~0 >> 1) - 1);
    printf("\tSHRT_MAX: %d\n", (short)((unsigned short) ~0 >> 1));
    printf("\tINT_MIN: %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
    printf("\tINT_MAX: %d\n", (int)((unsigned int) ~0 >> 1));
    printf("\tLONG_MIN: %ld\n", -(long)((unsigned long) ~0 >> 1) - 1);
    printf("\tLONG_MAX: %ld\n", (long)((unsigned long) ~0 >> 1));

    printf("Unsigned:\n");
    printf("\tUCHAR_MAX: %hhu\n", ~0U);
    printf("\tUSHRT_MAX: %hu\n", ~0U);
    printf("\tUINT_MAX: %u\n", ~0U);
    printf("\tULONG_MAX: %lu\n", ~0UL);

    return 0;
}