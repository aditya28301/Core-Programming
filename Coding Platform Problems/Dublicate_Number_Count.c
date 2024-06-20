#include <stdio.h>
#include <stdlib.h>

void dublicate_number(int*, int);

int main(void){

int arr[5]={34, 6, 9, 0 ,0};

dublicate_number(arr, 5);
return (0);
}

void dublicate_number(int* arr, int n){

    int i, j;
    int current_number;
    int count = 0;
    i = 0;
    while(i < n)
    {
        count = 0;
        current_number = arr[i];
        j = 0;
        while(j < i){
            if(current_number == arr[j]){
                break;
            }
            ++j;
        }
         
        if(j == i){
            j = 0;
            while(j < n){
                if(arr[j] == current_number)
                    count += 1;
                ++j;
            }
            printf("number = %d, count = %d\n", current_number, count);
        }
        ++i;
    }
}