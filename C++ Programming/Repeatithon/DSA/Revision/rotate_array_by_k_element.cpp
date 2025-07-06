#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class rotate_k_element{
	
	private:
		std::vector<int> vec;
		size_t k;

		void reverse_array(size_t l, size_t r){
			
			size_t temp = 0;

			while (l < r){
				
				temp = vec[l];
				vec[l] = vec[r];
				vec[r] = temp;	
				
				++l;
				--r;	
			}
	
		}
	
	public:
	
		rotate_k_element(std::vector<int>& ref_vec, size_t _k) : 
		vec(ref_vec), k(_k) { } 

		void brute_right_rotate_k(){

			std::vector<int> temp;
			
			// Transfering the element into the temp array
			for(size_t i = 0; i < k; ++i){
				
				temp.push_back(vec[vec.size() - k + i]);
			}

			// Shifting the element to the rght side

			for(size_t i = vec.size() - 1; i >= 2; --i){
				
				vec[i] = vec[i - k];	
			}	
			
			// adding element back from temp array to the orifinal array

			for(size_t i =0; i < temp.size(); ++i){

				vec[i] = temp[i];
			} 
		}

		void brute_left_rotate_k(){
			
			std::vector<int> temp;

			// Transfer element from kth element to the temp vector

			for(size_t i =0 ; i < k; ++i){
				
				temp.push_back(vec[i]);
			}			

			// Shifting the element to the left side of the array
	
			for(size_t i = 0; i < vec.size() - k; ++i){
			
				vec[i] = vec[k + i];
			}			


			// Transfering the temp element back to the orginal array

			for(size_t i = 0 ; i < temp.size(); ++i){
				
				vec[vec.size() - k + i] = temp[i];
			}
		}
		
		void optimal_left_rotate(){

			reverse_array(0, k - 1);
			reverse_array(k, vec.size() - 1);
			reverse_array(0, vec.size() - 1);
		}

		void optimal_right_rotate(){

			reverse_array(vec.size() - k, vec.size() - 1);
			reverse_array(0, k - 1);
			reverse_array(0, vec.size() - 1);
		}	

		void optimal_rotate_k(char choice){

			switch(choice){
			
				case 'l':
					optimal_left_rotate();
					break;
				
				case 'r':
					optimal_right_rotate();
					break;
			}
		}

		void show(void){
		
			for(size_t i = 0; i < vec.size(); ++i){
			
				std::cout << vec[i] <<" ";	
			}
			
			std::cout << std::endl;
		}		
};

int main(void){

	std::cout <<"---------------------Programme started------------------------" << std::endl;
	std::cout << std::endl;
	
	std::cout <<"OUTPUT:=" << std::endl;

	std::cout << std::endl;

	std::vector<int> vec = {1,2,3,4,5,6,7};

	rotate_k_element obj1(vec, 2);
	
	obj1.optimal_rotate_k('r');
	
	obj1.show();

	std::cout << std::endl;
	std::cout <<"------------------Programe terminated succesfully-------------" << std::endl;			
	return EXIT_SUCCESS;
}
