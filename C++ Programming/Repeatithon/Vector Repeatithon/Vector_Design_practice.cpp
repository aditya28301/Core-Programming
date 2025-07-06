#include <cstdio>
#include <cstdlib>

class vector{

    public:
    vector();

    vector(const size_t index);
    vector(
            const size_t index,
            const size_t data
    );

    size_t get(void){};
    void set(size_t index) const{};
    size_t show(void) const{};
    size_t size(void) const{};
    void resize(void) const{};
};

int main(void){
    test();
    return 0;
}

void test(void){
    vector v;
    v.get();   
    v.set(10);
    v.show();
    v.size();
    v.resize();
}

///////////////////////////////////////////
class vector{

    public:

    vector();
    vector(const size_t index);
    vector(
        const size_t index,
        const size_t data
    );

    void set(const size_t index) {};
    size_t get(void) const{};
    void show(void) const{};
    void size(void) const{};
    void resize(void) const {};

};

int main(void){
    test();
}

void test(void){
    vector v;
    v.set();
    v.get();
    v.show();  
    v.size();
    v.resize();
}

//////////////////////////////////////////////

class vector{

    public:
        vector();
        vector(const size_t index);
        vector(
            const size_t index,
            const size_t data
        );

        void set(const size_t index){};
        void get(size_t index) const{};
        void show(void) const{};
        void resize(void) const{};
        void size(void) const{};
};

int main(void){
    test();
}

void test(void){
    vector v;
    v.set();
    v.get();
    v.show();
    v.resize();
    v.size();
}

////////////////////////////////////////////

class vector{

    public:
        vector();
        vector(const size_t index);
        vector(
            const size_t index,
            const size_t data
        );

        void set(const size_t index){};
        size_t get(void) const{};
        void show(void) const{};
        void size() const{};
        void resize(void) const{};
};

int main(void){
    test();
    return 0;
}

void test(void){
    vector v;
    v.set();
    v.get();
    v.size();
    v.resize();
    v.show();
}
///////////////////////////////////////////////////////////////
class vector{
    public:

        vector();
        vector(const size_t index);
        vector(
            const size_t index,
            const size_t data
        );

        void set(const size_t index){};
        void get(void) const {};
        void show(void) const{};
        void resize(void) const {};
        void size(void) const {};
};
int main(void){
    test();
}   

void test(void){

}