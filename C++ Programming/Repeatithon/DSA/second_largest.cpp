#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>

ssize_t second_smallest(std::vector<ssize_t>& arr, ssize_t size);
ssize_t second_largest(std::vector<ssize_t>& arr, ssize_t size);

int main(void){
	ssize_t s_smallest;
	ssize_t s_largest;

	std::vector<ssize_t> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	s_smallest = second_smallest(vec, vec.size());
	s_largest = second_largest(vec, vec.size());
	
	std::cout <<"Second largest number is = " << s_largest << std::endl;
	std::cout <<"Second smallest number is= " << s_smallest << std::endl;
	return EXIT_SUCCESS;
}

ssize_t second_largest(std::vector<ssize_t>& arr, ssize_t size){

	ssize_t largest = arr[0];
	ssize_t second_largest = INT_MIN;


	for(size_t i = 0; i < arr.size(); ++i){
		if(arr[i] > largest){
			second_largest = largest;
			largest = arr[i];
		}
		else if(arr[i] < largest && arr[i] > second_largest){
			second_largest = arr[i];
		}
	}
	return second_largest;
}

ssize_t second_smallest(std::vector<ssize_t>& arr, ssize_t size){
	
	ssize_t smallest = arr[0];
	ssize_t second_smallest = INT_MAX;


	for(size_t i = 0; i < arr.size(); ++i){
		if(arr[i] < smallest){
			second_smallest = smallest;
			smallest = arr[i];
		}
		else if(arr[i] > smallest && arr[i] < second_smallest){
			second_smallest = arr[i];
		}
	}
	return second_smallest;
}

	
