#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

class buy_and_sell{

	private:
		std::vector<int> vec;
	public:
		buy_and_sell(std::vector<int>& ref_vec) : vec(ref_vec){}

		ssize_t better_buy_and_sell(){
			
			size_t sum = 0;
			size_t max_sum = 0;
			size_t i, j;

			i = 0;
			j = i + 1;

			while(i < vec.size() - 1 && j < vec.size()){
				
				j = i + 1;

				if(vec[j] < vec[i]){
					
					++i;
				}	
				else{
					sum = vec[j] - vec[i];
					max_sum = std::max(max_sum, sum);
					++j;
				}					
			}
			return max_sum;
		}

		ssize_t brute_buy_and_sell(){

			size_t sum = 0;
			size_t max_sum = 0;

			for(size_t i = 0; i < vec.size() - 2; ++i){
			
				for(size_t j = i + 1; j < vec.size(); ++j){
				
					if(vec[j] > vec[i])
						sum = vec[j] - vec[i];
					
					max_sum = std::max(max_sum, sum);
				}	
			}		
			
			return max_sum;
		
		}
};

int main(void){
		
	std::cout <<"------------------------programe started successfully---------------------" << std::endl;
	
	std::vector<int> vec;

	// Generate 1000 prices randomly in [0,1000]
	for(int i=0;i<1000000;++i) vec.push_back(rand()%1001);

	ssize_t max_profit;

	buy_and_sell obj1(vec);
		
	max_profit = obj1.brute_buy_and_sell();	
	
	std::cout <<"Maximum profit is =" << max_profit << std::endl;
		
	std::cout <<"------------------------programe terminated succesfully--------------------" << std::endl;
	
	return EXIT_SUCCESS;
}
