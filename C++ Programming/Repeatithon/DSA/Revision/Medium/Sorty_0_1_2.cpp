#include <iostream>
#include <cstdlib>
#include <vector>

class sort_n{
    friend std::ostream& operator<<(std::ostream& os, const sort_n& rhs);
    private:
        std::vector<int> vec;

    public:
        sort_n(std::vector<int>& ref_vec) : vec(ref_vec) { }

        void swap(int& first, int& second){
            int temp = 0;
            temp = first;
            first = second;
            second = temp;
        }

        void f_sort(){
            int low  = 0;
            int high = vec.size() - 1;
            int mid  = low;

            while(mid <= high){        
                if(vec[mid] == 0){
                    swap(vec[low], vec[mid]);
                    ++mid;
                    ++low;               
                }
                else if(vec[mid] == 1){
                    ++mid;
                }   
                else{
                    swap(vec[mid], vec[high]);
                    --high;
                }
            }   
       }
};

std::ostream& operator<<(std::ostream& os, const sort_n& rhs){
    for(size_t i = 0; i < rhs.vec.size(); ++i){
        os << rhs.vec[i] <<" ";
    }
    return os;
}

int main(void){
    std::vector<int> vec = {2,0,2,1,1,0};
    sort_n obj(vec);
    obj.f_sort();
    std::cout << obj << std::endl;
    std::cout <<"Programe terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}