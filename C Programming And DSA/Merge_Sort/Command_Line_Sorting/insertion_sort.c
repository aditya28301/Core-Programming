#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long int ssize_t;

void populate_array(unsigned int* arr, ssize_t N);
void show_array(unsigned int* arr, ssize_t N, const char* msg);
void sort(unsigned int* arr, ssize_t N);

int main(int argc, char* argv[]     ){
    int* arr = NULL;
    ssize_t N = 0;
    time_t start, end, delta;

    if(argc != 2){
        printf("UsageError:Correct usage:%s number_of_element\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoll(argv[1]);
    if(N <= 0){
        puts("ValueError:size must be positive");
        exit(EXIT_FAILURE);
    }

    arr = (unsigned int*)malloc(N * sizeof(unsigned int));
    if(arr == NULL){
        puts("AllocationError:malloc() Failed");
        exit(EXIT_FAILURE);
    }

    populate_array(arr, N);
    // show_array(arr,N, "Before Sort");
    start = time(0);
    sort(arr, N);
    end = time(0);
    // show_array(arr, N, "After Sort");

    delta = end - start;
    printf("Physical time :insertion sort for size:%lld:Second:%lld\n", N, delta);

    free(arr);
    arr = NULL;

    return (0);
}

void sort(unsigned int* arr, ssize_t N){
    ssize_t i, j;
    unsigned int key;

    for(j = 1 ; j < N; ++j){
        key = arr[j];
        for(i = j -1; i >=0 && arr[i] > key; --i){
            arr[i+1] = arr[i];
        }
        arr[i + 1] = key;
    }


}
void populate_array(unsigned int* arr, ssize_t N){
    ssize_t i;

    srand(time(0));
    for(i = 0; i < N; ++i)
        rand_s(arr + i);
}

void show_array(unsigned int* arr, ssize_t N, const char* msg){
    ssize_t i;

    if(msg)
        puts(msg);

    for(i = 0; i < N; ++i)
        printf("arr[%lld]:%u\n", i, arr[i]);
}
