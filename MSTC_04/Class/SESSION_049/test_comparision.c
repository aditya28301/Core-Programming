#include <stdio.h>
int main(void)
{
    int a,b;

    printf("Enter first number");
    scanf("%d", &a);

    printf("Enter a second number");
    scanf("%d", &b);

    if(a >=b)
    {
        puts("a is greater than or equal to b");
    }

    if(!(a < b))                                                                    
    {
        puts("not(a is less than b)");
    }
/*                                      */
    if(a < b)
    {
        puts("a is less than b");
    }

    if(!(a >= b))
    {
        puts("not(a is greater or equal to b");
    }
/*                                        */
    if(a > b)
    {
        puts("a is greater than b");
    }

    if(!(a <= b))
    {
        puts("not(a is less than or equal to b");
    }
/*                                         */
    if(a <= b)
    {
        puts("a is less than or equal to b");
    }

    if(!(a > b))
    {
        puts("not(a is greater than b)");
    }
/*                                          */
    if(a==b)
    {
        puts("a is equal to b");
    }

    if(!(a==b))
    {
        puts("not(a is equal to b");
    }
/*                                          */
    if(a != b)
    {
        puts("not(a is not equal to b");
    }

    if(a == b)
    {
        puts("a is equal to b");
    }

    return (0);
}