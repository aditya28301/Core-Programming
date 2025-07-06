#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

void moveZero(size_t* arr, size_t size);
void swap(size_t* first, size_t* second);

int main(int args, const char* argv[]){

	size_t arr[] = {10,20,30};

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
	ssize_t j = -1;
	size_t i;
	for(i = 0; i < size; ++i){
		if(arr[i] == 0){
			j = i;
			break;
		}
			
	}

	if(i == size)
		return;

	for(size_t i = j + 1; i < size; ++i){
		if(arr[i] != 0){
			swap(&arr[j], &arr[i]);
			++j;
		}		
	
	}	
}	                                                                                                                                                                                               
