#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

class majority{

	private:            
		std::vector<int> vec;

	public:
		majority(std::vector<int>& ref_vec) : vec(ref_vec) { }

		int optimal_majority_element(){

			size_t ele;
			size_t  count = 0;

			for(size_t i = 0; i < vec.size(); ++i){

				if(count == 0){
					ele = vec[i];
					count = 1;
				} 
				else if(vec[i] == ele){
					
					++count;
				}
				else{
			
					--count;
				}	
			}

			// verfying majority element is correct or not

			size_t count_cal = 0;

			for(size_t i = 0; i < vec.size(); ++i){

				if(vec[i] == ele)
					++count_cal;
			}

			if(count_cal > vec.size() / 2)
				return  ele;

			return -1;
		}

		int brute_majority_element(){
			
			std::map<int, int> mp;
			int max_count = 0;
			int ans = 0;
		
			for(size_t i = 0; i < vec.size()/2; ++i){

				mp[vec[i]] = i;
			}

			for(std::map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it){
		
				max_count = std::max(max_count, it->first);	
			}

			if(mp.find(max_count) != mp.end())
				ans = mp.find(max_count)->first;

			return ans;
		}
};
int main(void){

	std::cout<<"----------------------------------Programe started succesfully-------------------------------------" <<std::endl;

	std::cout << std::endl;

	std::vector<int> vec = {2,2,2,2,2,1,1,1};
	
	ssize_t ans = 0;

	majority obj1(vec);
		
	ans = obj1.optimal_majority_element();

	std::cout <<"Majority element is occured N/2 time is= " << ans << std::endl;

	std::cout << std::endl;

	std::cout <<"---------------------------------------Programe terminated succesfully-------------------------------------" << std::endl;
	
	return EXIT_SUCCESS;
}
