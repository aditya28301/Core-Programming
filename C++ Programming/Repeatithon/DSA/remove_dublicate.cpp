#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>

size_t remove_dublicate_2(std::vector<size_t>& arr);
size_t brute_force(std::vector<size_t>& arr);
size_t optimal_approach(std::vector<size_t>& arr);

void print(std::vector<size_t>& arr, size_t size);

int main(void){
	std::vector<size_t> arr;
	size_t count;

	arr.push_back(1);
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(3);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(5);
	arr.push_back(6);

	//std::cout <<"Array before removing dublicate element" << std::endl;
	//print(arr, arr.size());
	
	//std::cout << std::endl;
	count = optimal_approach(arr);
	
	//std::cout <<"Array after removing dublicate element"<< std::endl;
	//print(arr, arr.size());

	//std::cout << std::endl;
	
	std::cout <<"count is = " << count << std::endl;
	std::cout <<"Programme terminated succesfully" << std::endl;
	return EXIT_SUCCESS;
}

size_t optimal_approach(std::vector<size_t>& arr){
	ssize_t index = 0;

	for(size_t j = 1; j < arr.size(); ++j){
		if(arr[index] != arr[j]){
			index= index + 1;
			arr[index] = arr[j];
		}	
	}	
	return index + 1;
}

size_t remove_dublicate(std::vector<size_t>& arr){
	
	if(arr.size() == 1)
		return arr.size();
 
	size_t i;

	for(i = 0; i < arr.size(); ++i){
		if(i + 1 < arr.size() && arr[i] == arr[i + 1]){
			for(size_t j = i+1; j < arr.size(); ++j){
				arr[j-1] = arr[j];
			}
			arr.pop_back();
			print(arr, arr.size());
			i = 0;
		}		
	}

}


size_t brute_force(std::vector<size_t>& arr){
	std::set<ssize_t> s1;

	for(size_t i = 0; i < arr.size(); ++i){
		s1.insert(arr[i]);
	}
	return s1.size();
}

size_t remove_dublicate_2(std::vector<size_t>& arr){
	
	if(arr.size() == 1)
		return arr.size();

	size_t i = 0;

	for(size_t j = 0; j < arr.size(); ++j){
		
		if(arr[j] != arr[i]){
			arr[i+1] = arr[j];
			++i;
		}
	}
	return i + 1;
}

size_t remove_dublicate_1(std::vector<size_t>& arr){
	
	if(arr.size() == 1)
		return arr.size();

	size_t i;

	for(i = 0; i < arr.size(); ++i){
		if(i + 1 < arr.size() && arr[i] == arr[i + 1]){
			for(size_t j = i+1; j < arr.size(); ++j){
				arr[j-1] = arr[j];
			}
			arr.pop_back();
			print(arr, arr.size());
			i = 0;
		}		
	}
	return arr.size();	
}

void print(std::vector<size_t>& arr, size_t size){
	
	for(size_t i = 0; i < size; ++i){
		std::cout <<arr[i] <<" ";
	}
	std::cout << std::endl;
}
