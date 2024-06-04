/*
    @Author : Aditya Ashok Darekar
    @Date: 11 Apr 2024
    @Goal:
        Problem:
            Sort the os and 1s and 2s array wihtout using sorting algorithm.
            Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
            Input: 
            N = 5
            arr[]= {0 2 1 2 0}
            Output:
            0 0 1 2 2
            Explanation:
            0s 1s and 2s are segregated 
            into ascending order.

*/

#include <stdio.h>
#include <stdlib.h>

void BuildHeap(long long int*, size_t);
long long int* get_array(size_t);
void MaxHeap(size_t, long long int*, size_t);
void print(long long int*, size_t);
void HeapSort(long long int*, size_t);

int main(void)
{
    int size = 5;
    long long int* arr = NULL;

    arr = get_array(size);
    arr[0] = 2;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 2;
    arr[4] = 0;

    HeapSort(arr, size);
    print(arr, size);

    free(arr);
    arr = NULL;

    exit(0);
}
void print(long long int* arr, size_t size)
{
    for(int i = 0; i < size; ++i)
        printf("[%lld]\n", arr[i]);
}
void swap(long long int* f, long long int* s)
{
    long long int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}
size_t left_child(int lc)
{
    return ((2 * lc) + 1);
}
size_t right_child(int rc)
{
    return ((2  * rc) + 2);
}
void HeapSort(long long int* arr, size_t size)
{
    BuildHeap(arr, size);
    int index = size - 1;
    while(index >= 1 )
    {
        swap(&arr[0], &arr[index]);  
        size = size - 1;
        MaxHeap(0, arr, size);
        
        index = index - 1;
    }
}
void MaxHeap(size_t index, long long int* arr, size_t size)
{
    size_t lc;
    size_t rc;
    long long int largest;

    largest = index;
    lc = left_child(index);
    if(lc < size && arr[lc] > arr[largest])
        largest = lc;

    rc = right_child(index);
    if(rc < size && arr[rc] > arr[largest])
        largest = rc;
    if(index != largest)
    {
        swap(&arr[index], &arr[largest]);
        MaxHeap(largest, arr, size);
    }
}
void BuildHeap(long long int* arr, size_t size)
{
    int parent;
    int index;
    index = (size - 2) / 2;
    while(index >= 0)
    {
        MaxHeap(index, arr, size);
        index = index - 1;
    }
}
long long int* get_array(size_t size)
{
    long long int* ptr = NULL;
    ptr = (long long int*)malloc((size) * sizeof(long long int*));
    if(ptr == NULL)
    {   
        puts("Error in allocating the meomary");
        exit(-1);
    }
    return (ptr);
}