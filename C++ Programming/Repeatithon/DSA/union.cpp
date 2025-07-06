#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <set>
#include <vector>

std::set<size_t> brute_set(std::vector<size_t>& vec1, std::vector<size_t>& vec2);
std::map<size_t, size_t> brute_map(std::vector<size_t>& vec1, std::vector<size_t>& vec2);
std::vector<size_t> optimal_two_pointer(std::vector<size_t>& vec1, std::vector<size_t>& vec2);
 
int main(void){
	std::vector<size_t> vec1 = {1,2,3,4,5};
	std::vector<size_t> vec2 = {2,3,4,4,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5};

	std::set<size_t> union_set = brute_set(vec1, vec2);
	std::map<size_t, size_t> union_map = brute_map(vec1, vec2);
	std::vector<size_t> union_vec = optimal_two_pointer(vec1, vec2);

	std::cout <<"Map" << std::endl;
	for(std::map<size_t, size_t>::iterator it = union_map.begin(); it != union_map.end(); ++it){
	std::cout << it->first << std::endl;
	}

	std::cout << std::endl;
	std::cout <<"Set" << std::endl;
	for(std::set<size_t>::iterator it = union_set.begin(); it != union_set.end(); ++it){
		std::cout << *it << std::endl;
	}

	std::cout << std::endl;
	std::cout <<"Vector" << std::endl;
	for(std::vector<size_t>::iterator it = union_vec.begin(); it != union_vec.end(); ++it){
		std::cout << *it << std::endl;
	}
	return EXIT_SUCCESS;
}

std::set<size_t> brute_set(std::vector<size_t>& vec1, std::vector<size_t>& vec2){
	std::set<size_t> union_set;

	for(size_t i = 0; i < vec1.size(); ++i){
		union_set.insert(vec1[i]);
	}	

	for(size_t i = 0; i < vec2.size(); ++i){
		union_set.insert(vec2[i]);
	}
	
	return union_set;
}

std::map<size_t, size_t> brute_map(std::vector<size_t>& vec1, std::vector<size_t>& vec2){
	std::map<size_t, size_t> union_map;

	for(size_t i = 0; i < vec1.size(); ++i){
		union_map[vec1[i]]++;
	}

	for(size_t i = 0 ; i < vec2.size(); ++i){
		union_map[vec2[i]]++;
	}

	return union_map;
}

std::vector<size_t> optimal_two_pointer(std::vector<size_t>& vec1, std::vector<size_t>& vec2){
	std::vector<size_t> temp;
	
	size_t i = 0;
	size_t j = 0;

	for(; i < vec1.size() && j < vec2.size(); ){
		if(vec1[i] < vec2[j]){
			if(i == 0 || temp.back() != vec1[i]){
				temp.push_back(vec1[i]);
			}
			++i;
		}
		else{
			if(j == 0 || temp.back() != vec2[j]){
				temp.push_back(vec2[j]);	
			}
			++j;
		}
	}	


	for(; i < vec1.size(); ++i){
		if(temp.back() != vec1[i]){
			temp.push_back(vec1[i]);
		}
	}

	for(; j < vec2.size(); ++j){
		if(temp.back() != vec2[j]){
			temp.push_back(vec2[j]);
		}
	}
	
	return temp;
}	
