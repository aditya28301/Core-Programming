#include <stdio.h>

int main(void)
{
    int i = 10;

    i++;
    printf("i = %d\n", i);

    ++i;
    printf("i = %d\n", i);

    i--;
    printf("i = %d\n", i);

    --i;
    printf("i = %d\n", i);

    return (0);
}