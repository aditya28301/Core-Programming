#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[5]={10,20,30,40,50};
    int status;
    status = search_array(arr, 5 , 0, -10);
    if(status >= 0)
        printf("Element found = %d\n", status);
    else
        puts("Element not found");
    return 0;
}

int search_array(int* arr, int n, int i, int k)
{

    if(i == n)
        return -1;

    if(arr[i] == k)
    {
        return arr[i];
    }
   return (search_array(arr, n , i + 1 , k));
}