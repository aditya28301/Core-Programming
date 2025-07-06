#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

class two_sum{
	
	private:
		std::vector<int> vec;
		size_t target;

	public:
		
		two_sum(std::vector<int>& ref_vec, size_t target_) : vec(ref_vec), target(target_) { }
	
		bool optimal_two_sum_var1(){
			
			size_t left = 0;
			size_t right = vec.size() - 1;
			size_t sum = 0;

			while(left < right){
				
				sum = vec[left] + vec[right];

				if(sum == target){
				
					return true;
				}
				else if(sum < target){
					++left;
				}
				else{
					--right;
				}
					
			}

			return false;		
		}	


		std::vector<int> optimal_two_sum_var2(){
	
			size_t left = 0;
			size_t right = vec.size() - 1;
			size_t sum = 0;
			std::vector<int> temp;

			while(left < right){
			
				sum = vec[left] + vec[right];

				if(sum == target){
					
					temp.push_back(left);
					temp.push_back(right);
					return temp;
				}
				else if(sum < target){
				
					++left;
				}
				else{

					--right;
				}
			}

			temp.push_back(-1);
			temp.push_back(-1);
			return temp;
		}	

		bool better_two_sum_var1(){

			std::map<int, int> mp;

			for(size_t i = 0; i < vec.size(); ++i){
			
				mp[vec[i]] = i; 
			}	

			size_t isPresent = 0;
			bool status = false;

			for(size_t i = 0 ; i < vec.size(); ++i){
		
				isPresent = target - vec[i];

				if(mp.find(isPresent) != mp.end())
					return true;
				else
					status =  false;		
			}

			return status;
		}

		std::vector<int> better_two_sum_var2(){
		
			std::map<int, int> mp;
			
			std::vector<int> temp;

			for(size_t i = 0; i < vec.size(); ++i){
				
				mp[vec[i]] = i;		
			}

			size_t isPresent = 0;

			for(size_t i = 0; i < vec.size(); ++i){
		
				isPresent = target - vec[i];

				if(mp.find(isPresent) != mp.end()){
					temp.push_back(i);
					temp.push_back(mp[isPresent]);
					return temp;
				}		 		
			}
			
			temp.push_back(-1);
			temp.push_back(-1);
			
			return temp;
		}


		bool brute_two_sum_var1(){
			
			for(size_t i = 0; i < vec.size(); ++i){
				
				for(size_t j = i + 1; j < vec.size(); ++j){
		
					if(vec[i] + vec[j] == target)
						return true;
				}
			}

			return false;		
		}

		std::vector<int> brute_two_sum_var2(){

			std::vector<int> temp;

			for(size_t i = 0; i < vec.size(); ++i){

				for(size_t j = 0; j < vec.size(); ++j){
						
					if(vec[i] + vec[j] == target){	
						
						temp.push_back(i);
						temp.push_back(j);

						return temp;
					}
							
				}
	
			}
				
			temp.push_back(-1);
			temp.push_back(-1);

			return temp;
		}	

};

int main(void){

	std::cout <<"----------------------------------------------------Programe started succesfully------------------------------------------------------" << std::endl;

	std::cout << std::endl;

	bool status;
	
	std::vector<int> temp;

	std::vector<int> vec = {2,6,5,8,11};

	two_sum obj1(vec, 14);

	status = obj1.optimal_two_sum_var1();
		
	if(status == true)
		std::cout <<"YES" << std::endl;
	else 
		std::cout <<"NO" << std::endl;

	temp = obj1.optimal_two_sum_var2();

	std::cout <<temp[0] <<" , " << temp[1] << std::endl;
	
	std::cout << std::endl;

	std::cout <<"---------------------------------------------------Programe terminated succesfully--------------------------------------------------" << std::endl;
	
	return EXIT_SUCCESS;

}
