#include <iostream>

class Test
{
    private:
        int a;
        int b;
        float c;

    public:
        int d;
        int e;
        int f;
};

int main(void){

    Test t1;
    Test t2;

    /**/
        t1.a = 10;
        t1.b  = 'a';
        t1.c = 3.4f;

    /*
    t2.d = 100;
    t2.e = 200;
    t2.f = 300;
    */

    return 0;
}