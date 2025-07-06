#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <unordered_map>

class majority{
    private:
        std::vector<int> vec;
    public:
        majority(std::vector<int>& ref_vec) : vec(ref_vec){}
        
        void find_majority(){
            std::sort(vec.begin(), vec.end());

            size_t track = 0;
            size_t count = 1;
            size_t loop = track + 1;

            while(loop < vec.size()){
                if(vec[loop] == vec[loop - 1]){
                    ++count;
                }
                if(vec[loop] != vec[loop - 1]){
                    count = 1;
                }

                if(count > vec.size() / 2){
                    std::cout <<"majority element = " << vec[loop] << std::endl;
                    return;
                }
                ++loop;
            }       
        }

        void better(){
            std::unordered_map<int, int> mmap;

            for(size_t i = 0; i < vec.size(); ++i){
                mmap[vec[i]]++;
            }

            for(std::unordered_map<int, int>::iterator it = mmap.begin(); it != mmap.end(); ++it){      
                if(it->second > vec.size() / 2){
                    std::cout <<"Majority_element = " << it->first << std::endl;
                }
            }
        }

        void optimal(){
            int count = 0;
            int current_element = 0;
            int element = vec[0];

            while(current_element < vec.size()){
                if(vec[current_element] == element){
                    ++count;
                }
                else{
                    --count;
                }
    
                if(count == 0){
                    element = vec[current_element];
                    count = 1;
                }
                ++current_element;
            }
                int verify_count = 0;
                for(int i = 0; i < vec.size(); ++i){
                    if(vec[i] == element){
                        ++verify_count;
                    }       
                }

                if(verify_count > vec.size() / 2){
                    std::cout <<"YES = " << element << std::endl;
                }
                else{
                    std::cout <<"NO = " << element << std::endl;
                }
        }
};

int main(void){
    std::vector<int> vec = {2,2,1,1,1,2,2};
    majority obj(vec);
    obj.optimal();
    std::cout <<"Programe terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}