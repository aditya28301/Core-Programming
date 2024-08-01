#include <cstdlib>
#include <cstdio>

class complex{
    private:
        double real;
        double img;

    public:
        complex() : real(0.0), img(0.0){}
        complex(double real_, double img_) : real(real_), img(img_){}

        complex& add(const complex& second_number) const{
            complex summation;
            summation.real = real + second_number.real;
            summation.img =  img + second_number.img;
            return (summation);
        }

        void show(){ printf("real = [%.2f] ,img = [%2.f]\n", real, img);} 
};

int main(void){
    complex c1;
    complex c2(100.00f, 200.00f);
    complex& sum = c1.add(c2);  //ERROR returning the address of class object which is returned from the function.
    sum.show();
    return 0;
}