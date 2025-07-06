#include <iostream>

class base{
    int data;
    public:
        base() : data(100){
            std::cout <<"Base class constructor called" << std::endl;
        }

        void base_specific_function(){
            std::cout <<"base class specific function() = " << data << std::endl;
        }
        virtual void overidden_function(){
            std::cout <<"Overidden base class function is called = " << data << std::endl;
        }

        void not_virtual_function(){
            std::cout <<"Base class overidden not virtual function called = " << data << std::endl;
        }
};

class base_2{
    int data;

    public:
        base_2() :  data(100){
            std::cout <<"base_2 class constructor is called here = " << data << std::endl;
        }

        void base_2_specific_function(){
            std::cout <<"base_2 specific function is called = " << data << std::endl;
        }

        virtual void overidden_function(){
            std::cout <<"base_2 overidden virtual function is called here = " << data << std::endl;
        }

        void not_virtual_function(){
            std::cout <<"base_2 not virtual function is called = " << data << std::endl;
        }
};

class derived : public base, public base_2{
    int data;
        
    public:
        derived() : data(200){
            std::cout <<"Derived class function is called" << data << std::endl;
        }

        void derived_specific_function(){
            std::cout <<"Derived specific function is called = " << data << std::endl;
        }

        void overidden_function(){
            std::cout <<"derived overidden fucntion is called = " << data << std::endl;
        }

        void not_virtual_function(){
            std::cout <<"Overidden not virtual fucntion called = " << data << std::endl;
        }
};

int main(void){
    base* ptr = new derived();  

    std::cout <<"base class pointer contain derived class object" << std::endl;
    // Base class member function is called
    ptr->base_specific_function();
    ptr->::base::overidden_function();
    ptr->not_virtual_function();
    
    // base_2 class member function is called
    dynamic_cast<base_2*>(dynamic_cast<derived*>(ptr))->base_2_specific_function();
    dynamic_cast<base_2*>(dynamic_cast<derived*>(ptr))->base_2_specific_function();     // not sure
    dynamic_cast<base_2*>(dynamic_cast<derived*>(ptr))->overidden_function();
    dynamic_cast<base_2*>(dynamic_cast<derived*>(ptr))->not_virtual_function();

    // derived class memebr function

    dynamic_cast<derived*>(ptr)->derived_specific_function();
    ptr->overidden_function();
    dynamic_cast<derived*>(ptr)->not_virtual_function();

    std::cout <<"Derived class pointer contain derived class object" << std::endl;
    // Calling all function from base class pointer and base class object
    
    base* ptr_3  = new base();    
    
    ptr_3->base_specific_function();
    ptr_3->::base::overidden_function();  
    ptr_3->not_virtual_function();

    std::cout <<"Derived class pointer contain derived class object" << std::endl;
    
    // Calling all function from derived class pointer and derived class object
    derived* ptr_2 = new derived();

    // base class
    dynamic_cast<base*>(ptr_2)->base_specific_function();
    dynamic_cast<base*>(ptr_2)->::base::overidden_function();
    dynamic_cast<base*>(ptr_2)->not_virtual_function();

    //base_2

    dynamic_cast<base_2*>(ptr_2)->base_2_specific_function(); 
    static_cast<base_2*>(ptr_2)->::base_2::overidden_function();    //  Error
    dynamic_cast<base_2*>(ptr_2)->not_virtual_function();

    // derived
    ptr_2->derived_specific_function();
    ptr_2->overidden_function();
    ptr_2->not_virtual_function();

    std::cout <<"Programe terminated successfully" << std::endl;
    return EXIT_SUCCESS;
}

