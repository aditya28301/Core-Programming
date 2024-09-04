#ifndef _EMPLOYEE_
#define _EMPLOYEE_

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <typeinfo>

typedef unsigned int salary_t;
typedef unsigned int empid_t;
typedef std::string task_t;
typedef std::string name_t;

class employee{
    private:
        std::string name;
        unsigned int sal;

    public:
        employee();
        employee(std::string emp_name, unsigned int emp_sal);
        virtual void get_salary();  /* Overridden function  */
        virtual void get_task();        /* Overidden function   */
        void get_id();      /* Overridden not virtual  */
        virtual void get_name();     /* Overidden function*/
        void open_project();    /* Inheritor function   */
};
#endif  /*  _EMPLOYEE_  */
