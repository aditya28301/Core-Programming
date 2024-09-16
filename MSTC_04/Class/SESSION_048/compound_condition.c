#include <stdio.h>

int mian(void)
{
    int m;
    int n;
    int and_result;
    int or_result;

    printf("Enter m:");
    scanf("%d",&n);

    and_result = (m > 0) && (n > 0);
    or_result = (m > 0) || (n > 0);

    printf("and_result=%d, or_result=%d\n", and_result, or_result);

    return (0);
}