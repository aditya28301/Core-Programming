#include <iostream>
#include <typeinfo>

class base{
    public:
        void base_function(){
            std::cout <<"base class function called this = " << typeid(*this).name() << std::endl;
        }

        virtual void overidden_function(){
            std::cout <<"base virtual overidden function" << std::endl;
        }
};

class mid_left : virtual public base{
    void mid_left_function(){
        std::cout <<"base class function called" << std::endl;
    }

    virtual void overidden_function(){
        std::cout <<"mid left virtual overidden function" << std::endl;
    }
};

class mid_right : virtual public base{
    void mid_right_function(){
        std::cout <<"base class function called" << std::endl;
    }

    virtual void overidden_function(){
        std::cout <<"mid right virtual overidden function" << std::endl;
    }
};

class low : public mid_left, public mid_right{
    void low_function(){
        std::cout <<"base class function called" << std::endl;
    }

    virtual void overidden_function(){
        std::cout <<"low virtual overidden function" << std::endl;
    }
};

int main(void){
    base* ptr = new low();
    ptr->base_function();
    ptr->overidden_function();
    low obj;
    obj.base_function();
    std::cout <<"Programe terminated successfully" << std::endl;
    return EXIT_SUCCESS;
}