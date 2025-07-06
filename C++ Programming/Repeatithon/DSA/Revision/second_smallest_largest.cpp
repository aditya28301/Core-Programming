#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <climits>

class second_smallest_largest{
	
	private:
		std::vector<int> vec;

	public:
		second_smallest_largest(std::vector<int>& ref_vec) : vec(ref_vec) { 
				
			//std::cout <<"constructor value are initialize" << std::endl;
		}
	
		
		void asc_merge_array(std::vector<int>& ref_vec_sort, size_t l, size_t m, size_t r){
			
			size_t left = l;

			size_t right = m + 1;

			std::vector<int> temp;

			while(left <= m  && right <= r){
	
				if(ref_vec_sort[left] <= ref_vec_sort[right]){
					temp.push_back(ref_vec_sort[left]);
					++left;				
				}
				else{
					temp.push_back(ref_vec_sort[right]);	
					++right;
				}
			}

			while(left <= m){
				temp.push_back(ref_vec_sort[left]);
				++left;	
			}
			
			while(right <= r){
				temp.push_back(ref_vec_sort[right]);
				++right;
			}
	
		  	for(size_t i = l; i <= r; ++i){
				ref_vec_sort[i] = temp[i - l];
			}
		}
		

		////

		
		void desc_merge_array(std::vector<int>& ref_vec_sort, size_t l, size_t m, size_t r){
			
			size_t left = l;

			size_t right = m + 1;

			std::vector<int> temp;

			while(left <= m  && right <= r){
	
				if(ref_vec_sort[left] >= ref_vec_sort[right]){
					temp.push_back(ref_vec_sort[left]);
					++left;				
				}
				else{
					temp.push_back(ref_vec_sort[right]);	
					++right;
				}
			}

			while(left <= m){
				temp.push_back(ref_vec_sort[left]);
				++left;	
			}
			
			while(right <= r){
				temp.push_back(ref_vec_sort[right]);
				++right;
			}
	
		  	for(size_t i = l; i <= r; ++i){
				ref_vec_sort[i] = temp[i - l];
			}
		}

		///

		
		void asc_sort(std::vector<int>& ref_vec_sort, size_t l, size_t r){
		
			if(l >= r)
				return;
	
			size_t mid = l + ( r - l) / 2;
			
			asc_sort(ref_vec_sort, l, mid);
			asc_sort(ref_vec_sort, mid + 1, r);
			asc_merge_array(ref_vec_sort, l, mid, r);
								
		}

		///
	
		
		void desc_sort(std::vector<int>& ref_vec_sort, size_t l, size_t r){
		
			if(l >= r)
				return;
	
			size_t mid = l + ( r - l) / 2;
			
			desc_sort(ref_vec_sort, l, mid);
			desc_sort(ref_vec_sort, mid + 1, r);
			desc_merge_array(ref_vec_sort, l, mid, r);
								
		}

		///

		void merge_sort(size_t choice){

			switch(choice){
				case 1:
					asc_sort(vec, 0, vec.size() - 1);
					break;
				case 2:
					desc_sort(vec, 0, vec.size() - 1);
					break;
			}
		
		}
			
		void show() const {
			
			for(size_t i = 0; i < vec.size(); ++i){
				std::cout << vec[i] <<" ";
			}
		}
	
		std::vector<int> brute_approach_second_smallest_and_largest_number(){
					
			merge_sort(1);

			std::vector<int> temp;

			for(int i = vec.size() - 2; i >= 0; --i){ 
				if(vec[i] != vec[i + 1]){
					temp.push_back(vec[i]);
					break;
				}	
			}

		
			merge_sort(2);
	
			for(int i = vec.size() - 2; i >= 0; --i){ 
				if(vec[i] != vec[i + 1]){
					temp.push_back(vec[i]);
					break;
				}	
			}
			
			return temp;
		}

		std::vector<int> better_approach_second_smallest_and_largest_number(){
		
			std::vector<int> temp;

			// Find max and min from list of number
			
			int min = vec[0];
			int max = vec[0];
		
			int second_min = INT_MAX;
			int second_max = INT_MIN;

			for(size_t i = 0; i < vec.size(); ++i){
				
				min = std::min(min, vec[i]);
				max = std::max(max, vec[i]);
			}

			for(size_t i = 0; i < vec.size(); ++i){
				
				if(vec[i] < second_min && vec[i] != min){
					second_min = vec[i];
				}
				
				if(vec[i] > second_max && vec[i] != max){
					second_max = vec[i];
				}
			}

			temp.push_back(second_max);
			temp.push_back(second_min);
			
			return temp;
		}


		std::vector<int> optimal_approach_second_smallest_and_largest_number(){
			
			std::vector<int> temp;

			int max = vec[0];
			int second_max = INT_MIN;
	
			int min = vec[0];
			int second_min = INT_MAX;

			for(int i = 0 ; i < vec.size(); ++i){
				
				if(vec[i] > max){
					
					second_max = max;
					max = vec[i];
				}
				else if(vec[i] < max && vec[i] > second_max){
			
					second_max = vec[i];
				 }

				if(vec[i] < min){
					
					second_min = min;
					min = vec[i];
				}
				else if(vec[i] > min && vec[i] < second_min)
				{
					second_min = vec[i];
				}
			}

			temp.push_back(second_max);
			temp.push_back(second_min);
			
			return temp;	
		}
};                                                                                                                                                                                                                                                                       
int main(void){

	
	std::cout <<"-------------------------Programme Started succesfully------------------------" << std::endl;
	
	std::cout << std::endl;

	std::vector<int> vec = {0 ,100, 20, 1000 ,50};
		
	std::vector<int> temp;

	second_smallest_largest obj1(vec);

	//temp = obj1.brute_approach_second_smallest_and_largest_number();

	temp = obj1.better_approach_second_smallest_and_largest_number();
	
	std::cout <<"Second Largest numebr = " << temp[0] << std::endl;
	
	std::cout <<"Second Smallest number = " << temp[1] << std::endl;

	std::cout << std::endl;

	std::cout <<"-------------------------Programme terminated succesfully------------------------" << std::endl;

	return EXIT_SUCCESS;
}
