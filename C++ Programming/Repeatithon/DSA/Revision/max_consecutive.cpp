#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

class consecutive_number{
	
	private:
		std::vector<int> vec;
	
	public:

		consecutive_number(std::vector<int>& ref_vec) : vec(ref_vec) { }

		int find_max_consecutive_number(){

			size_t count = 0;
			
			size_t max_count = 0;

			for(size_t i = 0; i < vec.size(); ++i){
			
				if(vec[i] == 1){
					
					++count;
				}		
				else{
					count = 0;
				}

				max_count = std::max(count, max_count);		
			}
			
			return max_count;
		}
};

int main(void){

	std::cout <<"------------------------------------Programe started sucesfully-----------------------------------------------" << std::endl;

	std::cout << std::endl;

	std::vector<int> vec = {1, 0, 1, 1, 0, 1};
	
	size_t max_count = 0;

	consecutive_number obj1(vec);

	max_count = obj1.find_max_consecutive_number();
	
	std::cout <<"Max consecutive number is = " << max_count << std::endl;	

	std::cout << std::endl;
	
	std::cout << std::endl;

	std::cout <<"----------------------------------Programe terminated sucesfully----------------------------------------------" << std::endl;

	return EXIT_SUCCESS;
}
