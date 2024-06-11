#include <stdio.h>
#include <stdlib.h>

void print(int*, int, int);

int main(void)
{
    int arr[5]={10,20,30,40,50};
    print(arr, 5, 0);
    return (0);
}

void print(int* arr, int N, int i)
{
    if(i == N)
        return;

    printf("arr[%d] = %d\n", i, arr[i]);
    print(arr, N, i+1);
}