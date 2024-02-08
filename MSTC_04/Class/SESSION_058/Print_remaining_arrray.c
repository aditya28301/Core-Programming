#include <stdio.h>
#include <stdlib.h>

void input_array(int a[], int N);
void output_array(int a[], int N, char msg[]);
void print_remaining_array(int a[], int N);

int main(void)
{
    int number_of_element = 8;
    int arr[8];

    input_array(arr, number_of_element);
    output_array(arr, number_of_element,"Initial state of array");
    print_remaining_array(arr, number_of_element);

    return(0);
}

void input_array(int a[], int N)
{
    int i;
    int max_val = 100;

    for(i = 0; i < N; ++i)
        a[i] = rand() % max_val;
}

void output_array(int a[], int N, int msg[])
{
    int i;

    for(i = 0; i < N; ++i)
        printf("a[%d]:%d\n",i, a[i]);
}

void printf_remainign_array(int a[], int N)
{
    int i, j;

    for(i = 0; i < N; ++i)
    {
        printf("Current Element");
        puts("Remaining Array");
        for(j = i + 1; j < N; j++)
        {
            printf("\ta[%d]:%d\n", j, a[j]);
        }
        puts("-----------------------------");
    }
}