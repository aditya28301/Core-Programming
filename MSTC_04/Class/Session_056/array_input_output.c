#include <stdio.h>

void output_array(int a[], int N);
void input_array(int a[], int N, char msg[]);

void main(void)
{
    int arr[5] = {10, 20, 30, 40, 50};

    output_array(arr, 5, "initial state of array:");
    input_array(arr, 5);
    output_array(arr, 5 ,"Array after input from end user:");

    return (0);
}

void input_array(int a[], int N)
{
    int i;

    i = 0;
    while(i < N)
    {
        printf("Enter an value for element at index %d", i);
        scanf("%d", &a[i]);
        i = i  + 1;
    }
}

void output_array(int a[], int N, char msg[])
{
    int i;

    puts(msg);

    i = 0;
    while(i < N)
    {
        printf("a[%d]:[%d]\n", i, a[i]);
        i = i  + 1;
    }
}
