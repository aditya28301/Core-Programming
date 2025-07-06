#include <iostream>
#include <cstdlib>

class base{
    private:
        int base_data;
    public:
        base() :  base_data(100){
            std::cout <<"base class constructor is called here" << std::endl;
        }
        void base_specific_function(){
            std::cout <<"Base specific function" << std::endl;
        }

        virtual void overidden_function(){
            std::cout <<"Overidden_function" << std::endl;
        }

        void overidden_not_virtual(){
            std::cout <<"Overidden not virtual function" << std::endl;
        }
};

class derived : public base{
    private:
        int derived_data;
    public:
        derived() : base(), derived_data(1000){
            std::cout <<"Derived class constructor" << std::endl;
        }

        void derived_specific_function(){
            std::cout <<"Derived specific function" << std::endl;
        }

        virtual void overidden_function(){
            std::cout <<"Overidden function" << std::endl;
        }

        void overidden_not_virtual(){
            std::cout <<"Overidden not virtual" << std::endl;
        }
};

int main(void){

    base* ptr = new derived();
    ptr->base_specific_function();
    ptr->::base::overidden_function();
    ptr->overidden_not_virtual();
    
    dynamic_cast<derived*>(ptr)->derived_specific_function();
    ptr->overidden_function();
    dynamic_cast<derived*>(ptr)->overidden_not_virtual();


    ptr = new base();
    ptr->base_specific_function();
    ptr->::base::overidden_function();
    ptr->overidden_not_virtual();   
    dynamic_cast<derived*>(ptr)->derived_specific_function();
    ptr->overidden_function();
    dynamic_cast<derived*>(ptr)->overidden_not_virtual();

    std::cout <<"Program terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}