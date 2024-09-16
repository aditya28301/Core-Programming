#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

void insertion_sort(int n);

int main(void){
    insertion_sort(10);
    std::cout <<"Programme termianted sucessfully";
    return EXIT_SUCCESS;
}

void insertion_sort(int n){  
    int* unsorted_array = 0;
    unsorted_array = new int[10];
    for(int i = 0; i < n; ++i)
        unsorted_array[i] = rand() % 100 + 1;

    int temp = 0;
    for(int i = 0; i < n; ++i){
        temp = unsorted_array[i];
        int j = i - 1;
        while(temp < unsorted_array[j] && j >= 0){
            unsorted_array[j + 1] = unsorted_array[j];
            --j;
        }
        unsorted_array[j + 1] = temp;
    }

    for(int i = 0; i < n; ++i)
        std::cout <<unsorted_array[i] << std::endl;

    delete unsorted_array;
    unsorted_array = 0;
}