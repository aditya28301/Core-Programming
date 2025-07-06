#include <iostream>
#include <cstdlib>
#include <typeinfo>

class D_vector{
    private:
        int* ptr;
        int size;
        int id;
        static int count;

    public:
        D_vector() : ptr(0), size(0){
        id = ++count;
        }
        ~D_vector(){
            std::cout <<"Destrctor count = " << id << std::endl;
            free(ptr);
            ptr = 0;
        }
    void push_back(int new_data){
        size_t new_required_byte = sizeof(int) * (size + 1);
        ptr = (int*)realloc(ptr, new_required_byte);
        if(ptr == 0){
            std::cout <<"Error in resizing the meomary" << std::endl;
            exit(EXIT_FAILURE);
        }
        size = size + 1;
        ptr[size - 1] = new_data;
    }
    void show(){
        for(size_t i =0 ; i < size; ++i){
            std::cout <<ptr[i] <<" ";
        }
        std::cout << std::endl;
    }

    D_vector(D_vector& ref_obj){
        id = ++count;
        if(this != &ref_obj){
            ptr = new int[ref_obj.size];
            for(size_t i = 0; i < ref_obj.size; ++i){
                ptr[i] = ref_obj.ptr[i];
            }
            size = ref_obj.size;
        }   
    }

    D_vector& operator=(const D_vector& other){
        if(this != &other){
            free(ptr);
            ptr = new int[size];
            for(size_t i = 0; i < other.size; ++i){
                ptr[i] = other.ptr[i];
            }
        }
        return *this;
    }       
};

int D_vector::count = 0;

int main(void){
    
    D_vector obj;
    obj.push_back(10);
    obj.push_back(20);

    std::cout  <<"Regular Object" << std::endl;
    obj.show();

    D_vector obj2(obj);
    std::cout <<"Copy constructor" << std::endl;
    obj2.show();

    D_vector obj3;
    obj3.push_back(100);
    obj3.push_back(200);
    obj3.push_back(300);

    D_vector obj4;

    std::cout <<"Copy assignment operator" << std::endl;
    obj4 = obj3;
    std::cout <<"Programe terminated sucesfully" << std::endl;
    return EXIT_SUCCESS;
}