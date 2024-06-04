/*
    Author: Aditya Ashok Darekar

    Problem statement : Array Reverse in C
    Array reverse or reverse a array means changing the position of each number of the given array to its opposite position from end, 
    i.e. if a number is at position 1 then its new position will be Array.
    length, similarly if a number is at position 2 then its new position will be Array.length – 1, and so on.

    Input: original_array[] = {1, 2, 3} 
    Output: array_reversed[] = {3, 2, 1}

    Date :  2 April 2024
*/

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int Uint;

Uint* memAlloc_arrayInput(Uint);
void arrayInput(Uint*, Uint);
void reverseArray(Uint*, Uint);
void printArray(Uint*, Uint);

int main(void)
{
    Uint size;
    Uint* dArray = NULL;
    /* Getting size of the array from the user */
    printf("Enter the size of the array\n");
    scanf("%u", &size);

    /* Allocating the meomary at runtime and getting the array input*/
    dArray = memAlloc_arrayInput(size);

    printf("\n");
    /* Before reversing the array */
    puts("Array before the reversing");
    printArray(dArray, size);

    /* Reverse array integer Algorithm */
    reverseArray(dArray, size);

    printf("\n");
    /* After reversing the array */
    puts("Array after reversing");
    printArray(dArray, size);

    /* Return with scuessfull execution status with return code - 0*/
    return (0);
}

Uint* memAlloc_arrayInput(Uint size)
{
    Uint* ptr = NULL;

    /* Allocating the meomary at runtime execution - Dynamic meomary allocation */
    ptr = (Uint*)malloc(size * sizeof(Uint));
    
    /* Verifying the meomary is sucessfully allocated or not*/
    if(ptr == NULL)
    {
        puts("Error in allocating the meomary");
        exit(-1);
    }

    /* Getting the input and stored data in allocated block */
    arrayInput(ptr, size);

    /* Returning the address of meomary that allocated to store array input*/
    return (ptr);
}

void arrayInput(Uint* add, Uint size)
{
    int i=0;

    while(i < size)
    {
        *(add + i) = rand() % 100;
        i = i + 1;
    }
}

void reverseArray(Uint* add, Uint size)
{
    Uint i;
    Uint j;
    Uint temp;
    i = 0;
    j = size - 1;
    temp = 0;
    while(i < j)
    {
        temp = add[i];
        add[i] = add[j];
        add[j] = temp;
        i = i + 1;
        j = j -1;
    }
}

void printArray(Uint* add, Uint size)
{
    int i;
    for(i = 0; i < size; ++i)
        printf("value at index:[%d] = %d\n", i, *(add + i));
}