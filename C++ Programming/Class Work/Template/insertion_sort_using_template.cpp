#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T> void insertion_sort(T* ptr, int n);

int main(void){
    float f_unsorted_array [] = {9.8, 7.1, 1.1, 3.1};
    int f_size = 0;
    f_size = sizeof(f_unsorted_array) / sizeof(float);

    int unsorted_array [] = {100,99,88, 1, 2, 3};
    int i_size = 0;
    i_size = sizeof(unsorted_array) / sizeof(int);

    std::cout <<"insertion sort of integer" << std::endl;
    insertion_sort<int>(&unsorted_array[0], i_size);
    std::cout <<"insertion sort of float" << std::endl;
    insertion_sort<float>(&f_unsorted_array[0], f_size);

    std::cout <<"Programme termianted sucessfully";
    return EXIT_SUCCESS;
}

template <typename T> void insertion_sort(T* ptr, int n){  


    T temp = 0;
    for(int i = 0; i < n; ++i){
        temp = ptr[i];
        int j = i - 1;
        while(temp < ptr[j] && j >= 0){
            ptr[j + 1] = ptr[j];
            --j;
        }
        ptr[j + 1] = temp;
    }

    for(int i = 0; i < n; ++i)
        std::cout <<ptr[i] << std::endl;
}