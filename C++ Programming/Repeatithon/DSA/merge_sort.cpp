#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

void merge_sort(std::vector<size_t>& vec, size_t low, size_t high);
void merge(std::vector<size_t>& vec, size_t low, size_t mid, size_t high);

int main(void){
	std::vector<size_t> vec;

	vec.push_back(100);
	vec.push_back(99);
	vec.push_back(88);
	vec.push_back(77);
	vec.push_back(66);

	std::cout <<"Original array" << std::endl;
	for(std::vector<size_t>:: iterator it = vec.begin(); it != vec.end(); ++it){
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	merge_sort(vec, 0, vec.size() - 1);

	std::cout <<"After sorting the array" << std::endl;
	for(std::vector<size_t>:: iterator it = vec.begin(); it != vec.end(); ++it){
		std::cout << *it <<" ";	
	}

	return EXIT_SUCCESS;
}

void merge(std::vector<size_t>& vec, size_t low, size_t mid, size_t high){
	std::vector<size_t> temp;
	
	size_t l = low;
	size_t r = mid + 1;

	while( l <= mid && r <= high){
		if(vec[l] <= vec[r]){
			temp.push_back(vec[l]);
			++l;
		}
		else{	
			temp.push_back(vec[r]);
			++r;
		}			
	}	

	while( l <= mid ){
		temp.push_back(vec[l]);
		++l;					
	}

	while( r <= high){
		temp.push_back(vec[r]);
		++r;	
	}

	for(size_t i = low; i <= high; ++i){
		
		vec[i] = temp[i - low];		
		
	}
}

void merge_sort(std::vector<size_t>& vec, size_t low, size_t high){
	
	size_t mid;

	if(low >= high)
		return;

	mid = low + (high - low) / 2;

	merge_sort(vec, low, mid);
	merge_sort(vec, mid+1, high);
	merge(vec, low, mid, high); 
}
