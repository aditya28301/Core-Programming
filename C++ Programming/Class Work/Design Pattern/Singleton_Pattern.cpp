#include <cstdio>

#define TEST_MAX 2
class singleton{
    private:
        int a;
        int b;

        singleton(int a_, int b_) : a(a_), b(b_){

        }
        static int obj_count;

    public:
        static singleton* get_instance(int a, int b){
            obj_count++;
            if(obj_count > TEST_MAX - 1){
                puts("YOU CAN CREATE ONLY SINGLE OBJECT");
                return 0;
            }
            return new singleton(a, b);
        }
        void get_data(int* p, int* q)
        {
            *p = a;
            *q = b;
        }
};

int singleton::obj_count = 0;

int main(){
    int temp_1[TEST_MAX];
    int temp_2[TEST_MAX];

    singleton** s1 = 0;
    s1 = new singleton*;

    for(int i = 0; i < TEST_MAX; ++i){
        int* a = 0;
        a = new int[TEST_MAX];
        a[i] = i;

        int* b = 0;
        b = new int[TEST_MAX];
        b[i] = i + 1;

        *(s1 + i) = singleton::get_instance(a[i], b[i]);
        if(s1[i] == NULL)
            break;

        s1[i]->get_data(&temp_1[i], &temp_2[i]);
        printf("object create s1[%d] and value are [%d], [%d]\n", i, a[i], b[i]);
    }   

    for(int  i = 0; i < TEST_MAX; ++i){

        if(sizeof(s1)/sizeof(s1[0]) == 1){
            puts("SINGLE OBJECT OCCURED");
            delete s1[i];
            s1[i] = 0;
            break;
        }
        delete s1[i];
        s1[i] = 0;
    }
    puts("Terminated Sucessfully");
    return 0;
}