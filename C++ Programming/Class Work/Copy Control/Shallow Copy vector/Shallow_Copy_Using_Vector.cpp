#include <iostream>
#include <cstdio>
#include <cstdlib>

void run(void);

class vecref{
    friend class vector;
    private:
        int* ptr;
        size_t size;
        unsigned int ref_count;
    public:
        vecref() : ptr(0), size(0), ref_count(1){
        }

        void push(int data){
            size_t new_required_byte = size + 1 * sizeof(int);
            ptr = (int*)realloc(ptr, new_required_byte);
            if(ptr == 0){
                puts("ERROR IN RESIZING THE MEOMARY");
                exit(EXIT_FAILURE);
            }
            size+= 1;
            ptr[size - 1] = data;
        }

        friend std::ostream& operator<<(std::ostream& os, const vecref& rhs){
            os <<"VECTOR DATA" <<std::endl;
            for(size_t i = 0; i < rhs.size; ++i){
                os << rhs.ptr[i] <<std::endl;
            }
            return os;
        }
        void incRef(){
            ref_count+= 1;
        }

        void decRef(){
            ref_count-= 1;
        }

        ~vecref(){
            free(ptr);
        }
};

class vector{
    private:
        vecref* vf;

    public:
        vector() : vf(new vecref){
        }

        vector(const vector& rhs) : vf(rhs.vf){
            vf->incRef();
        }

        void pushback(const int data) const{
            vf->push(data);
        }

        vector& operator=(const vector& rhs){
            if(this != &rhs){
                vf->decRef();
                if(vf->ref_count == 0){
                    delete vf;
                }
                vf = rhs.vf;
                vf->incRef();
            }
            return *this;
        }

        friend std::ostream& operator<<(std::ostream& os , const vector& rhs){
            os << *rhs.vf << std::endl;
            return os;
        }

        ~vector(){
            std::cout << rcount() <<std::endl;
            vf->decRef();
            if(vf->ref_count == 0){
                delete vf;
            }
        }

        unsigned int rcount(void){
            return vf->ref_count;
        }
};  

int main(void){
    run();
    std::cout <<"PROGRAMMED TERMINATED SUCCESFULLY";
    return 0;
}

void run(void){
    vector* v1 = new vector; //1
    v1->pushback(10);
    v1->pushback(20);
    vector* v2 = new vector(*v1); //2
    std::cout<< *v2;
    std::cout <<"reference count = " << v2->rcount() <<std::endl;

    std::cout <<"SECOND OBJECT" <<std ::endl;
    vector* v3 = new vector; //1
    v3->pushback(100);
    v3->pushback(200);
    vector* v4 = new vector(*v3); //2
    std::cout << *v4 <<std::endl;
    std::cout <<"reference count = " << v4->rcount() <<std::endl;


    *v4 = *v1; //v4 - 1, v4 + 1
    std::cout << *v4 <<std::endl;
    std::cout <<"reference count = " << v4->rcount() <<std::endl;

    delete v1;
    v1 = 0;
    std::cout <<"FIRST COMPLETED DESTRUCTOR" <<std::endl;

    delete v2;
    v2 = 0;
    std::cout <<"SECOND COMPLETED DESTRUCTOR" <<std::endl;

    std::cout <<"reference count = " << v3->rcount() <<std::endl;
    delete v3;
    v3 = 0;
    std::cout <<"THIRD COMPLETED DESTRUCTOR"<<std::endl;

    std::cout <<"reference count = " << v4->rcount() <<std::endl;
    delete v4;
    v4 = 0;
    std::cout <<"FOURTH COMPLETED DESTRUCTOR" <<std::endl;
}