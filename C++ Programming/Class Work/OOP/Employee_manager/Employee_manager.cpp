#include "Employee_manager.hpp"

unsigned int employee::size = 0;

/*  Employee class details  */
employee::employee() : emp_name(""), emp_id(0), sal(0){

}

employee::employee(std::string name, unsigned int id, unsigned int salary) :
    emp_name(name), emp_id(id), sal(salary){
    size+= 1;    
}

unsigned int employee::get_salary(){
    return sal;
}   

std::string employee::get_employee_name(){
    return emp_name;
}

unsigned int employee::get_employee_id(){
    return emp_id;
}

/*  Manager class details   */
manager::manager() : name(""), manager_salary(0){}

manager::manager(std::string m_name, unsigned int sal) : name(m_name), manager_salary(sal){}

unsigned int manager::get_team_size(){
    return size;
}

unsigned int manager::get_salary(){
    return manager_salary;
}