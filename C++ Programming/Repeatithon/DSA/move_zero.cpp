#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
void brute_move_zero(std::vector<size_t>& vec);
void optimise_move_zero(std::vector<size_t>& vec);

void move_zero(std::vector<size_t>& vec){
	size_t track = -1;
	size_t temp;

	for(size_t i = 0; i < vec.size(); ++i){	
		if(vec[i] > 0){
			track++;
			temp = vec[track];
			vec[track] = vec[i];
			vec[i] = temp;
		}
	}												
}

void show(std::vector<size_t>& vec){
	std::cout <<"Show vector" << std::endl;
	for(size_t i = 0; i < vec.size(); ++i){
		std::cout << vec[i] <<" ";		
	}	
}

int main(void){
	
	std::vector<size_t> vec={1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
	std::cout <<"Vector before moving zero at the end" << std::endl;
	show(vec);
	std::cout << std::endl;
	optimise_move_zero(vec);	
	show(vec);
	std::cout << std::endl <<"Programme terminated succesfully"<< std::endl;
	return EXIT_SUCCESS;
}

void brute_move_zero(std::vector<size_t>& vec){
	std::vector<size_t> temp;
	
	for(size_t i = 0; i < vec.size(); ++i){
		//std::cout <<vec[i] << std::endl;
		if(vec[i] > 0){
			temp.push_back(vec[i]);
		}	
	}	
	
	size_t i;
	for(i = 0; i < temp.size(); ++i){
		vec[i] = temp[i];
	}

	for(; i < vec.size(); ++i){
		vec[i] = 0;
	}
}

void swap(size_t& ref_1, size_t& ref_2){	
	size_t temp;
	
	temp = ref_1;
	ref_1 = ref_2;
	ref_2 = temp;	
}

void optimise_move_zero(std::vector<size_t>& vec) {

	size_t track = -1;

	for(size_t i = 0; i < vec.size(); ++i){
		if(vec[i] > 0){ 
			++track;
			swap(vec[i], vec[track]);
		}
	}
	
}
 
