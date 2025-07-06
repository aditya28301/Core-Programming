#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

const int TEST_MAX = 10;

void insertion_sort(size_t* arr, size_t size);
void swap(size_t* start, size_t* end);
void show(size_t* arr, size_t size);

int main(void){
    srand(time(0));
    size_t* arr = new size_t[TEST_MAX];
    for(size_t i = 0; i < TEST_MAX; ++i)
        arr[i] = rand() % 1000 + 1;
    std::cout <<"Array before sort" << std::endl;
    show(arr, TEST_MAX);
    insertion_sort(arr, TEST_MAX);
    std::cout <<"Array after sort" << std::endl;
    show(arr, TEST_MAX);
    std::cout <<"Program termianted sucesfully";
    return EXIT_SUCCESS;
}

void show(size_t* arr, size_t size){
    for(size_t i = 0; i < size; ++i){
        std::cout <<"a[" <<i <<"]" <<"= " << arr[i] << std::endl;
    }
}

void swap(size_t* start, size_t* end){
    size_t temp = 0;
    temp = *start;
    *start = *end;
    *end = temp;
}

void insertion_sort(size_t* arr, size_t size){
    for(size_t i = 0; i < size; ++i){
        size_t current = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > current){
            arr[j+1] = arr[j];
            --j;
        }       
        arr[j+1] = current;
    }
}