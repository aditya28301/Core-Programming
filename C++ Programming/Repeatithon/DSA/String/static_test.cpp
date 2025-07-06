#include <iostream>
#include <cstdlib>

class static_test{
    private:
        int a;
        int b;
    public:
        static_test() : a(100), b(200) { }

        void call_function(){
            get_data();     // But in a member function we can call static function
        }

        static void get_data(){
            std::cout << a << std::endl; // Non static member cant be access in a static function
        }

};

int main(void){

    return EXIT_SUCCESS;
}