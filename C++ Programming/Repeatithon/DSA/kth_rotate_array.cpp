#include <cstdio>                                                                            
#include <cstdlib>
#include <iostream>
#include <vector>

void reverse(std::vector<size_t>& vec, size_t l, size_t r){
	size_t temp;

	while(l < r){
		temp = vec[l];
		vec[l] = vec[r];
		vec[r] = temp;
		++l;
		--r;	
	}
}

void left_rotate_optimise(std::vector<size_t>& vec, size_t k){
	
	//calculating the rotation
	k = k % vec.size();

	//reversing the element from their position
	reverse(vec, 0, vec.size() - k - 1);
	reverse(vec, vec.size() - k, vec.size() - 1);
	reverse(vec, 0, vec.size() - 1);
}

void right_rotate_optimise(std::vector<size_t>& vec, size_t k){			
	left_rotate_optimise(vec, k);
}

void right_rotate_brute(std::vector<size_t>& vec, size_t k){
	
	//Calculating the rotation
	k = k % vec.size();
	
	//copying the k-element in temp array
	std::vector<size_t> temp;
	for(size_t i = vec.size() - k; i < vec.size(); ++i){
		temp.push_back(vec[i]);		
	}			

	//Shifting the remianing element to the right side 
	for(size_t i = vec.size() - k - 1; i < vec.size(); --i){
		vec[i + k] = vec[i];			
	} 
	
	//std::cout <<"Size of temp is = " << temp.size() << std::endl;
	//Copying the element from temp array to back to original array
	for(size_t i = 0; i < k; ++i){
		//std::cout <<"index = " << i << std::endl;
		vec[i] = temp[i];	
	}  									
}

void left_rotate_brute(std::vector<size_t>& vec, size_t k){
	k = k % vec.size();
	//std::cout <<"Executing "<< std::endl;
	//Copying the k-element in temp array
	std::vector<size_t> temp;
	for(size_t i = 0; i < k; ++i){
		temp.push_back(vec[i]);
	}

	//Shifitng the remaining element to the left side
	for(size_t i = vec.size() - k; i < vec.size(); ++i){
		vec[i - k] = vec[i];	
	}

	//Copying the element from temp array back to the original array
	for(size_t i = vec.size() - k; i < vec.size(); ++i){
		vec[i] = temp[i - (vec.size() - k)];	
	}	
	//std::cout <<"Execution end" << std::endl;
}

void left_rotate_kth_array(std::vector<size_t>& vec, size_t k){
	size_t temp;
	size_t j;
	for(size_t i = 0; i < k; ++i){
		temp = vec[0];	
		for(j = 1; j < vec.size() ; ++j){
		                   	vec[j - 1] = vec[j];				
		}
		vec[j - 1] = temp; 								
	}
}

void right_rotate_kth_array(std::vector<size_t>& vec, size_t k){
	size_t temp;
	size_t j;
	for(size_t i = 0; i < k; ++i){
		temp = vec[vec.size() - 1];
		for(j = vec.size() - 1; j > 0; --j){
			vec[j] = vec[j - 1];			
		}
		vec[j] = temp; 							
	}
}

void show(std::vector<size_t>& vec){
	//std::cout <<"Showing vecotr" << std::endl;
	for(size_t i = 0; i < vec.size(); ++i){
		std::cout << vec[i] <<" ";
	}
	//std::cout <<"Shwoing vector end" << std::endl;
}

int main(int argc, char* argv[]){

	if(argc < 3){ std::cout << "Not enough argument" << std::endl; exit(EXIT_FAILURE); }
	std::vector<size_t> vec = {3,7,8,9,10,11};
	int direction;
	int k;
	
	k = std::atoi(argv[1]);
	direction = atoi(argv[2]);

	std::cout <<"Array before rotate" << std::endl;
	show(vec);

	switch(direction){
		case 0 :
			left_rotate_optimise(vec, k);
			break;
		case 1 :
			right_rotate_optimise(vec, k);
			break;
			
	}
	std::cout << std::endl;
	std::cout <<"Array rotate after = " << k <<" iteration" << std::endl;	
	show(vec);
	std::cout << std::endl <<"Programme termianted sucesfully" << std::endl;
	return EXIT_SUCCESS;
}
