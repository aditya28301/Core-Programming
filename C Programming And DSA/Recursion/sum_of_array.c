#include <stdio.h>
#include <stdlib.h>

int sum(int*, int, int);

int main(void)
{
    int arr[7]={10,20,30,40,50,60,70};

    printf("SUM OF ARRAY 7 is =%d\n", sum(arr, 7, 0));

    return (0);
}

 int sum(int* arr, int N, int i)
{
    int result;

    if(i == N)
        return 0;

    result = arr[i] + sum(arr, N, i+1);
    return result;
}