#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class left_array{

	private:
		
		std::vector<int> vec;
	public:
		left_array(std::vector<int>& ref_vec) : vec(ref_vec){

		}

		void optimal_left_array_rotate(){

			size_t rotate_element = vec[0];

			for(size_t i = 1; i < vec.size(); ++i){
				
				vec[i - 1] = vec[i];
					
			} 

			vec[vec.size() - 1] = rotate_element;
		}


		void brute_left_array_rotate(){

			std::vector<int> temp;

			size_t rotate_element = vec[0];

			for(size_t i = 1; i < vec.size(); ++i){

				temp.push_back(vec[i]);		
			}
	
			size_t i;

			for(i = 0; i < temp.size(); ++i){
				
				vec[i] = temp[i];
			}
	
			vec[i] = rotate_element;
		}

		void show(){

			for(size_t i = 0; i < vec.size(); ++i){

				std::cout << vec[i] <<" ";
			}
		
			std::cout << std::endl;
		}		
	
};
 

int main(void){

	std::cout <<"---------------------------------Programme started succesfully--------------------------------" << std::endl;
	
	std::cout << std::endl;
		
	std::vector<int> vec = { 1,2,3,4,5 };			
	
	left_array obj1(vec);
	
	obj1.optimal_left_array_rotate();

	obj1.show();

	std::cout << std::endl;

	std::cout <<"---------------------------------Programme terminated succesfully--------------------------------" << std::endl;
	
	return EXIT_SUCCESS;
	}
