#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <set>


class rm_dublicate{
	private:
		std::vector<int> vec;

	public:
		rm_dublicate(std::vector<int>& ref_vec) : vec(ref_vec) {

		} 

		size_t remove_dublicate_brute(){
			
			std::set<int> unique_element;

			for(size_t i = 0; i < vec.size(); ++i){
					
				unique_element.insert(vec[i]);
			}
			
			size_t i = 0;

			for(std::set<int>::iterator it = unique_element.begin(); it != unique_element.end(); ++it){
				
				vec[i++] = *it;
			}
			return (unique_element.size());
		}	

	
		size_t remove_dublicate_optimal(){

			int track = 0;

			for(size_t i = 1; i < vec.size(); ++i){
				
				if(vec[i] != vec[i - 1]){
					
					++track;
						
					vec[track] = vec[i];
				}
			}
				
			return (track + 1);
		}		
	
		void show(size_t size){
				
			for(size_t i = 0; i < size; ++i){
			
				std::cout << vec[i] <<" ";
			}
			
			std::cout << std::endl;
		}
};

int main(void){

	std::cout <<"--------------------------------Programe started succesfully------------------------------" << std::endl;

	std::cout << std::endl;

	size_t size = 0;

	std::vector<int> vec = {0, 1, 1, 1, 2, 2, 2, 3, 3, 4, 5, 6, 7, 7, 7, 8, 8, 8};
	
	rm_dublicate obj1(vec);

	size = obj1.remove_dublicate_optimal();
 	
	obj1.show(size);

	std::cout << std::endl;		
	
	std::cout <<"---------------------------------Programme terminated succesfully-------------------------" << std::endl;
	return EXIT_SUCCESS;
}
