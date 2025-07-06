#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class move_zero_end{
	
	friend std::ostream& operator<<(std::ostream& os, const move_zero_end& rhs);

	private:
		std::vector<size_t> vec;
		
	public:
		move_zero_end(std::vector<size_t>& ref_vec): vec(ref_vec){ }

		void swap(size_t& ref_1, size_t& ref_2){
			
			size_t temp;

			temp = ref_1;
			ref_1 = ref_2;	
			ref_2 = temp;						
		}

		void better_approach(){
		
			size_t track = 0;

			for(size_t i = 0; i < vec.size(); ++i){
			
				if(vec[i] > 0){
					
					swap(vec[i], vec[track]);
					++track;
				}
			}		
		}

		void brute_move_zero_end(){
		
			std::vector<int> temp;
		
			for(size_t i = 0; i < vec.size(); ++i){
				
				if(vec[i] > 0)
					temp.push_back(vec[i]);
			}		

			size_t i;

			for(i = 0; i < temp.size(); ++i){
					
				vec[i] = temp[i];
			}

			for(; i < vec.size(); ++i){
			
				vec[i] = 0;
			}
		}
};


std::ostream& operator<<(std::ostream& os, const move_zero_end& rhs){

	for(size_t i = 0; i < rhs.vec.size(); ++i){

		os << rhs.vec[i] <<" ";
	}
	
	os << std::endl;

	return os;
}

int main(void){
	
	std::cout <<"Programe started succesfully" << std::endl;	

	std::cout << std::endl;

	std::vector<size_t> vec = {0,0,0,0,0,0,0, 1 ,0 ,2 ,3 ,0 ,4 ,0 ,1, 4, 5,8,9,100, 6, 4, 5,6, 4,4 , 4,5 ,3,5, 5,6, 3, 5,3, 4, 6, 4};

	move_zero_end obj1(vec);
	
	obj1.better_approach();

	std::cout << obj1 << std::endl;
	
	std::cout <<"Programe terminated succesfully" << std::endl;

	return EXIT_SUCCESS;
}
