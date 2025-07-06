#include <iostream>
#include <cstdlib>
#include <vector>

class buy_sell_stock{
    private:
        std::vector<int> vec;
    public:
        buy_sell_stock(std::vector<int>& ref_vec) : vec(ref_vec){ }

        void brute(){
            int sum = 0;
            int max_sum = 0;

            for(int i = 0; i < vec.size(); ++i){
                for(int j = i + 1; j < vec.size(); ++j){
                    if(vec[i] > vec[j]){
                        break;
                    }
                    sum = vec[j] - vec[i];
                    max_sum = std::max(max_sum, sum);                
                }
            }

            std::cout <<"Maximum profit = " << max_sum << std::endl;
        }

        void optimal(){
            int min = vec[0];
            int max_profit = 0;
            int cost = 0;

            for(int i = 0; i < vec.size(); ++i){
                cost = vec[i] - min;
                max_profit = std::max(max_profit, cost);
                min = std::min(vec[i], min);            
            }
            std::cout <<"Maximum profit is = " << max_profit << std::endl;
        }
};

int main(void){
    std::vector<int> vec = {7,1,5,3,6,4};
    buy_sell_stock obj(vec);
    obj.optimal();
    std::cout <<"Programe terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}