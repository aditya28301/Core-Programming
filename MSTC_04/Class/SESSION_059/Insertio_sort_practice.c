#include <stdio.h>
#include <stdlib.h>

void input_array(int [], int);
void output_array(int [], int);
void insertion_sort(int [], int);

int main(void)
{

    int arr[8], size;
    size = 8;

    printf("Auto Number Genearates and inputing array....\n");
    input_array(arr,size);
    printf("Array before the performed insertion sort\n");
    output_array(arr, size);
    printf("array after performed insertion sort\n");
    insertion_sort(arr, size);
    output_array(arr, size);

    return (0);

}

void input_array(int arr[], int size)
{
    int i;
    int max_val = 100;
    for(i = 0; i < size ; ++i)
        arr[i] = rand() % max_val; 
}

void output_array(int arr[], int size)
{
    int i;
    for(i = 0; i < size ; ++i)
    {
        printf("a[%d] = %d\n", i,arr[i]);
    }
}

void insertion_sort(int arr[], int size)
{
    int i;
    int j;  
    int key;

    for(i = 1; i < size; ++i)
    {
        key = arr[i];
        j = i - 1;
        while(j > -1 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j = j -1;
        }
        arr[j+1] = key;
    }
}