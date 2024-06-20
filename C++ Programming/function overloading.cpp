#include <cstdio>

class fOverload{
    private:
        int a;
        int b;
    public:
        fOverload(): a(10), b(10){};
        int fun(int, int);
        int fun(float, float);
};  

int fOverload::fun(int a, int b){
    printf("int\n");
    return 3;
}
int fOverload::fun(float a, float b){
    printf("float");
    return 2;
}

int main(void){
fOverload f;
int num;
num = f.fun(10, 20);
num = f.fun(10.0f, 20.0f);
return 0;
}