#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>

class isSorted_array{
	private:
		std::vector<int> vec;

	public:
		
	isSorted_array(std::vector<int>& ref_vec) : vec(ref_vec) { }

	bool isSort_brute_approach(){
		
		for(size_t i = 0; i < vec.size(); ++i){
			
			for(size_t j = i + 1; j < vec.size(); ++j){
				
				if(vec[j] < vec[i]){
					return false;
				}
			}
		}
		
		return true;
	}

	bool isSort_optimal_approach(){
	
		for(size_t i = 1; i < vec.size(); ++i){
			
			if(vec[i] < vec[i - 1]){
				return false;
			}		
		}	

		return true;
	}
};

int main(void){
	
	std::cout <<"-------------------------------------- Programme started ------------------------------------------" << std::endl;
	
	bool status = false;
	
	std::vector<int> vec = {0, 2, 3, 4, 5, 6};

	isSorted_array obj1(vec);
	
	status = obj1.isSort_optimal_approach();
	
	std::cout << std::endl;

	if(status == true)
		std::cout<<"Array is sorted" << std::endl;
	else
		std::cout <<"Array is not sorted" << std::endl;

	std::cout << std::endl;
	
	std::cout <<"------------------------------------- Programme terminated --------------------------------------" << std::endl; 
	return EXIT_SUCCESS;
}
