#include "Manager.hpp"

void run(void);
int main(void){
    srand(time(0));
    run();
    std::cout <<"Programme terminated sucessfully";
    return(EXIT_SUCCESS);
}

void run(void){
    employee* aditya = 0;
    aditya = new employee("Aditya", 61000);
    manager* ambrish = 0;
    ambrish = new manager("Ambrish", 150000);

    /* Employee pointer and employee object */
    std::cout <<"employee pointer and employee object" << std::endl;
    aditya->get_name(); /* employee::f()*/
    aditya->get_salary();   /*  employee::f()*/
    aditya->get_task();  /*  employee::f()*/
    aditya->get_id();  /*  employee::f()*/

    std::cout << std::endl;

    /*  Employee pointer and manager object */
    std::cout << "Employee pointer and manager object" << std::endl;
    aditya = ambrish;
    aditya->open_project(); /* employee::f()*/
    dynamic_cast<manager*>(aditya)->get_teamSize(); /* manager::f()*/
    aditya->employee::get_salary(); /*  employee::f()*/
    aditya->get_salary();   /* manager::f() */
    aditya->get_id();   /* employee::f()    */
    dynamic_cast<manager*>(aditya)->get_id();   /*  manager::f()*/
    aditya->employee::get_task();   /* employee::f()    */
    aditya->get_task(); /*  manager::f()    */
    aditya->employee::get_name();   /*  employee::f()*/
    aditya->get_name(); /*  manager::f()    */

    std::cout << std::endl;

    /* Manager pointer and manager object   */
    std::cout <<"Manager pointer and manager object" << std::endl;
    ambrish->get_teamSize();    /*  manager::f()    */
    ambrish->open_project();  /* employee::f()    */
    ambrish->employee::get_id();    /* employee::f()    */
    ambrish->get_id();  /*  manager::f()    */
    ambrish->employee::get_name();  /* employee::f()    */
    ambrish->get_name();    /*  manager::f()    */
    ambrish->employee::get_task();  /*  employee::f()   */
    ambrish->get_task();    /*  manager::f()    */
    ambrish->employee::get_salary();    /* employee::f()    */
    ambrish->get_salary();  /* manager::f() */
}   