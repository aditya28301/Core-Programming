#include <iostream> 
#include <string> 
#include <vector> 
#include <memory> 

#include <cstdio> 
#include <cstdlib> 
#include <cassert> 

class Date
{
    private: 
        int day, month, year; 
    public: 
        Date(int init_day, int init_month, int init_year) : day(init_day), 
                                                            month(init_month), 
                                                            year(init_year)
        {

        }

        void show() const
        {
            std::cout << day << "-" << month << "-" << year << std::endl; 
        }
}; 

void defining_and_using_shared_ptr(void); 
void get_swap_routines_of_shared_ptr(void); 
void make_shared_demo(void); 
void shared_ptr_reference_counting(void); 
void shared_ptr_adv_operations(void); 

int main(void)
{
    defining_and_using_shared_ptr(); 
    get_swap_routines_of_shared_ptr(); 
    make_shared_demo(); 
    shared_ptr_reference_counting(); 
    return (EXIT_SUCCESS); 
}

void defining_and_using_shared_ptr(void)
{
    std::shared_ptr<int> p_int(new int(100)); 
    std::shared_ptr<std::vector<int>> p_vec_int(new std::vector<int>(5, 100)); 

    std::cout << "*p_int = " << *p_int << std::endl; 
    *p_int = 500; 
    std::cout << "*p_int = " << *p_int << std::endl; 

    puts("Showing vector:"); 
    for(std::vector<int>::size_type i = 0; i != p_vec_int->size(); ++i)
        std::cout << (*p_vec_int)[i] << std::endl; 

    p_vec_int->push_back(600); 
    p_vec_int->push_back(700); 

    puts("Showing the modified vector"); 
    for(std::vector<int>::size_type i = 0; i != p_vec_int->size(); ++i)
        std::cout << (*p_vec_int)[i] << std::endl; 
}

void get_swap_routines_of_shared_ptr(void)
{
    std::shared_ptr<std::vector<int>> p_vec_int1(new std::vector<int>); 
    std::shared_ptr<std::vector<int>> p_vec_int2(new std::vector<int>); 

    for(std::vector<int>::size_type i = 0; i != 5; ++i)
    {
        p_vec_int1->push_back((i+1) * 10); 
        p_vec_int2->push_back((i+1) * 5); 
    }

    // using get() member function 
    std::vector<int>* p_vec1 = p_vec_int1.get(); 
    std::vector<int>* p_vec2 = p_vec_int2.get(); 

    puts("Vector1:"); 
    for(std::vector<int>::size_type i = 0; i != p_vec1->size(); ++i)
    {
        std::cout << "p_vec1->at(" << i << "):" << p_vec1->at(i) << std::endl;  
    }

    puts("Vector2:"); 
    for(std::vector<int>::size_type i = 0; i != p_vec2->size(); ++i)
    {
        std::cout << "p_vec2->at(" << i << "):" << p_vec2->at(i) << std::endl; 
    }

    // swap() member function 
    std::swap(p_vec_int1, p_vec_int2); 
    p_vec1 = p_vec_int1.get(); 
    p_vec2 = p_vec_int2.get(); 

    puts("Vector1:"); 
    for(std::vector<int>::size_type i = 0; i != p_vec1->size(); ++i)
    {
        std::cout << "p_vec1->at(" << i << "):" << p_vec1->at(i) << std::endl;  
    }

    puts("Vector2:"); 
    for(std::vector<int>::size_type i = 0; i != p_vec2->size(); ++i)
    {
        std::cout << "p_vec2->at(" << i << "):" << p_vec2->at(i) << std::endl; 
    }
}

void make_shared_demo(void)
{
    std::shared_ptr<int> p_int = std::make_shared<int>(10); // std::shared_ptr<int> sp_int(new int(100)); 
    std::shared_ptr<std::string> p_string = std::make_shared<std::string>("Hello!"); 
    std::shared_ptr<Date> p_date = std::make_shared<Date>(10, 10, 2021); 
    // std::shared_ptr<T> sp_T = std::make_shared<T>(init data compatible with at least one CC of T); 

    std::cout   << "*p_int = " << *p_int << std::endl 
                << "*p_string = " << *p_string << std::endl; 
    p_date->show(); 
}

void shared_ptr_reference_counting(void)
{
    std::shared_ptr<int> p1 = std::make_shared<int>(100); 
    std::shared_ptr<int> p2(p1); 
    std::shared_ptr<int> p3 = p1; 

    std::cout   << "p1.use_count():" << p1.use_count() << std::endl
                << "p2.use_count():" << p2.use_count() << std::endl 
                << "p3.use_count():" << p3.use_count() << std::endl; 

    p1 = nullptr;  

    std::cout   << "p1.use_count():" << p1.use_count() << std::endl
                << "p2.use_count():" << p2.use_count() << std::endl 
                << "p3.use_count():" << p3.use_count() << std::endl; 

    p2 = nullptr; 

    std::cout   << "p1.use_count():" << p1.use_count() << std::endl
                << "p2.use_count():" << p2.use_count() << std::endl 
                << "p3.use_count():" << p3.use_count() << std::endl; 

    p3 = nullptr; 

    std::cout   << "p1.use_count():" << p1.use_count() << std::endl
                << "p2.use_count():" << p2.use_count() << std::endl 
                << "p3.use_count():" << p3.use_count() << std::endl; 
    
}

/*
void shared_ptr_adv_operations(void)
{
    std::unique_ptr<int> pu_int(new int(10)); 
    int* p = pu_int.get(); 
    std:
    
    :cout << "p = " << p << std::endl; 
    std::cout << "*p=" << *p << std::endl; 
    std::shared_ptr<int> ps_int(pu_int); 
    p = pu_int.get(); 
    if(p==0)
        std::cout << "Unique ptr is now NULL" << std::endl; 
    p = ps_int.get(); 
    std::cout << "p = " << p << std::endl; 
    std::cout << "*p = " << *p << std::endl; 
}
*/ 

/*

std::shared_ptr<Date> pgDate; 

int main(void)
{
    f(); 
}

void f(){
    std::shared_ptr<Date> pDate = std::make_shared<Date>(10, 10, 2021); 
    pgDate = pDate;     
}

[datePtr    ]:  --------------> DYNAMICALLY ALLOCATED DATE OBJ 
[ref_count  ]:  --------------> 1 

/////////////////////////////////////////////////////////////////////

[datePtrLocal] :    -----------------> DYNAMICALLY ALLOCATED DATE OBJ
[ref_count  ]:      --------------> 2 

[datePtrGlobal]:    -----------------> DYNAMICALLY ALLOCATED DATE OBJ
[ref_count  ]:      --------------> 2 
//////////////////////////////////////////////////////////////////////
after returning from f()
[datePtrGlobal]:    -----------------> DYNAMICALLY ALLOCATED DATE OBJ
[ref_count  ]:      --------------> 1 
#-----------------------------------------------------------------
in main: gpDate.reset(nullptr); 
datePtrGlobal]:    -----------------> DYNAMICALLY ALLOCATED DATE OBJ
[ref_count  ]:      --------------> 0 

delete DateObjectAddress 
    [1] Call Date::~Date(DateObjectAddress); 
    [2] free(DateObjectAddress); 

*/

/* 

void test(void)
{
    std::shared_ptr<int> p_int1 = std::make_shared<int>(10); 
    std::shared_ptr<int> p_int2(p_int1); 
    std::shared_ptr<int> p_int3(p_int2); 

    // use p_int1, p_int2, p_int3


}

void test(void)
{
    std::shared_ptr<Date> pDate1 = std::make_shared<Date>(10, 10, 2021); 
    std::shared_ptr<Date> pDate2(pDate1); 
    std::shared_ptr<Date> pDate3(pDate2); 

    // pDate1.use_count(), pDate2.use_count(), pDate3.use_count() == 3 

    pDate1.reset(std::make_shared<Date>(1,1,1970)); 
    // pDate1.use_count(), pDate2.use_count(), pDate3.use_count() == 2 
    pDate2.reset(std::make_shared<Date>(2,2,1971)); 
    // pDate1.use_count(), pDate2.use_count(), pDate3.use_count() == 1 
    pDate3.reset(std::make_shared<Date>(3,3,1972)); 
        // pDate1.use_count(), pDate2.use_count(), pDate3.use_count() == 0 

}
*/ 


