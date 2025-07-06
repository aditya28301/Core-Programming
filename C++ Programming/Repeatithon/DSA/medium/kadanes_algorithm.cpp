#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

class kadanes{
	
	private:
		std::vector<int> vec;

	public:
		kadanes(std::vector<int>& ref_vec) : vec(ref_vec) { }
		
		ssize_t optimal_kadanes(){
			
			ssize_t max_sum = 0;
			ssize_t sum = 0;

			for(ssize_t i = 0; i < vec.size(); ++i){

				sum = sum + vec[i];
				
				if(sum < 0){
					sum = 0;
				}

				if(sum > 0){
					
					max_sum = std::max(sum, max_sum);	
				}
			}

			return max_sum;
		}	

		ssize_t brute_kadanes(){
			
			if(vec.size() == 1)
				return vec[vec.size() - 1];
			
			ssize_t max_sum = 0;
			ssize_t sum = 0;

			for(ssize_t  i = 0; i < vec.size() - 2; ++i){
				
				sum = vec[i];

				for(ssize_t j = i + 1; j < vec.size(); ++j){
					
					sum = sum + vec[j];	
					
					max_sum = std::max(max_sum, sum);					
				}

							
			}	
			
				return max_sum;	
		}	

};

int main(void){
	
	std::cout <<"------------------------Programe strarted succesfully----------------------------" << std::endl;
	
	std::vector<int> vec {-2,1,-3,4,-1,2,1,-5,4};
	
	ssize_t max_sum = 0;

	kadanes obj1(vec);
	
	max_sum = obj1.optimal_kadanes();

	std::cout <<"Maximum sub array sum is = " << max_sum << std::endl;
	
	std::cout <<"-------------------------Programe terminated succesfully------------------------" << std::endl; 		
	return EXIT_SUCCESS;
}
