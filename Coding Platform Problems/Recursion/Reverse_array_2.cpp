#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>

typedef unsigned long long int data_t;
typedef data_t range_t;
typedef range_t size_t;

void reverse_array(data_t* arr, size_t N, data_t l);
void swap(data_t* n1, data_t* n2);

int main(void){
    data_t N = 0;
    srand(time(0));
    N = rand() % 100 + 1;
    data_t* arr = new data_t[N];

    for(range_t i = 0; i < N; ++i)
        arr[i] = rand() % 1000 + 1;

    std::cout <<"Before reverse array is" << std::endl;
    for(size_t i = 0; i < N; ++i)
        std::cout <<"arr" <<"[" << i <<"]" << arr[i] << std::endl;

    reverse_array(arr, N, 0);

    std::cout << std::endl <<"After reverse array is" << std::endl;
    for(size_t i = 0; i < N; ++i)
        std::cout <<"arr" <<"[" << i <<"]" << arr[i] << std::endl;
    std::cout <<"Programme terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}
void swap(data_t* n1, data_t* n2){
    data_t temp = 0;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void reverse_array(data_t* arr, size_t N, data_t l){
    if(l >= N/2)
        return;
    swap(&arr[l], &arr[N-l-1]);
    reverse_array(arr, N, l+1);
}

/*
    1   2   3   4   5   6   7

    0   1   2   3   4   5   6

    l = 0 , r = 6 - 0 - 1 = 5
*/
