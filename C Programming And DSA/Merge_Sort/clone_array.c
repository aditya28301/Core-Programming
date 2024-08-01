#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define TRUE 1

void merge_sort(void);

int main(void){
    merge_sort();
    return (0);
}

 void merge_sort(void){
    int arr[] = {
        100, 20, 0 , 5, 10,
        7, 200, 300, 400, 50,
        60, 70, 800, 73, 4
    };

    int* mArray_1 = NULL;
    int* mArray_2 = NULL;

    int p = 5;
    int q = 8;
    int r = 13;
    int count = 0;

    int size_1 = q - p + 1;
    int size_2 = r - q;

    mArray_1 = (int*)malloc(size_1  * sizeof(int));
    mArray_2 = (int*)malloc(size_2 * sizeof(int));

    printf("Before an sort\n");
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        printf("a[%d] = %d\n", i, arr[i]);

    for(int i = 0; i < size_1; ++i){
        mArray_1[i] = arr[p + i];
        // printf("[%d]\n", mArray_1[i]);
    }

    count = 0;
    for(int i = 0; i < size_2; ++i){
        mArray_2[i] = arr[(q + 1) + i];
        // printf("[%d]\n", mArray_2[i]);
    }

    int i = 0;
    int j = 0;
    int k = 0;
        
    while(TRUE){
        if(mArray_1[i] <= mArray_2[j]){
            arr[p + k] = mArray_1[i];
            ++i;
            ++k;
            if(i == size_1 - 1){
                while(j < size_2 - 1){
                    arr[p + k] = mArray_2[j];
                    ++j;
                    ++k;
                }
                break;
            }
        }
        else{
            arr[p + k] = mArray_2[j];
            ++j;
            ++k;
            if(j == size_2 - 1){
                while(i <  size_1 - 1){
                    arr[p + k] = mArray_1[i];
                    ++i;
                    ++k;
                }
                break;
            }
        }
    }

    printf("after an sort\n");
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        printf("a[%d] = %d\n", i, arr[i]);
}