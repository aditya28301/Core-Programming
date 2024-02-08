#include <stdio.h>

void input_array(int a[] , int N);
void output_array(int a[], int N, char msg[]);
int linear_search(int a[], int N, int search_data);

int main(void)
{
    int N = 8;  /* size of array 8 of integer */
    int arr[8]; /*arr is  array of 8 integers   */

    int search_data;    /* sotres the value to be searched withtin array    */
    int index;  /* cartches the output value of linear_Seach() algorithm */

    input_array(arr , N);   /* Take array value input from the end user */
    output_array(arr, N, "Array after inputing values from end user");
    printf("Enter data to be searched withitn the array:");
    scanf("%d", &search_data);
    index = linear_search(arr, N, search_data);
    if(index >= 0)
        printf("%d is found in array for the first time at index %d", search_data, index);
    else if(index  == -1)
        printf("%d is not found in array\n", search_data);

    return (0);
}

void input_array(int a[], int N)
{
    int i;

    for(i = 0; i < N; i++)
    {
        printf("Enter value for element at index %d:", i);
        scanf("%d", &a[i]);
    }
}

void output_array(int a[], int N, char msg[])
{
    int i; 

    puts(msg);
    for(i = 0;i < N ; i++)
        printf("a[%d]:%d\n", i, a[i]);
}

int linear_search(int a[], int N, int search_data)
{
    int i;
    for(i = 0; i < N; ++i)
    {
        if(a[i] == search_data)
            break;

    }
        if(i < N)   
            return (i);
        else if(i == N)
            return (-1); 
} 
