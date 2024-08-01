#include <cstdio>

class construct{
    private:
        float a;
        float b;
    public:
        // initiliazation syntax Default constrctor
        construct(): a(10.0), b(20.0){};

        // member function
        float get_a(){
            return a;
        }

        float get_b(){
            return b;
        }
};

int main(void){
    float num1;
    float num2;

    construct c1;
    num1 = c1.get_a();
    num2 = c1.get_b();
    
    printf("num1 = %.3f, num2 = %.3f\n", num1, num2);
    return 0;
}