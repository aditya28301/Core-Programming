#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>

void rotate_array_kth(std::vector<size_t>& arr, size_t k);
void show_array(std::vector<size_t>& arr);
std::vector<size_t> rotate_array_brute_force(std::vector<size_t>& arr, size_t k);

int main(int argc, char* argv[]){
	if(argc < 1){
		std::cout <<"Argument is not enough" << std::endl;
		return EXIT_FAILURE;
	}
	
	size_t k = 0;
	k = atoi(argv[1]);
	//std::cout <<"K value of command line argument" << k << std::endl;
	std::vector<size_t> arr;	
	std::vector<size_t> temp;

	arr.push_back(3);
	arr.push_back(7);
	arr.push_back(8);
	arr.push_back(9);
	arr.push_back(10);
	arr.push_back(11);
	
	std::cout <<"Before rotating the array" << std::endl;
	show_array(arr);	
	temp = rotate_array_brute_force(arr, k);
	std::cout << std::endl;
	std::cout <<"After rotating the array" << std::endl;
	show_array(temp);
	std::cout << std::endl;
	std::cout <<"Programe terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}

std::vector<size_t> rotate_array_brute_force(std::vector<size_t>& arr, size_t k){

	std::vector<size_t> temp;

	for(size_t i = arr.size() - k; i < arr.size(); ++i){
		temp.push_back(arr[i]);		
	} 	

	for(size_t i = 0; i < arr.size() - k; ++i){
		temp.push_back(arr[i]);
	}
	return temp;
}


void show_array(std::vector<size_t>& arr){
	
	for(size_t i = 0; i < arr.size(); ++i){
		std::cout << arr[i] <<" ";
	}
}

void rotate_array_kth(std::vector<size_t>& arr, size_t k){

	//std::cout <<"K value is = " << k << std::endl;
	size_t temp = 0;
	
	for(size_t i = 0; i < k; ++i){
		temp = arr[arr.size() - 1];
		for(size_t j = arr.size() - 1; j > 0; --j){
			arr[j] = arr[j - 1];	
		}
		arr[0] = temp;
	}
}
