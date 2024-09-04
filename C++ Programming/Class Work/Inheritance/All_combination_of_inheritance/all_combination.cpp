#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <typeinfo>

class base{
    public:
        void base_specific_function(void){
            std::cout <<"base::base_specific_function()" << std::endl;
        }

        void o_function(){
            std::cout <<"base::base_function_overRidden" <<std::endl;
        }

        virtual void o_virtual(){
            std::cout <<"base::base_virtuall" << std::endl;
        }
};

class derived : public base{
    public:
        void derived_specific_function(void){
            std::cout <<"derived::derived_specific_function()" << std::endl;
        }

        void o_function(){
            std::cout <<"derived::derived_function_overRidden" <<std::endl;
        }

        void o_virtual(){
            std::cout <<"derived::derived_virtual" << std::endl;
        }
};

void test_run(void);

int main(void){
    test_run();
    std::cout <<"Programme terminated sucessfully";
    return 0;
}   

void test_run(void){
    base* pb = 0;
    derived* pd = 0;
    derived d;

    pb = &d;
    pd = &d;

    /* Calling base specific function   */
    pb->base_specific_function();
    /* calling overridden function from derived class virtual */
    pb->o_virtual();
    /*  calling overridden function but not virtual*/
    pb->o_function();


    /* calling derived specific function using base class pointer   */
    if(typeid(*pb) == typeid(d))
        reinterpret_cast<derived*>(pb)->derived_specific_function();

    /*  Dervied */
    pd->base_specific_function();   /* Derived  */
    pd->derived_specific_function();    /* Derived  */
    pd->o_function();   /* Derived  */
    pd->o_virtual(); /*Derived*/
    pd->base::base_specific_function();
}