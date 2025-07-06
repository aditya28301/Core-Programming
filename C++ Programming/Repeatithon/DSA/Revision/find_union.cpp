#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class find_union{

	private:
		std::vector<int> vec1;
		std::vector<int> vec2;
	
	public:

		find_union(std::vector<int>& ref_vec1, std::vector<int>& ref_vec2) : vec1(ref_vec1), vec2(ref_vec2) {

		}
 	
		std::vector<int> union_vec;

		std::vector<int> optimal_approach() {
			
			size_t i = 0;
			size_t j = 0;

			for( ;i < vec1.size() && j < vec2.size(); ){ 
			
				if(vec1[i] <= vec2[j]){
				
					if(union_vec.size() == 0 || union_vec.back() != vec1[i]){
						union_vec.push_back(vec1[i]);
					}
					
					++i;
				}

				else{
					if(union_vec.size() == 0 || union_vec.back() != vec2[j]){
						union_vec.push_back(vec2[j]);
					}
					
					++j;
				}
			}

			while(i < vec1.size()){
				
				union_vec.push_back(vec1[i]);
				++i;
			}

			while(j < vec2.size()){
				
				union_vec.push_back(vec2[j]);
				++j;
			}

			return union_vec;	
			
		}
		
		void show(std::vector<int>& vec){
			
			for(size_t i = 0; i < vec.size(); ++i){
				std::cout << vec[i] <<" ";
			}
		} 	
};

int main(void){

	std::cout <<"--------------------------------Programe started sucesfully-------------------------------------" << std::endl;
	
	std::cout << std::endl;

	std::vector<int> vec1 = {1 ,2 ,3 ,4 ,5 ,6 ,7};

	std::vector<int> vec2 = {1, 2,  3, 4, 5};
	
	std::vector<int> temp;

	find_union f1(vec1, vec2);
	
	temp = f1.optimal_approach();
	
	f1.show(temp);
	
	std::cout << std::endl;
	
	std::cout << std::endl;

	std::cout <<"------------------------------------Programe end succesfully------------------------------------------" << std::endl;	
	
	return EXIT_SUCCESS;
}

void test(void){

}
