#include <stdio.h>
#include <stdlib.h>

void print_rev(int*, int, int);

int main(void)
{
    int arr[4]={20, 30, 40 ,50};
    print_rev(arr, 4, 0);
    return (0);
}

void print_rev(int* arr, int N, int i)
{
    if(i == N)
        return;

    print_rev(arr, N, i+1);
    printf("arr[%d] = %d\n", i, arr[i]);
}