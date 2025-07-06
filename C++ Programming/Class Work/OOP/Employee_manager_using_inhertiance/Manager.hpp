#ifndef _MANAGER_
#define _MANAGER_ 

#include "Employee.hpp"

class manager : public employee{
    private:
        std::string name;
        unsigned int sal;

    public:
        manager();
        manager(std::string emp_name, unsigned int emp_sal);
        void get_id();  /* Overidden not virtual*/
        void get_salary(); /*  overridden virtual*/
        void get_name(); /*  overridden virtual  */
        void get_task(); /*  overridden virtual  */
        void get_teamSize();    /* Derived specific function    */    
};

#endif /*   _MANAGER_  */