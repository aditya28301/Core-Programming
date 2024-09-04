#include "Manager.hpp"

manager::manager() : name(""), sal(0){
}

manager::manager(std::string emp_name, unsigned int emp_sal){
    if(emp_sal >=0){
        sal = emp_sal;
    }
    else{
        std::cout << "Input requried greater than zero" << std::endl;
        exit(EXIT_FAILURE);
    }
    name = emp_name;
}

void manager::get_id(){
    empid_t id;
    srand(time(0));
    id = rand() % 9999 + 5;
    std::cout <<"Manager id = " << id << std::endl;
}

void manager::get_salary(){
    std::cout << "Manager sal = " << sal << std::endl;
}
void manager::get_name(){
    std::cout << "Manager name = " << name << std::endl;
}

void manager::get_task(){
     unsigned int choose;
    std::string task;
    choose = rand() % 6 + 1;
    switch(choose){
        case 1:
            task = "Organise event";
            break;
        case 2:
            task = "Project planning";  
            break;
        case 3:
            task = "Employee Increment and hike";
            break;
        case 4:
            task = "Hiring new employee";
            break;
        case 5:
            task = "Get employee details";
            break;
        default:
            task = "Idle";
            break;
    }
    std::cout <<"Manager task = " << task << std::endl;
}

 void manager::get_teamSize(){
    std::cout << "1000 is team size" << std::endl;
 }  /* Derived specific function */