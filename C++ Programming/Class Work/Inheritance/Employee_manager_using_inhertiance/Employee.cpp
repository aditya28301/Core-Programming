#include "Employee.hpp"

employee::employee(std::string emp_name, unsigned int emp_sal){
        if(emp_sal >= 0){
            sal = emp_sal;
        }
        else    
        {
            std::cout <<"Please enter number greater 0 " << std::endl;
            exit(EXIT_FAILURE);
        }
        name = emp_name;
    }

employee::employee() : name("default"), sal(0){

}

void employee::get_salary(){
    std::cout <<"employee = " << sal << std::endl;
}  /* Overridden function  */

void employee::get_task(){
    unsigned int choose;
    std::string task;
    choose = rand() % 6 + 1;
    switch(choose){
        case 1:
            task = "Update eod status";
            break;
        case 2:
            task = "update and stabilize script";  
            break;
        case 3:
            task = "send report";
            break;
        case 4:
            task = "Give kt to fresher";
            break;
        case 5:
            task = "status of assigne task";
            break;
        default:
            task = "Idle";
            break;
    }
    std::cout << "task = " << task << std::endl; 
}        /* Overidden function   */

void employee::get_id(){
    empid_t id;
    srand(time(0));
    id = rand() % 9999 + 1;
    std::cout <<"employee id = " << id << std::endl;
}      /* Inheriant function   */

void employee::get_name(){
    std::cout << "employee name = " << name << std::endl;
}   /* Overidden function*/

void employee::open_project(){
    std::cout<< "Employee open a project" << std::endl;
};  /* Inheritor function   */