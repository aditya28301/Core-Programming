#include <stdio.h>

/*
    the following data defination statement will
    Allocate 5 integers contiguesly and each integer
    will have initial value of 0.
    arr[0] == 0
    arr[1] == 0
    arr[2] == 0
    arr[3] == 0
    arr[4] == 0
*/
int arr1[5];

/*
    the following data definition statement will allocated 
    5 integers cintiguoesly and element at each index will be intialized as follows
    arr2[0]     --> 10 
    arr2[1]     --> 20
    arr2[2]     --> 30
    arr2[4]     -->50

*/
int arr2[5] = { 10 , 20 ,30 ,40, 40};

/*
    the follwoing data definition statement will allocate
    4 integers contiguosly and each element will be initalized
    as follows
    arr2[0]     --> 100
    arr2[1]     --> 200
    arr2[2]     --> 300
    arr2[3]     --> 400

*/
int arr3[] = {100, 200, 300, 400};

/*
    the follwing data definition statement isinvalid
    because you must specify the size of array as constant
    or you initialize an array.

not doing both leaves compiler confused about the size of array.

*/
// int arr4[]; /* not allowed */

int main(void)
{

    return (0);
}

