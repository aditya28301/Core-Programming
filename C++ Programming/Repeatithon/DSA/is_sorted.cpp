#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

bool isSorted(std::vector<size_t>& vec, size_t size);
bool isSorted_brute(std::vector<size_t>& vec, size_t size);

int main(void){
	std::vector<size_t> arr;
	bool status = false;

	arr.push_back(100);
	arr.push_back(200);
	arr.push_back(300);
	arr.push_back(400);
	arr.push_back(500);

	status = isSorted(arr, arr.size());
	
	if(status == true)
		std::cout <<"Array is sorted" << std::endl;
	else
		std::cout <<"Array is not sorted" << std::endl;		
	return EXIT_SUCCESS;
}
bool isSorted_brute(std::vector<size_t>& arr, size_t size){
	
	for(size_t i = 0 ; i < size - 1; ++i){
		for(size_t j = i + 1; j < size; ++j){
			if(arr[j] < arr[j-1]){
				return false;
			}
		}
	}
	return true;
}


bool isSorted(std::vector<size_t>& arr, size_t size){
	
	for(size_t i = 0; i < size; ++i){
		
		if(arr[i-1] > arr[i])
			return false;
	}
	return true;
}
