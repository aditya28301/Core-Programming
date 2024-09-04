#ifndef _EMPLOYEE_MANAGER_
#define _EMPLOYEE_MANAGER_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>

class employee{
    private:
        std::string emp_name;
        unsigned int emp_id;
        unsigned int sal;

    public:
        static unsigned int size;
        employee();
        employee(std::string, unsigned int id, unsigned int salary);
        unsigned int get_salary();
        std::string get_employee_name();
        unsigned int get_employee_id();
};

class manager : public employee{
    private:
        std::string name;
        unsigned int manager_salary;

    public:
        manager();
        manager(std::string m_name, unsigned int sal);
        unsigned int get_team_size();
        unsigned int get_salary();
};

#endif  /*  _EMPLOYEE_MANAGER_  */
