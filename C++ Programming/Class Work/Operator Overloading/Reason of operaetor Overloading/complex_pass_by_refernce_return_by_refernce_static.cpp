#include <cstdlib>
#include <cstdio>

class complex{
    private:
        float real;
        float img;

    public:
        complex() : real(0.0), img(0.0) {}
        complex(float real_, float img_) : real(real_), img(img_){}

        complex& add(const complex& second_number) const{
            static complex summation;
            summation.real = real + second_number.real;
            summation.img = img + second_number.img;
            return (summation);
        }   

        void show(void){ printf("real = [%.2f], img = [%.2f]\n", real, img);}
};

int main(void){
    complex c1;
    complex c2(100.0f, 200.0f);
    complex& sum = c1.add(c2);   
    sum.show();
    return 0;
}