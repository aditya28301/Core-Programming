#include <iostream> 
#include <memory> 

class HasPtr{
    private: 
        int n; 
        std::shared_ptr<int> p_int; 

    public: 
        HasPtr(int _n, int _val) : n(_n), p_int(std::make_shared<int>(_val)){  
        }

        void show_ref_count(const char* msg) const {
            if(msg)
                std::cout << msg << std::endl; 
            std::cout << "Ref count:" << p_int.use_count() << std::endl; 
        }
}; 

int main(void){
    HasPtr hp1(100, 200); 
    HasPtr hp2(hp1); 
    HasPtr hp3(hp2); 

    hp1.show_ref_count("on hp1:"); //3 
    hp2.show_ref_count("on hp2:"); //3
    hp3.show_ref_count("on hp3:"); //3

    HasPtr hp4(1000, 2000); 
    HasPtr hp5(hp4); 
    hp4.show_ref_count("on hp4:"); //2
    hp5.show_ref_count("on hp5:"); //2

    hp5 = hp3; 

    hp1.show_ref_count("on hp1 after hp5 = hp3:"); //4
    hp2.show_ref_count("on hp2 after hp5 = hp3:"); //4
    hp3.show_ref_count("on hp3 after hp5 = hp3::"); //4
    hp4.show_ref_count("on hp4 after hp5 = hp3::"); //1
    hp5.show_ref_count("on hp5 after hp5 = hp3::"); //4
}
