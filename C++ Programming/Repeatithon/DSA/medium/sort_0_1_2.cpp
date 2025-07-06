#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class sort{
	
	private:
		
		std::vector<int> vec;
		static void swap(int& first, int& second){
		
			int temp = first;
			first = second;
			second = temp;		
		}
		
	public:
	
		sort(const std::vector<int> ref_vec) : vec(ref_vec) { }

		void show(void){

			for(size_t i = 0; i < vec.size(); ++i){
				
				std::cout <<vec[i] <<" ";
			}
			
			std::cout << std::endl;
		}

		void optimal_sort_0_1_2(){

			size_t low = 0;
			size_t mid = 0;
			size_t high = vec.size() - 1;

			while(mid < high){

				if(vec[mid] == 0){
					swap(vec[low], vec[mid]);
					++low;
					++mid;
				}
				else if(vec[mid] == 1){
					++mid;
				}
				else{
					swap(vec[mid], vec[high]);
					--high;
				}	 
			}
		}

		void brute_sort_0_1_2(){

			size_t count_zero = 0;
			size_t count_one = 0;
			size_t count_two = 0;

			// Getting the all count of zero and one and two
			for(size_t i = 0; i < vec.size(); ++i){
			
				if(vec[i] == 0)
					++count_zero;
				else if(vec[i] == 1)
					++count_one;
				else
					++count_two;		
			}

			// Putting all those value back to location

			for(size_t i = 0; i < count_zero; ++i){
				
				vec[i] = 0;		
			}

			for(size_t i = count_zero; i < count_zero + count_one; ++i){
			
				vec[i] = 1;
			}		

			for(size_t i = count_zero + count_one; 
				i < count_zero + count_one + count_two;
				++i){
				
				vec[i] = 2;
			
			}

		}

};

int main(void){

	std::cout <<"------------------Programe started sucesfully--------------" << std::endl;

	std::vector<int> vec = {2,0,2,1,1,0,1,2};
	
	sort obj1(vec);
	
	std::cout <<"Vector before sorted" << std::endl;

	obj1.show();

	obj1.optimal_sort_0_1_2();

	std::cout <<"Sorted array is" << std::endl;

	obj1.show();

	std::cout << std::endl;

	std::cout <<"-----------------------------Programe termianted succesfully---------------------------------------" << std::endl;
	return EXIT_SUCCESS;
}
