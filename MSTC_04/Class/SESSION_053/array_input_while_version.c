/*
@Goal
a) Define array of 5 integer.
b) Accept values for the integers in array from the end user on keyboard.
c) Display the input values.
*/

#include <stdio.h>

int main(void)
{
    int a[5];
    int i;

    i = 0;
    while(i < 5)
    {
        printf("Enter the value for integer at index %d:", i);
        scanf("%d", &a[i]);
        i = i + 1;
    }

    i = 0;
    while(i < 5)
    {

        printf("a[%d]:[%d]\n", i, a[i]);
        i = i + 1;
    }
    return (0);
}