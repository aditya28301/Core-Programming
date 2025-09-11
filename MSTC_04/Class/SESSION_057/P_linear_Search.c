/*
    @Author: Aditya Ashok Darekar
    Class  : MSTC-04 Session_057
    @Goal : 1. Develope linear search algorith where user will decide the size of array.
            2. While developing algorithm Do not mix i/o operation and computaion in same code.
            3. Search data will decide by user.
*/

#include <stdio.h>

int linear_Search(int [], int , int);
void input_array_Auto(int [], int);
void output_array(int [], int);

int main(void)
{
    int box_arr[100000];    /* Declare array of size 10 */
    int size;  
    int search_data;         
    int position;
    printf("Enter size of array");
    scanf("%d", &size);

    printf("Enter search_data");
    scanf("%d", &search_data);

    printf("Array value Entering ...\n");
    input_array_Auto(box_arr,size);                             /* Array will be input here */

    position = linear_search(box_arr, size, search_data);       /* Linear search algorith is performed here */

    output_array(box_arr,size);                                 /* Array will be output here */ 

    if(!(position < 0))
    {
        printf("positioned is [%d]\n", position); 
        return (0);
    }
    else    
        {
            printf("value are not found\n");
            return(-1);
        }
}   

void output_array(int arr[], int size)
{
    size = size + 1;
    for(int i = 0; i < size; i = i + 1)
    {
        printf("arr[%d] = [%d]\n", i, arr[i]);
    }

}

void input_array_Auto(int arr[], int size)
{
printf("Execute1");
    size = size + 1;
    unsigned int data = 0;
    for(int i = 0; i < size; i = i + 1)
    {
        if(i == 0)
            arr[i] = 0;
        else
        {
            data = data + 1;
            arr[i] = data;
        }
    }
}


int linear_search(int arr[], int size, int search_data)
{
printf("Execute2");
    int i;
    size = size + 1;
    for(i = 0; i < size; i = i + 1)
    {
        if(arr[i] == search_data)
            break;
    }
    
    if(!(i  < size))
        return (-1);
    else    
        return (i+1);
}