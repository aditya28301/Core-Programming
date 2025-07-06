#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void brute_approach(std::vector<int>& vec);
std::vector<int> optimal_approach(std::vector<int>& vec);	
std::vector<int> find_Min_Max(std::vector<int>& vec, int i);
	
int main(void){
	int min_num = 0;

	std::vector<int> vec = {1,2,3,4,5};
	std::vector<int> tmp;
	
	tmp = optimal_approach(vec);
	 
	std::cout<<"Smallest number is = " << tmp[0] << std::endl;
	std::cout <<"Largest number is = " << tmp[1] << std::endl;

	std::cout <<"Programe terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}


std::vector<int> findMin(std::vector<int>& vec, int i){

	static int min_num = INT_MAX;
	static int max_num = INT_MIN;
	
	static std::vector<int> tmp;

	if(vec.size() == i){
		
		tmp.push_back(min_num);
		tmp.push_back(max_num);

		return tmp;
	}

	min_num = std::min(min_num, vec[i]);		
	max_num = std::max(max_num, vec[i]);

	return(findMin(vec, i + 1));
}


std::vector<int> optimal_approach(std::vector<int>&vec){
	
	return (findMin(vec,0));
}

void brute_approach(std::vector<int>& arr){
	
	int max = INT_MIN;
	int min = INT_MAX;

	for(int i = 0; i < arr.size(); ++i){
		if(arr[i] > max){
			max = arr[i];
		}

		if(arr[i] < min){
			min = arr[i];
		}	
	}	

	std::cout <<"Largest number is = " << max << std::endl;
	std::cout <<"Smallest number is = " << min << std::endl;
}
