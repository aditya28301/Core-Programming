#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

void moveZero(size_t* arr, size_t size);
void swap(size_t* first, size_t* second);

int main(int args, const char* argv[]){

	size_t arr[] = {1, 2, 0, 4, 3, 0, 5, 0};

	size_t size = sizeof(arr) / sizeof(arr[0]);
	
	std::cout <<"Array size is = " << size << std::endl;

	moveZero(&arr[0], size);

	std::cout << std::endl << "Move Zero sucessfully done = "<< std::endl;
	
	for(size_t i = 0; i < size; ++i){
		std::cout << arr[i] <<" ";
	}

	std::cout << std::endl;

	return EXIT_SUCCESS;
}

void swap(size_t* first, size_t* second){
	size_t temp;
	temp = *first;
	*first = *second;
	*second = temp;		
}

void moveZero(size_t* arr, size_t size){
	size_t l = 0;
	size_t r = size - 1;

	for(;l <= r;){
		if(arr[l] <= 0 &&  arr[r] > 0){
			swap(&arr[l], &arr[r]);
			++l;
			--r;
		}
		else if(arr[l] == 0 && arr[r] == 0){
			--r;			
		}
		else{
			++l;
		}
	}	
}                                                                                                                                                                                                  
