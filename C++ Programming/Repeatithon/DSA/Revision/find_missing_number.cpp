#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class find_missing_number{
	   
	private:
		std::vector<int> vec;
		size_t N;
	
	public:
	
	find_missing_number(std::vector<int>& ref_vec, size_t N_) :  vec(ref_vec), N(N_) { }	
	
	size_t optimal2_findMissing(){

		size_t xor_of_n =0;
		
		size_t xor_of_element = 0;

		for(size_t i = 0; i < N - 1; ++i){
			
			xor_of_element = xor_of_element ^ vec[i];	
			
			xor_of_n = xor_of_n ^ (i + 1);					
		}

		xor_of_n = xor_of_n ^ N;
							
		return xor_of_n ^ xor_of_element;
	}

	size_t optimal1_findMissing(){
		
		size_t sum_of_no = 0;
		
		size_t sum_of_element = 0;

		size_t find_missing_number = 0;

		sum_of_no = N * (N + 1) / 2;
	
		for(size_t i = 0; i < vec.size(); ++i){
			
			sum_of_element = sum_of_element + vec[i];             
		}		
			
		return sum_of_no - sum_of_element;
	}

	size_t better_findMissing(){

		size_t current_element = 0;

		bool status = false;
		

		for(size_t i = 1; i <= N; ++i){
			
			current_element = i;
			
			status = false;
	
			for(size_t j = 0; j < vec.size(); ++j){
					
				if(current_element == vec[j]){	
					status = true;
					break;
				}
			}
			
			if(status == false){
				return current_element;
			}
		}			
	}
	
	size_t brute_findMissing(){
			
		std::vector<int> temp(N,0);

		for(size_t i = 0; i < vec.size(); ++i){
				
			temp[vec[i]] = 1;			
		}	

		for(size_t i = 1; i < temp.size(); ++i){
			
			if(temp[i] == 0)
				return i;
		}	
	}

};

int main(void){
	
	std::cout <<"-------------------------------------Programe started succsfully------------------------------------------"<< std::endl; 
	
	std::cout << std::endl;

	std::vector<int> vec = {1, 2, 4, 5};
	
	size_t missing_number = 0;

	find_missing_number obj1(vec, 5);

	missing_number = obj1.optimal2_findMissing();	
		
	std::cout <<"Missing number from array is = " << missing_number << std::endl; 

	std::cout << std::endl;

	std::cout <<"------------------------------------Programe end successfully---------------------------------------------" << std::endl;

	return EXIT_SUCCESS; 
}
