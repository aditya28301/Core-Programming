#include <cstdio>

class construct_param{

    private:
        int a;
        int b;
    public:
    construct_param(int n1, int n2){
        this->a = n1;
        this->b = n2;
    }

    int get_a(void){
        return a;
    };

    int get_b(void){
        return b;
    }
};

int main(void){
    construct_param p(10,20);
    printf("value b = %d\n", p.get_b());
    printf("value a = %d\n", p.get_a());
    return 0;
}