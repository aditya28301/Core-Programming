#include "IOperation.hpp"

class addition :  public IOperation{
    public:
        addition();
        inline double compute(double num1, double num2);
};

class subtraction : public IOperation{
    public:
        subtraction();
        inline double compute(double num1, double num2);
};

class multiplication : public IOperation{
    public:
        multiplication();
        inline double compute(double num1, double num2);
};

class division : public IOperation{
    public:
        division();
        inline double compute(double num1, double num2);
};



