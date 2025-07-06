#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class longest_subarray{
	private:
		std::vector<int> vec;
		int k;
	
	public:

		longest_subarray(std::vector<int>& ref_vec, int _k) : vec(ref_vec), k(_k) {}
			
		size_t optimal_longest_subarray(){
			
			size_t right = 0;
			size_t left = 0;	
			size_t sum = 0;
			size_t max_total = 0;

			while(right < vec.size()){
				
				while(left <= right && sum > k){
				
					sum = sum - vec[lef];
					++left;		
				}

				if(sum == k)
					max_total = std::max(max_total, right - left + 1);

				++right;
				if(right < vec.size())
					sum = sum + vec[righ];
			}
		
			return max_total; 
		}		

		size_t better_longest_subarray(){
		
			std::map<long long, int> PreSum;	
			size_t sum = 0;
			size_t max_count =0;
			size_t rem = 0;

			for(size_t i = 0; i < vec.size(); ++i){
					
				sum = sum + vec[i];
		
				if(sum == k)
					max_count = std::max(max_count, i + 1);

				rem = sum - k;

				if(PreSum.find(rem) != PreSum.end()){
					
					max_count = std::max(max_count, i - PreSum[rem]);	
				}

				if(PreSum.find(rem) == PreSum.end()){
					
					PreSum[sum] = i;
				}		
			}	

			return max_count;
		}

		int brute_longest_subarray(){
			
			size_t sum;
			size_t count;
			size_t total_count = 0;

			for(size_t i =0 ; i < vec.size(); ++i){
				
				sum = 0;
				count = 1;
		
				for(size_t j = 0; j < vec.size(); ++j){	
					
					sum = sum + vec[j];
					
					if(sum == k)	
						total_count = std::max(total_count, count);
					
					++count;
				}
				
			}
			
			return total_count;
		}
};

int main(void){
	
	std::cout <<"------------------Programme started succesfully----------------" << std::endl;

	std::cout << std::endl;

	size_t len = 0;

	std::vector<int> vec = {2, 3, 5, 1, 9};
		
	longest_subarray obj1(vec, 10);

	len = obj1.better_longest_subarray();
	
	std::cout <<"The longest subarray is = " << len << std::endl; 

	std::cout << std::endl;

	std::cout <<"----------------Programe terminated succesfully----------------" << std::endl;
	
	return EXIT_SUCCESS;
}
