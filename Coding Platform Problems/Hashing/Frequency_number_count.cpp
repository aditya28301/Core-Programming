#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

const int TEST_MAX = 10000000000000000000;
typedef unsigned long long int data_t;  

data_t* randome_array(data_t size);
void frequency_count(data_t* arr, data_t size);
void show(data_t* arr, data_t size);

int main(void){
    srand(time(0));
    data_t size = 0;
    data_t* arr = 0;
    size = rand() % TEST_MAX + 1;
    arr = randome_array(size);
    //show(arr, size);
    frequency_count(arr, size);
    std::cout <<"size = " << size << std::endl;
    delete[] arr;
    arr = 0;
    std::cout <<"Program terminated sucessfully" << std::endl;
    return 0;
}
void show(data_t* arr, data_t size){
    for(size_t i = 0; i < size; ++i){
        std::cout <<"[" << arr[i] <<"]->";
    }
    std::cout << std::endl;
}
data_t* randome_array(data_t size){
    // srand(time(0));
    data_t* array = new data_t[size];
    for(size_t i = 0; i < size; ++i){
        array[i] = rand() % TEST_MAX + 1;
    }
    return array;
}   

void frequency_count(data_t* arr, data_t size){
    data_t current_num = 0;
    data_t cnt = 0; 
    size_t i;
    size_t j;
    for(i = 0; i < size; ++i){
        cnt = 0;
        current_num = arr[i];
        for(j = 0; j < i ; ++j){
            if(arr[j] == current_num)
                break;
        }
        if(i == j){
            for(size_t j = 0; j < size; ++j){
                if(arr[j] == current_num){
                    cnt+= 1;
                }
            }
            std::cout <<"value = " << arr[i] <<" count = " << cnt << std::endl;
        }
    }
}

/*  10  2   3   10  1   */
