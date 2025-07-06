#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

void moveZero(size_t* arr, size_t size);

int main(int args, const char* argv[]){

	size_t arr[] = {0,0};
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

void moveZero(size_t* arr, size_t size){
	std::vector<size_t> temp;
	for(size_t i = 0; i < size; ++i){
		if(arr[i] > 0)
			temp.push_back(arr[i]);	
	}		

	int i = 0;
	for(i = 0; i < temp.size(); ++i){
		arr[i] = temp[i];	
	}

	for(size_t rem = i; rem < size; ++rem){
		arr[rem] = 0;
	}
}                                                                                                                                                                                                  
