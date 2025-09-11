#include <stdio.h>

#define ARRAY_SIZE 10
typedef unsigned int POSITIVE;      /* typedef statment we use to create alias_name for data type*/

void array_input(POSITIVE[], int);
void output_array(POSITIVE[], int);
int main(void)
{
    int arr[ARRAY_SIZE];

    array_input(arr, ARRAY_SIZE);
    output_array(arr, ARRAY_SIZE);
    return (0);

}

void output_array(POSITIVE arr[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        printf("Arr[%d] = %d \n", i, arr[i]);
    }
}

void array_input(POSITIVE arr[], int size)
{
    int i;
    for(i = 0; i < size; ++i)
    {
        if(i == 0)
        {   
            arr[i] = 1;
            continue;
        }
        arr[i] = i+1;
    }   
}
