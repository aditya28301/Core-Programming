#include <iostream>
#include <cstdlib>
#include <vector>
#include <unordered_map>

class two_sum{
    private:    
        std::vector<int> vec;
        size_t target;

    public:
        two_sum(std::vector<int>& ref_vec, size_t _target) : vec(ref_vec), target(_target){ 
        }

    void find_target_value(){
        std::unordered_map<int, size_t> mmap;
        size_t num = 0;
        size_t check_if = 0;
        for(size_t i = 0; i < vec.size(); ++i){
            num = vec[i];
            check_if = target - num;
            std::unordered_map<int, size_t>::iterator it = mmap.find(check_if);
            if(it != mmap.end()){
                std::cout <<"YES" << std::endl;
                std::cout <<"index_1 = " << it->second << std::endl << "index_2 = " << i << std::endl; 
            }      
            mmap[num] = i;
        }
    }

        void find_target_value_2(){
            size_t left = 0;
            size_t right = vec.size() - 1;
            size_t sum = 0;

            while(left < right){
                sum = vec[left] + vec[right];
                if(sum == target){
                    std::cout <<"YES" << std::endl;
                    std::cout <<"INDEX_1 = " << left << std::endl
                              <<"INDEX_2 = " << right << std::endl; 
                    return;
                }
                else if(sum < target){
                    ++left;
                }
                else{
                    --right;
                }
            }
            std::cout <<"NO" << std::endl;
        }
};

int main(void){
    std::vector<int> vec {2,6,5,8,11};
    two_sum obj(vec, 14);
    obj.find_target_value_2();
    return EXIT_SUCCESS;
}