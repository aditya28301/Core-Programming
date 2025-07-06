#include <iostream>
#include <cstdlib>

class A{
    public:
        virtual void function(){
            std::cout<<"Class a function is called" << std::endl;
        }
};

class B : public A{
    public:
    virtual void function(){
        std::cout<<"Class a function is called" << std::endl;
    }

};

class D : public B{
    public:
    void function(){
        std::cout<<"Derived Class a function is called" << std::endl;
    }
};

int main(void){
    A* ptr = new D();
    ptr->function();
    dynamic_cast<B*>(ptr)->B::function();
    return EXIT_SUCCESS;
}