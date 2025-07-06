#include <iostream>

class base{
    private:
        int a;
        int b;

    public:
        base() { std::cout <<"Base class constructor" << std::endl;}

        virtual void func() const{
            std::cout <<"Base class override function" << std::endl;
        }
};

class derived : public base{
    public:
        derived() : base(){
            std::cout <<"Derived class constructor is called here" << std::endl;
        }

        void func() const override{
            std::cout <<"Base class override function called" << std::endl;
        }
};

int main(void){
    base* b_ptr = new derived;
    b_ptr->func();
    return EXIT_SUCCESS;
}