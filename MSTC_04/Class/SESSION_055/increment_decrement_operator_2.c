#include <stdio.h>

int main(void)
{
    int num_1;
    int i = 10;

    int num_2;
    int j = 10;

    printf("i = %d\n", i);
    num_1 = ++i;
    printf("i = %d, num_1 =%d\n",i, num_1);

    printf("j = %d\n", j);
    num_2 =j++;
    printf("j = %d, num_2 = %d\n", j, num_2);

    return (0);
}