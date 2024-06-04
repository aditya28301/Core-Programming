/*
    Author: Aditya Ashok Darekar
    Goal  : 
          Problem statement:
          Maximum and minimum of an array using minimum number of comparisons.
          Given an array of size N. 
          The task is to find the maximum and the minimum element of the array using the minimum number of comparisons.

            Input: arr[] = {3, 5, 4, 1, 9}
            Output: Minimum element is: 1
            Maximum element is: 9

            Input: arr[] = {22, 14, 8, 17, 35, 3}
            Output:  Minimum element is: 3
            Maximum element is: 35
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int int_max_cal(void);
int int_min_cal(void);
int* allocate_meomary(int*);
void cal_min_max(int*, int, int*, int*);
void release_mem(int*);
void auto_add(int*, int);
void show_array(int*, int);

int main(void)
{
    int* address = NULL;
    int size;
    int max;
    int min;
    int i;

    /* Getting the maximun and minumum value for integer which 4 byte*/
    min = int_max_cal();    /* Generating max value but assigining to the min var*/
    max = int_min_cal();    /* Generating min value and assigning to max var*/

    /* Allocating the meomary dynamically */
    address = allocate_meomary(&size);

    /* Auto Generate the value and add into the dynamically created array */
    auto_add(address, size);
    
    /* printing array value */
    show_array(address, size);

    /* calculate minimum and maximum number*/
    cal_min_max(address, size, &min, &max);

    /* printing maximum and minimum value */
    printf("Minumum value in a entire array is = [%d]\n", min);
    printf("Maximum value in a entire array is = [%d]\n", max);

    /* Releasing meomary which allocated dynamically*/
    release_mem(address);

    exit(0);
}

int int_max_cal()
{
    int max;

    max = pow(2,8 * sizeof(int));
    max = max - 1;

    return max;
}

int int_min_cal()
{
    int min;

    min = (8 * sizeof(int));
    min = 1 << (min - 1);
    min = min + 1;

    return min;
}

int* allocate_meomary(int* ptr_size)
{
    int size;
    size = 10000;
    *ptr_size = size;
    int* address = NULL;

   address = (int*)malloc(size * sizeof(int));
    if(address == NULL)
    {
        puts("Error in allocating the meomary");
        exit(-1);
    }

    /* Returning address of dynamically created meomary */
    return (address);
}

void cal_min_max(int* address, int size, int* ptr_min, int* ptr_max)
{
    int i;
    i = 0;
    while(i < size)
    {
        if(address[i] < *ptr_min)
        {
            *ptr_min = address[i];
        }
        if(address[i] > *ptr_max)
        {
            *ptr_max = address[i];
        }

        i = i + 1;
    }
}

void release_mem(int* address)
{
    free(address);
    address = NULL;
}

void auto_add(int* address, int size)
{
    int i;
    int data;
    i = 0;
    while(i < size)
    {
        data = rand() % 1000;
        address[i] = data;

        i = i + 1;
    }
}

void show_array(int* address, int size)
{
    int i;
    i = 0; 
    while(i < size)
    {
        printf("value at index[%d] = [%d]\n", i, address[i]);
        i = i + 1;
    }
}