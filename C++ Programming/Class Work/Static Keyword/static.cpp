#include <cstdio>
#include <cstdlib>
#include <iostream>

class test{
    private:
        int a;
        int b;
        static int c;
    public:
        void func(){
            std::cout <<"Non static function = " << a << b << c << std::endl;
        }

        static void func2(){
            std::cout <<"Static function = " << c << std::endl;
        }
};

int test::c = 100;

// int main(void){
//     test t1, t2;
//     //test::func();   //It shoule be error becasue you cant access non-static member function outside the class using class name qualifier
//     test::func2();  // It should be accssible outside the classs beacause static memeber can be acceess outside the class usign class name qualifier
    
//     t1.func();      //It can be accessible using the object and its have refernce of calling object   
//     t2.func2();     // Static member function can be accessed using the class name qulaifier and object also
    
//     return EXIT_SUCCESS;
// }
