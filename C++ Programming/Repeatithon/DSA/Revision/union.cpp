#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>

class find_union{
	
	private:
		std::vector<int> vec1;
		std::vector<int> vec2;
	public:
	
	find_union(std::vector<int>& ref_vec1, std::vector<int>& ref_vec2): vec1(ref_vec1), vec2(ref_vec2){

	}

	std::vector<int> FindUnion(){
		
		size_t i = 0;
		size_t j = 0;
		
		std::vector<int> temp;

		while(i < vec1.size() && j < vec2.size()){
		
			if(vec1[i] < vec2[j]){
				
				temp.push_back(vec1[i]);
				++i;
			}
			else{
				temp.push_back(vec2[j]);
				++j;		
			}
		} 

		while(i < vec1.size()){
			temp.push_back(vec1[i]);
			++i;
		}
		
		while(j < vec2.size()){
			temp.push_back(vec2[j]);	
			++j;
		}

		return temp;
	}

};

void show(std::vector<int>& vec){
	
	for(size_t i =0 ; i < vec.size(); ++i){

		std::cout << vec[i] <<" ";
	}
	
	std::cout << std::endl;
}
int main(void){

	std::cout <<"------------------------Porgrame started succsfully-----------------------------" << std::endl;
	
	std::cout << std::endl;

	std::vector<int> vec1 = {1, 3, 5, 7, 9, 11};
	
	std::vector<int> vec2 = {2, 4, 6, 8, 10};

	std::vector<int> temp;

	find_union obj1(vec1, vec2);

	temp = obj1.FindUnion();
	
	show(temp);
	
	std::cout << std::endl;

	std::cout <<"------------------------Porgarmme terminated succesfully-------------------------" << std::endl;
	
	return EXIT_SUCCESS;
}
	
