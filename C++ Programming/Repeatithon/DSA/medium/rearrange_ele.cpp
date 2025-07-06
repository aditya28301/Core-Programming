#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class re_arrange{
	
	private:
		std::vector<int> vec;

	public:
		re_arrange(std::vector<int>& ref_vec) : vec(ref_vec){ }

		void brute_force_approach(){

			std::vector<int> pos;
			std::vector<int> neg;

			for(int i = 0; i < vec.size(); ++i){
			
				if(vec[i] > 0)
					pos.push_back(vec[i]);
				else 
					neg.push_back(vec[i]);			
			}


			for(int i = 0; i < vec.size()/2; i++){

				vec[2 * i] = pos[i];
				vec[2 * i + 1] = neg[i]; 
			}

		}

		std::vector<int> optimal_approach(){

			int pos = 0;
			int neg = 1;
	
			std::vector<int> ans(vec.size(), 0);

			for(size_t i = 0; i < vec.size(); ++i){
				
				if(vec[i] >= 0){
					ans[pos] = vec[i];
					pos = pos + 2;
				}
				else{
					ans[neg] = vec[i];
					neg = neg + 2;
				}
			}

			return ans;
		}

		void show(){
		
			for(size_t i = 0; i < vec.size(); ++i){
				std::cout <<vec[i] <<" ";	
			}
		}
};

int main(void){

	std::cout <<"---------------------------------------Programe started succesfully-------------------------------------------" <<std::endl;

	std::cout << std::endl;

	std::vector<int> ans;

	std::vector<int> vec = {1,2,-4,-5};
	
	re_arrange obj1(vec);
	
	ans = obj1.optimal_approach();

	re_arrange obj2(ans);

	obj2.show();

	std::cout << std::endl;
	
	std::cout <<"--------------------------------------Programe terminated succesfully----------------------------------------" <<std::endl;	
	return EXIT_SUCCESS;
}
