#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

const int TEST_MAX = 10;

void selection_sort(size_t* arr, size_t size);
void swap(size_t* start, size_t* end);
void show(size_t* arr, size_t size);

int main(void){
    srand(time(0));
    size_t* arr = new size_t[TEST_MAX];
    for(size_t i = 0; i < TEST_MAX; ++i)
        arr[i] = rand() % 1000 + 1;
    std::cout <<"Array before sort" << std::endl;
    show(arr, TEST_MAX);
    selection_sort(arr, TEST_MAX);
    std::cout <<"Array after sort" << std::endl;
    show(arr, TEST_MAX);
    std::cout <<"Program termianted sucesfully" << std::endl;
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

void selection_sort(size_t* arr, size_t size){
    size_t min = 0;
    for(size_t i = 0; i < size - 1; ++i){   
        min = i;
        for(size_t j = i; j < size; ++j){
            if(arr[j] < arr[min])
                min = j;
        }
        swap(&arr[i] , &arr[min]);
    }
}