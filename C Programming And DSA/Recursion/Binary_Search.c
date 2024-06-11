#include <stdio.h>
#include <stdlib.h>

int binSearch(int* arr, int, int, int, int);

int main(void)
{
    int arr[5]={10,20,30,40,50};
    int s_index = 0;
    int e_index = 5-1;
    for(int i = 0; i < 51; ++i){
        if(binSearch(arr, 5, s_index, e_index, i) != -1)
            printf("element found [%d]\n", i);
        else 
            printf("element not found [%d]\n",i);
    }
    return 0;
}

int binSearch(int* arr, int n, int s, int e, int t)
{
    int m;
    if(s <= e){
        m = (s+e)/2;
        if(arr[m] == t)
            return 1;
        else if(arr[m] < t)
            return (binSearch(arr, n, s+1, e, t));
        else
            return (binSearch(arr, n, s, e-1,t));
    }
    else
    {
        return -1;
    }
}