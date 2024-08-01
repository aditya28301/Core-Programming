#include <cstdlib>
#include <cstdio>

class complex{
    private:
        float real;
        float img;
    public:
        complex() : real(0.0), img(0.0){}
        complex(float real_, float img_) : real(real_), img(img_){}

        complex* add(const complex second_number) const{
            complex* ptr = new complex;
            ptr->real = real + second_number.real;
            ptr->img = img + second_number.img;
            return (ptr);
        }
        void show(void){ printf("real = [%.2f], img = [%.2f]\n", real, img); }
};

int main(void){
    complex c1;
    complex c2(100.0f, 200.0f);
    complex* sum = c1.add(c2);
    sum->show();
    delete sum;
    return 0;
}