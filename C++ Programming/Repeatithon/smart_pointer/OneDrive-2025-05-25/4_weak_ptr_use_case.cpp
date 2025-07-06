#include <iostream> 
#include <memory> 

class B;    // Declaration of class B 

class A
{
    private: 
       
        std::shared_ptr<B> sP1;

    public:
        A() {  std::cout << "A()" << std::endl; }
        ~A() { std::cout << "~A()" << std::endl; }

        void setShared(std::shared_ptr<B>& p)
        {
            sP1 = p;
        }
};

class B
{
    private: 
        std::shared_ptr<A> sP1;

    public:
        B() {  std::cout << "B()" << std::endl; }
        ~B() { std::cout << "~B()" << std::endl; }

        void setShared(std::shared_ptr<A>& p)
        {
            sP1 = p;
        }
};

void test(void); 

int main()
{
    test(); 

    // the program will continue 
    // for foreseeable duration 
//-----------------------------------------------------
    return 0;  
}

void test(void){
    std::shared_ptr<A> aPtr(new A);
    std::shared_ptr<B> bPtr(new B);
    aPtr->setShared(bPtr); 
    bPtr->setShared(aPtr);
} 