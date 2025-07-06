#include <iostream>
#include <cstdlib>
#include <vector>

class max_sub_array{
    private:
        std::vector<int> vec;
    public:
        max_sub_array(std::vector<int>& ref_vec) : vec(ref_vec){ }

    void brute(){
        int result = 0;
        int max_result = 0;

        for(int i = 0; i < vec.size(); ++i){
            result = 0;
            for(int j = i; j < vec.size(); ++j){
                result = result + vec[j];
                max_result = std::max(max_result, result);
           }
        } 
        std::cout <<"Maximum subarray sum is = " << max_result << std::endl;
    }

    void better(){
        int max_sum = 0;
        int sum = 0;
        for(size_t i = 0; i < vec.size(); ++i){
            sum = sum + vec[i];
            if(sum < 0){
                sum = 0;
            }
            max_sum = std::max(max_sum, sum);
        }
        std::cout <<"Maximum sum is = " << max_sum << std::endl;
    }

    void optimal(){
        
    }

};

int main(void){
    std::vector<int> vec = {-2,1,-3,4,-1,2,1,-5,4};
    max_sub_array obj(vec);
    obj.better();
    std::cout <<"Programe terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}