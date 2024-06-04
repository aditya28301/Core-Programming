#include <stdio.h>
#include <stdlib.h>


void insert(int*, int, int, int);
void print_array(int*, int);
int extract_min(int*, int*);
void min_heapify(int, int*, int*);
void swap(int*, int*);
int left_child(int);
int right_child(int);
int* get_array(int*);

int arr[] = { 7,10,4,3,20,15 };

int main(void)
{

    int k = 3;
    int* arr2 = NULL;
    int size = 6;

    arr2 = get_array(&size);

    int k_th = k;
    for (int i = 0; i < size; ++i)
    {
        insert(arr2, size, arr[i], i);
    }
    while (k--)
    {
        if (k != 0)
            extract_min(arr2, &size);
        else
            printf("kth [%d] smallest element [%d]\n", k_th, extract_min(arr2, &size));
    }
    print_array(arr2, size);
    exit(0);
}
int* get_array(int* size)
{
    int* ptr = NULL;
    ptr = (int*)malloc((*size) * sizeof(int));
    if (ptr == NULL)
        exit(0);
    return (ptr);
}
int left_child(int lc)
{
    return (2 * lc) + 1;
}
int right_child(int rc)
{
    return (2 * rc) + 2;
}
void min_heapify(int index, int* arr2, int* size)
{
    int smallest = index;
    int lc;
    int rc;
    lc = left_child(index);
    if (lc < *size && arr2[lc] < arr2[smallest])
        smallest = lc;
    rc = right_child(index);
    if (rc < *size && arr2[rc] < arr2[smallest])
        smallest = rc;
    if (smallest != index)
    {
        swap(&arr2[index], &arr2[smallest]);
        min_heapify(smallest, arr2, size);
    }
}
int extract_min(int* arr2, int* size)
{

    swap(&arr2[0], &arr2[*size - 1]);
    *size = *size - 1;
    min_heapify(0, arr2, size);
    return (arr2[*size]);
}
void print_array(int* arr2, int size)
{
    for (int i = 0; i < size; ++i)
    {
        printf("%d\n", arr2[i]);
    }
}
void swap(int* f, int* s)
{
    int temp;
    temp = *f;
    *f = *s;
    *s = temp;
}
void insert(int* arr2, int size, int data, int index)
{
    int parent;
    arr2[index] = data;
    while (index != 0)
    {
        parent = (index - 1) / 2;
        if (arr2[parent] > arr2[index])
        {
            swap(&arr2[parent], &arr2[index]);
        }
        index = parent;
    }
}