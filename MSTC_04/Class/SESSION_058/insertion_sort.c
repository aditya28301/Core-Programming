#include <stdio.h>
#include <stdlib.h>

void input_array(int a[], int N);
void output_array(int a[], int N, char msg[]);
void sort_array(int a[], int N);

int main(void)
{
    int number_of_elements = 8;
    int arr[8];

    input_array(arr, number_of_elements);
    output_array(arr, number_of_elements, "Before Sort:");
    sort_array(arr, number_of_elements);
    output_array(arr, number_of_elements, "After Sort:");

    return (0);
}

void input_array(int a[], int N)
{
    int i;
    int max_val = 100;

    for(i = 0; i < N; i++)
        a[i] = rand() % max_val;
}

void output_array(int a[], int N, char msg[])
{
    int i;

    puts(msg);
    for(i = 0; i < N; ++i)
        printf("a[%d]:%d\n", i, a[i]);
}

void sort_array(int a[], int N)
{
    int i;
    int j;
    int key;

    for(j = 1; j < N; ++j)
    {
        key = a[j];
        i = j - 1;
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i];
            i = i - 1;  
        }
        a[i+1] = key;
    }
}