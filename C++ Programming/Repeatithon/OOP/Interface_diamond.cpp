#include <iostream>
#include <cstdlib>

class base{
    public:
        virtual void function() = 0;
};

class mid_left : public base{
    public:
        virtual void function() = 0;
};

class mid_right : public base{
    public:
        virtual void function() = 0;
};

class derived : public mid_left, public mid_right{
    public:
        void function(){
            std::cout <<"Derived class function is called" << std::endl;
        }
};

int main(void){
    derived obj;
    dynamic_cast<mid_left*>(&obj)->function(); 
    dynamic_cast<mid_right*>(&obj)->function();
    return EXIT_SUCCESS;
}