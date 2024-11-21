#include <stdio.h>

int main(void)
{
    int arr[5];
    int i;
    int value;
    i = 0;
    value = 0;
    while(i < 5)
    {
        arr[i] = (i + 1) * 100 + 2;     /* Stored the value for each positioned using variable by creating formulae */

        i = i + 1;          /* Incrementing loop variable value to go to next postioned */
    }

    /* Printing all number which is stored in array positioned */
    
    i = 0;
    while(i < 5)
    {
        printf("Positioned = %d , value = %d , arr[%d] = %d\n", i+1, arr[i], i, arr[i]);

        i = i + 1;
    }

    return (0);
}
        