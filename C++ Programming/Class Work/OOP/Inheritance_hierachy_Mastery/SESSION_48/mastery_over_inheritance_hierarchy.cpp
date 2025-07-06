#include <iostream> 

class B1{
    public: 
        virtual void f(){
            std::cout << "B1::f()" << std::endl; 
        }

        void g1(){
            std::cout << "B1::g1()" << std::endl; 
        }
}; 

class B2{
    public: 
        virtual void f(){
            std::cout << "B2::f()" << std::endl; 
        }

        void g2(){
            std::cout << "B2::g2()" << std::endl; 
        }
}; 

class B3{
    public: 
        virtual void f(){
            std::cout << "B3::f()" << std::endl; 
        }

        void g3(){
            std::cout << "B3::g3()" << std::endl; 
        }
}; 

class B4{
    public: 
        virtual void f(){
            std::cout << "B4::f()" << std::endl; 
        }

        void g4(){
            std::cout << "B4::g4()" << std::endl; 
        }
}; 

class B11 : public B1, public B2{
    public: 
        void f(){
            std::cout << "B11:f()" << std::endl; 
        }

        void g11(){
            std::cout << "B11:g11()" << std::endl; 
        } 
}; 

class B22 : public B3, public B4{
    public: 
        void f(){
            std::cout << "B22:f()" << std::endl; 
        }

        void g22(){
            std::cout << "B22:g22()" << std::endl; 
        } 
};

class D : public B11, public B22{
    public: 
        void f(){
            std::cout << "D:f()" << std::endl; 
        }

        void g(){
            std::cout << "D:g()" << std::endl; 
        }
}; 

void test_B1(void); 

int main(void){
    test_B1(); 
    return EXIT_SUCCESS;
}

void test_B1(void){
    B1* pB1 = new D; 
    
    pB1->::B1::f();
    dynamic_cast<B2*>(pB1)->::B2::f();
    dynamic_cast<B3*>(pB1)->::B3::f();
    dynamic_cast<B4*>(pB1)->::B4::f();
    dynamic_cast<B11*>(pB1)->::B11::f();
    dynamic_cast<B22*>(pB1)->::B22::f();

    pB1->g1();
    dynamic_cast<B2*>(pB1)->g2();
    dynamic_cast<B3*>(pB1)->g3();   
    dynamic_cast<B4*>(pB1)->g4();
    dynamic_cast<B11*>(pB1)->g11();
    dynamic_cast<B22*>(pB1)->g22();
    dynamic_cast<D*>(pB1)->::D::g();

    delete pB1; 
    pB1 = 0; 
}