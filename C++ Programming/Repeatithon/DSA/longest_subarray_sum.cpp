#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <ctime>

const int MAX_NUM = 9999;

namespace DSA{
	int using_brute_force(std::vector<size_t>& vec, size_t k);
	int using_better_hashing(std::vector<size_t>& vec, size_t k);
	int using_optimal_approach(std::vector<ssize_t>& vec, size_t k);

	void random_number_gen(std::vector<size_t>& vec);
	void show(std::vector<size_t>& vec);
}

int main(void){

	int longest_count_subarray_sum = 0;

	std::vector<ssize_t> vec = {10, 5, 2, 7, 1, -10};

	//DSA::random_number_gen(vec);
	
	//DSA::show(vec);

	longest_count_subarray_sum = DSA::using_optimal_approach(vec, 15);
	
	std::cout <<"Longest subarray sum is = " << longest_count_subarray_sum << std::endl;
	
	std::cout <<"Programme terminated sucesfully" << std::endl;	
	
	return EXIT_SUCCESS;
}

int DSA::using_optimal_approach(std::vector<ssize_t>& vec, size_t k){

	size_t left = 0;
	size_t sum = 0;
	size_t len = 0;

	for(size_t right = 0; right < vec.size(); ++right){
		sum = sum + vec[right];
		
		if(sum == k){
			len = std::max(len, (right - left) + 1);
		}				
	
		while(sum > k){

			sum = sum - vec[left];

			++left;
		}
	}

	return len;
	}

void DSA::show(std::vector<size_t>& vec){
	
	for(std::vector<size_t>::iterator it = vec.begin(); it != vec.end(); ++it){
		std::cout << *it << " ";
	}	
}

void DSA::random_number_gen(std::vector<size_t>& vec){
	
	srand(time(0));

	for(size_t i = 0; i < MAX_NUM; ++i){
		
		vec.push_back( rand() % MAX_NUM + 1);
	}	
}

int DSA::using_better_hashing(std::vector<size_t>& vec, size_t k){
	std::unordered_map<int, size_t> hash_map;
	
	size_t sum = 0;
	size_t len = 0;
	size_t required_k_size = 0;

	for(size_t i =0 ; i < vec.size(); ++i){
		
		sum = sum + vec[i];
		
		if(sum == k){
			if((i + 1) > len)
				len = i + 1;

		}
	
		if(sum > k){
			
			required_k_size = sum - k;

			for(std::unordered_map<int, size_t>::iterator it = hash_map.begin(); it != hash_map.end(); ++it){
				if(it->second == required_k_size){
					len = std::max(len, (i - it->first));
				}
			}
		}
		
		hash_map.insert({i, sum});		
	}		
	return len;
}

int DSA::using_brute_force(std::vector<size_t>& vec, size_t k){
	
	size_t count = 0;
	size_t sum = 0;

	for(size_t i = 0; i < vec.size() - 1; ++i){
		
		sum = vec[i];
		count = 1;
		for(size_t j = i + 1; j < vec.size(); ++i){
			++count;
			sum = sum + vec[i];
			if(sum == k){
				return count;
			}	
		}
	}		
	return -1;
}
