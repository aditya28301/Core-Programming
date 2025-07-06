#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <array>

const int N = 10;
const int row = 5;
const int col = 5;

void _1D_array(int arr[], int size);
void _1D_d_array(int* ptr, int size);
void _1D_r_array(int (&arr)[5], int size);
void _1D_r2_array(std::array<int, N>& arr);
void _2D_array(int arr[][3]);
void _2D_r_array(int (&arr)[3][3]);
void _2D_d_array(int** arr, int row, int col);

int main(void){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int _2d_arr[3][3] = {
        {1,2,3},
        {4,5,6}
    };

    int** _2d_d_arr = new int*[N];
      for(size_t i = 0; i < N; ++i){
        _2d_d_arr[i] = new int[col];
    }

    int* ptr_arr = new int[N];
  
    std::array<int, N> arr_T = {1, 2, 3, 4, 5};

    _1D_array(arr, size);
    _1D_d_array(ptr_arr, N);
    _1D_r_array(arr, size);
    _1D_r2_array(arr_T);
    _2D_array(_2d_arr);
    _2D_r_array(_2d_arr);
    _2D_d_array(_2d_d_arr, row, col);

    delete[] ptr_arr;
    for(size_t i = 0; i < N ; ++i){
        delete[] _2d_d_arr[i];
    }
    delete[] _2d_d_arr;
    std::cout <<"PROGRAMME TERMINATED SUCCESFULLY"
            << std::endl;
    return EXIT_SUCCESS;
}

void _1D_r2_array(std::array<int, N>& arr_t){
    std::cout <<"ONE DIMENSIONAL REFERENCE ARRAY" << std::endl;
    for(size_t i = 0; i < arr_t.size(); ++i){
        std::cout <<"a[" << i << "]" <<
        std::setw(11) <<" =" << arr_t[i] << std::endl; 
    }
}

void _1D_r_array(int (&arr)[5], int size){
     std::cout <<"ONE DIMENSIONAL REFERENCE ARRAY" 
            << std::endl;
    for(size_t i = 0; i <5; ++i){
        std::cout <<"a[" << i << "]" <<
        std::setw(11) <<" =" << arr[i] << std::endl; 
    }
}

void _1D_d_array(int* ptr, int size){
    for(size_t i =0; i < size; ++i){
        *(ptr +i) = i * 10;
    }

    std::cout <<"ONE DIMENSIONAL DYNAMIC ARRAY" << std::endl;
    for(size_t i = 0; i < size; ++i){
        std::cout <<"a[" << i << "]" <<
        std::setw(11) <<" =" << ptr[i] << std::endl; 
    }
}

void _1D_array(int arr[], int size){
     std::cout <<"ONE DIMENSIONAL ARRAY" << std::endl;
    for(size_t i = 0; i < size; ++i){
        std::cout <<"a[" << i << "]" <<
        std::setw(11) <<" =" << arr[i] << std::endl; 
    }
}
////////////////////////////////////////////////////

void _2D_array(int arr[][3]){
    std::cout <<"TWO DIMENSIONAL ARRAY" << std::endl;
    for(size_t i = 0; i < 3; ++i){
        for(size_t j = 0; j < 3; ++j){
            std::cout <<"a[" << i <<"]" <<"[" << j <<"]" 
            <<std::setw(11) <<" =" << arr[i][j] << std::endl; 
        }
    }
}

void _2D_r_array(int (&arr)[3][3]){
    std::cout <<"TWO DIMENSIONAL REFERENCE ARRAY" << std::endl;
     for(size_t i = 0; i < 3; ++i){
        for(size_t j = 0; j < 3; ++j){
            std::cout <<"a[" << i <<"]" <<"[" << j <<"]" 
            <<std::setw(11) <<" =" << arr[i][j] << std::endl; 
        }
    }
}

void _2D_d_array(int** arr, int row, int col){
    std::cout <<"TWO DIMENSIONAL POINTER ARRAY" << std::endl;
    for(size_t i = 0; i < 3; ++i){
        for(size_t j = 0; j < 3; ++j){
            std::cout <<"a[" << i <<"]" <<"[" << j <<"]" 
            <<std::setw(11) <<" =" << arr[i][j] << std::endl; 
        }
    }
}

