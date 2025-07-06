#include <iostream>
#include <cstdlib>
#include <memory>
#include <vector>
#include <typeinfo>

class date{
    private:
        int day;

    public:
        date() : day(10) {} 
        void show() const{
            std::cout << this->day << std::endl;
        }
};

void unique_ptr(void){
    std::unique_ptr<int> obj(new int(100));

    if(obj.get())
        std::cout <<*obj << "NOT NULL" << std::endl;
    else       
        std::cout <<"NULL" << std::endl;

    // std::unique_ptr<int> obj2(obj);  // not allowed
    std::unique_ptr<int> obj3(new int(200));
    // obj3 = obj;  not allowed unique_ptr restricting to copy assignment operator

    

}

void shared_ptr(void){
    std::shared_ptr<int> p_obj(new int(100));
    std::shared_ptr<int> p_obj2(p_obj);
    std::cout <<"refernce_count = " << p_obj.use_count() << std::endl;
    std::cout <<"Get inside ptr = " << typeid(*p_obj.get()).name() << std::endl;

    p_obj2 = nullptr;
    p_obj = nullptr;

    std::cout <<"Using nullptr reference_count = " << p_obj.use_count() << std::endl;
    std::shared_ptr<std::vector<int>> v_obj(new std::vector<int>(5, 100));
    std::shared_ptr<std::vector<int>> v_obj2(new std::vector<int>(5,200));
    std::cout <<"Get inside ptr = " << typeid(*v_obj.get()).name() << std::endl;
    v_obj2 = v_obj;

    for(size_t i =0 ; i < v_obj2->size(); ++i){
        std::cout <<(*v_obj2)[i] <<" ";
    }
    std::cout << std::endl;
    std::cout <<"Vector shared_ptr count = " << v_obj.use_count() << std::endl;
    
    std::shared_ptr<date> u_obj(new date);
    u_obj->show();
    std::cout <<u_obj.use_count() << std::endl;
    std::cout <<"Get inside ptr = " << typeid(*u_obj.get()).name() << std::endl;

    // uiing make_shared\

    std::shared_ptr<int> m_obj = std::make_shared<int>(100);
    std::shared_ptr<int> m_obj2(m_obj);
    std::cout <<"Reference count :: count = " <<m_obj.use_count() << std::endl;
    std::cout <<*m_obj << std::endl;
    std::cout <<"Get inside ptr = " << typeid(*m_obj.get()).name() << std::endl;
    m_obj = nullptr;
    std::cout <<"Reference count:: using nullptr = " << m_obj2.use_count()<< std::endl;

}
int main(void){
    //shared_ptr();
    unique_ptr();
    std::cout <<"Programe terminated succesfully" << std::endl;
    return EXIT_SUCCESS;
}