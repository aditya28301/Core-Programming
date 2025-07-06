#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

class find_occurence{

	private:
		std::vector<int> vec;
	public:

		find_occurence(std::vector<int>& ref_vec) : vec(ref_vec){ } 

		size_t optimal_find_occurence(){
			
			size_t xor_sum = 0;

			for(size_t i = 0; i < vec.size(); ++i){
					
				xor_sum = xor_sum ^ vec[i];
			}				

			return xor_sum;
		}

		size_t better_find_occurence(){
		
			int max_element = 0;

			for(size_t i = 0; i < vec.size(); ++i){
				
				max_element = std::max(max_element, vec[i]);
			}	

			std::vector<int> temp(max_element + 1, 0);

			for(size_t i = 0; i < vec.size(); ++i){
				
				temp[vec[i]]++;
			}

			for(size_t i = 0; i < temp.size(); ++i){
				
				if(temp[i] == 1)
					return i;
			}
		}
	
		size_t brute_find_occurence(){

			size_t current_element = 0;

			size_t count = 0;

			for(size_t i = 0; i < vec.size(); ++i){
			
				current_element = vec[i];
				
				count = 0;

			
				for(size_t i = 0; i < vec.size(); ++i){

					if(vec[i] == current_element){
						++count;
					}
				}	

				if(count == 1)
					return current_element;	
			}	
		}		
};

int main(void){

	std::cout <<"--------------------------------Programe started succsufully--------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::vector<int> vec = {4, 1, 2, 1, 2};
	
	size_t repeat_once_element = 0;

	find_occurence obj1(vec);

	repeat_once_element = obj1.optimal_find_occurence();
	
	std::cout <<"The element occured one time is = " << repeat_once_element << std::endl;

	std::cout << std::endl;

	std::cout << std::endl;

	std::cout <<"--------------------------------Programe termianted succesfully---------------------------------------" << std::endl;
	return EXIT_SUCCESS;
}	
