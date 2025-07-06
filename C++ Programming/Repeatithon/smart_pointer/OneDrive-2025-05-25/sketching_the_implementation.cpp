#include <iostream> 

namespace cpa{
    template <typename T> 
    class T_ptr{
        private: 
            T* p; 
            std::size_t ref_cnt; 

            T_ptr(T _val) : p(new T(_val)), ref_cnt(1){

            }

            ~T_ptr(){
                delete ptr; 
                ptr = 0; 
            }
    }; 

    template <typename T> 
    class shared_ptr{
        private: 
            T_ptr* ptr; 
        public: 
            shared_ptr(T val) : new T_ptr<T>(val){

            }

            shared_ptr(const shared_ptr<T>& other){
                // copy constructor 
                this->ptr = other.ptr; 
                this->ptr->ref_cnt += 1; 
                return *this; 
            }

            shared_ptr<T>& operator=(const shared_ptr<T>& other){
                // copy assignment operator 
                if(this != &other){
                    this->ptr->ref_cnt -= 1; 
                    if(this->ptr->ref_cnt == 0)
                        delete this->ptr; 
                    this->ptr = other.ptr; 
                    this->ptr->ref_cnt += 1;  
                }
                return *this;
            }

            ~shared_ptr(){
                if(--this->ptr->ref_cnt == 0)
                    delete this->ptr; 
            }

            T& operator*(){
                return *(this->ptr->p); 
            }

            T* operator->(){
                return this->ptr->p;
            }
    }; 
}