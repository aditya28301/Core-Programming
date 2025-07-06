#include "Employee_manager.hpp"

int main(void){
    employee* emp_1 = 0;
    employee* emp_2 = 0;
    employee* emp_3 = 0;
    manager* mng = 0;

    unsigned int salary = 0;
    unsigned int emp_id = 0;
    std::string name;

    unsigned int team_size = 0;
    unsigned int m_salary = 0;

    std::cout <<"Employee Details\n----------------------------------------------------------------------------------------\n" << std::endl;
    /*  Employee 1   */
    emp_1 = new employee("Aditya Darekar", 197747, 61000);
    salary = emp_1->get_salary();
    name = emp_1->get_employee_name();   
    emp_id = emp_1->get_employee_id();

    std::cout <<"Employee Name = " << name << std::endl  
        <<"Employee id = " << emp_id << std::endl    
        <<"Employee salary = " << salary << std::endl << std::endl;

    /*  Employee 2   */
    emp_2 = new employee("Somesh Atole", 19000, 180000);
    salary = emp_2->get_salary();
    name = emp_2->get_employee_name();   
    emp_id = emp_2->get_employee_id();

    std::cout <<"Employee Name = " << name << std::endl  
        <<"Employee id = " << emp_id << std::endl    
        <<"Employee salary = " << salary << std::endl << std::endl;

    /*  Employee 3   */
    emp_3 = new employee("Mandar Chitale", 71799, 780000);
    salary = emp_3->get_salary();
    name = emp_3->get_employee_name();   
    emp_id = emp_3->get_employee_id();

    std::cout <<"Employee Name = " << name << std::endl  
        <<"Employee id = " << emp_id << std::endl    
        <<"Employee salary = " << salary << std::endl << std::endl;

std::cout << "Manager Details\n----------------------------------------------------------------------------------------"<< std::endl;

    /*  Manager Operation   */

    mng = new manager("Ambrish Kapoor", 40000000);
    team_size = mng->get_team_size();
    m_salary = mng->get_salary();

    std::cout <<"Team size = " << team_size << std::endl  
        <<"Manager Salary = " << m_salary << std::endl << std::endl;

    delete emp_1;
    delete emp_2;
    delete emp_3;
    delete mng;
    printf("Programme terminated succesfully");
    return 0;
}