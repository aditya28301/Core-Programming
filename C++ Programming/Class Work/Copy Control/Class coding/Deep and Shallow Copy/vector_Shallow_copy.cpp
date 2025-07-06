#include <iostream>
#include <cstdlib>
#include <typeinfo>

struct count_maintain{
    int* ptr;
    int ref_count;
};

class D_vector{
    private:
        struct count_maintain* ref_ptr;
        int size;

    public:
        D_vector() : size(0){
            ref_ptr = (struct count_maintain*)malloc(sizeof(struct count_maintain));
            if(ref_ptr == 0){
                std::cout <<"Error in reallocating the meomary" << std::endl;
                exit(EXIT_FAILURE);
            }
            ref_ptr->ref_count = 1;
        }

        D_vector(const D_vector& rhs){
            if(this != &rhs){
                ref_ptr = rhs.ref_ptr;
                size = rhs.size;
                ref_ptr->ref_count = ref_ptr->ref_count + 1;
            }
        }

        ~D_vector(){
            std::cout <<"reference_count = " << ref_ptr->ref_count << std::endl;
            ref_ptr->ref_count = ref_ptr->ref_count - 1;
            if(ref_ptr->ref_count == 0){
                std::cout <<"reference_count = " << ref_ptr->ref_count << std::endl;
                free(ref_ptr->ptr);
                free(ref_ptr);
                ref_ptr = 0;
            }
        }

        D_vector& operator=(const D_vector& rhs){
            if(this != &rhs){
                ref_ptr->ref_count = ref_ptr->ref_count - 1;
                if(ref_ptr->ref_count == 0){
                    ref_ptr = rhs.ref_ptr;
                    size = rhs.size;
                    ref_ptr->ref_count = ref_ptr->ref_count + 1;
                }
            }
            return *this;
        }

        void push_back(int new_data){
            int new_required_byte = sizeof(int) * (size + 1);
            ref_ptr->ptr = (int*)realloc(ref_ptr->ptr, new_required_byte);
            size = size + 1;
            ref_ptr->ptr[size - 1] = new_data;
        }

        void show(){
            for(size_t i =0 ; i < size; ++i){
                std::cout <<ref_ptr->ptr[i] <<" ";
            }
            std::cout << std::endl;
        }
};

int main(void){
    
    D_vector obj1;
    obj1.push_back(100);
    obj1.push_back(200);
    obj1.push_back(300);
    
    std::cout <<"Showing object_1 data" << std::endl;
    obj1.show();
    D_vector obj2(obj1);
    std::cout <<"Showing Object_2 Copy constructor data" << std::endl;
    obj2.show();

    // Copy assignment operator
    D_vector obj3;
    obj3.push_back(1000);
    obj3.push_back(2000);
    obj3.push_back(3000);
    std::cout <<"Showing Object_3 data" << std::endl;
    obj3.show();

    D_vector obj4;
    obj4 = obj3;
    std::cout <<"Showing object_4 Copy assignment data" << std::endl; 
    obj4.show();

    std::cout <<"Programe terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}