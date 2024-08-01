#define _CRT_RAND_S
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1

typedef long long int ssize_t;

void populate_array(unsigned int* arr, ssize_t N);
void show_array(unsigned int* arr, ssize_t N, const char* msg);
void sort(unsigned int* arr, ssize_t N);
void merge(unsigned int* arr, ssize_t p, ssize_t q, ssize_t r);
void merge_sort(unsigned int* a, ssize_t p, ssize_t r);

int main(int argc, char* argv[]){
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
    printf("Second:%lld\n", delta);

    free(arr);
    arr = NULL;

    return (0);
}

void sort(unsigned int* arr, ssize_t N){
    merge_sort(arr, 0, N-1);
}
void merge_sort(unsigned int* a, ssize_t p, ssize_t r){
    ssize_t q;

    if(p < r){
        q = (p + r)/2;
        merge_sort(a, p, q);
        merge_sort(a, q+1, r);
        printf("P = [%lld] , q = [%lld], r = [%lld]\n", p, q, r);
        merge(a, p, q, r);
    }
}
void merge(unsigned int* arr, ssize_t p, ssize_t q, ssize_t r){
    unsigned int* a1 = NULL;
    unsigned int* a2 = NULL;    
    ssize_t N1, N2;
    ssize_t i, j, k;

    N1 = q - p + 1;
    N2 = r - q;

    a1 = (unsigned int*)malloc(N1 * sizeof(unsigned int));
    if(a1 == NULL){
        puts("AllocationError:malloc() failed");
        exit(EXIT_FAILURE);
    }

    a2 = (unsigned int*)malloc(N2 * sizeof(int));
    if(a2 == NULL){
        puts("AllocationError:malloc() failed");
        exit(EXIT_FAILURE);
    }

    for(i = 0; i < N1; ++i)
        a1[i] = arr[p + i];

    for(i = 0; i < N2; ++i)
        a2[i] = arr[q + 1 + i];

    i = 0;
    j = 0;
    k = 0;

    while(TRUE){
        if(a1[i] <= a2[j]){
            arr[p + k] = a1[i];
            k = k + 1;
            i = i + 1;
            if(i == N1){
                while(j < N2){
                    arr[p +k] = a2[j];
                    j = j + 1;
                    k = k + 1;
                }
                break;
            }
        }
        else{
            arr[p + k] = a2[j];
            j = j + 1;  
            k = k + 1;
            if(j == N2){
                while(i < N1){
                    arr[p + k] = a1[i];
                    i = i + 1;
                    k = k + 1;
                }
                break;
            }        
        }
    }

    free(a1);   
    a1 = NULL;

    free(a2);
    a2 = NULL;
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
