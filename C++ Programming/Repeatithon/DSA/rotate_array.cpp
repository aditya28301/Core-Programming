#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

void rotate_array(std::vector<size_t>& arr){
	size_t temp = arr[0];
	for(size_t i = 1; i < arr.size(); ++i){
		arr[i - 1] = arr[i]; 	

	}
	arr[arr.size() - 1] = temp;
}
int main(void){
	std::vector<size_t> arr;
	
	arr.push_back(1);                                                                              
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(4);
	arr.push_back(5);

	std::cout <<"Array before rotate element" << std::endl;

	for(size_t i = 0; i < arr.size(); ++i)
		std::cout << arr[i];	

	rotate_array(arr);

	std::cout << std::endl;
	std::cout <<"Array after rotate element" << std::endl;
	for(size_t i = 0; i < arr.size(); ++i){
		std::cout << arr[i];	
	}
	
	std::cout << std::endl;
	std::cout <<"Programme terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}
