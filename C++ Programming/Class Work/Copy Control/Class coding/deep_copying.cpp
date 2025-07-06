#include <iostream>

class HasPtr{
    private:
        int n;
        int* ptr;
    public:
        HasPtr(int _n, int _val) : n(_n), ptr(new int(_val)){
        }

        ~HasPtr(){
            delete ptr;
        }

        HasPtr(const HasPtr& other) : n(other.n), ptr(new int(*other.ptr)){
        }

        HasPtr& operator=(const HasPtr& other){
            if(this != &other){

                n = other.n;
                *this->ptr = *other.ptr;
            }

            return *this;
        }

        void setn(int new_n){
            n = new_n;
        }

        int* get_ptr() const{
            return ptr;
        }

        int getptr_val() const{
            return *ptr;
        }

        void setptr_val(int new_val){
            *this->ptr = new_val;
        }
};

int main(void){
    array a(10);
    a.
    return EXIT_SUCCESS;
}
