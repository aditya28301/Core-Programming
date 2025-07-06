#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <vector>

size_t max(size_t lhs, size_t rhs);

namespace DSA{

	int find_single_appearance(std::vector<size_t>& vec);
	int using_hashing_method(std::vector<size_t>& vec);
	int using_xor_Optimal_method(std::vector<size_t>& vec);

}			
int main(void){
	std::vector<size_t> vec={1, 1, 2, 1, 2, 2, 1};
	int number = 0;

	//number = DSA::find_single_appearance(vec);
	number = DSA::using_xor_Optimal_method(vec);
	std::cout <<"The number that appear once only is = " << number << std::endl;
	return EXIT_SUCCESS;
}

int DSA::using_xor_Optimal_method(std::vector<size_t>& vec){
		
	size_t xor_num = 0;
	for(size_t i = 0 ; i < vec.size(); ++i){
		xor_num = xor_num ^ vec[i];	
	}	
	
	return xor_num;
}

int DSA::find_single_appearance(std::vector<size_t>& vec){
	std::map<size_t, size_t> m_count;

	for(size_t i = 0; i < vec.size(); ++i){
		m_count[vec[i]]++;	
	}

	for(std::map<size_t, size_t>::iterator it = m_count.begin(); it != m_count.end(); ++it){
		if(it->second == 1){
			return it->first;
		}
	}
	return -1;		
}


size_t max(size_t lhs, size_t rhs){

	if(lhs >= rhs)
		return lhs;
	else
		return rhs; 	
}

int DSA::using_hashing_method(std::vector<size_t>& vec){

	// Traverinsg the vector and find the maximum element in vector
	size_t max_num = -1;

	for(size_t i = 0; i < vec.size(); ++i){
		max_num = max(max_num, vec[i]);
	}
	std::vector<size_t> temp(max_num);
	
	// Hasing the array element in a associated array
	for(size_t i = 0; i < vec.size(); ++i){
		temp[vec[i]]++;
	}	
	
	// Traversing the array where only 1 has are their this is the result
	
	for(std::vector<size_t>:: iterator it = temp.begin(); it != temp.end(); ++it){
		if((*it) == 1)
			return *it;	
	}
	return -1;
}

	
