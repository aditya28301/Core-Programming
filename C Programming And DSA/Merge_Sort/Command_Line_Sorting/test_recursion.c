#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define TEST_MAX 5

void test_sort(int* arr, int size);
void print(int* arr, int p, int r, int count);
void merge(int p, int q, int r);

int main(void){
    int* arr = NULL;
    arr = (int*)malloc(TEST_MAX * sizeof(int));
    assert(arr != NULL);
    for(int i =0 ; i < TEST_MAX; ++i)
        *(arr + i) = (rand() % TEST_MAX);

    test_sort(arr, TEST_MAX);
    free(arr);
    arr = NULL;

    return (0);
}

void test_sort(int* arr, int size){
    printf("size = [%d]\n", size);
    print(arr, 0, size-1, 1         );
}
int count = 0;
void print(int* arr, int p, int r, int count){
    int q = 0;

    if(p < r){
        q = (p + r) /2;
        // printf("BEFORE count = [%d] ,p = [%d], q = [%d], r = [%d]\n", count, p, q, r);
        print(arr, p, q, ++count);
        // printf("BEAFT count = [%d] ,p = [%d], q = [%d], r = [%d]\n", count, p, q, r);
        print(arr, q+1, r, ++count);
        // printf("AFTER count = [%d] ,p = [%d], q = [%d], r = [%d]\n", count, p, q, r);
        merge(p,q,r);
    }
    // printf("RETURN count = [%d] ,p = [%d], q = [%d], r = [%d]\n", count, p, q, r);
}

void merge(int p, int q, int r){
    printf("p = [%d], q = [%d], r = [%d]\n", p, q, r);
}