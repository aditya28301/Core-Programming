#include <cstdio>

class calling_object{
    private:
        int number1;
        int number2;
        int subtraction;
    public:
        void set_value(){
            this->number1 = 10;
            this->number2 = 20;
        }

        int get_sub(){
            subtraction = number1 - number2;
            return subtraction;
        }
};

int main(void){
    calling_object c1;
    int sub;

    c1.set_value();
    sub = c1.get_sub();
    printf("subtraction = %d\n", sub);
    return (0);
}