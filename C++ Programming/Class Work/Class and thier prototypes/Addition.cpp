#include <cstdio>

class Add{
    private:
        int number1;
        int number2;
        int sum;
    public:
        void set_value(int a, int b){
            this->number1 = a;
            this->number2 = b;
         }

        int get_add_result(void){
            return number1 + number2;
        }
};

int main(void){
    int sum;
    Add a;
    a.set_value(100, 200);
    sum = a.get_add_result();
    printf("value = %d\n", sum);
    return 0;
}