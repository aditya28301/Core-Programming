#pragma once

#include <iostream>
#include <string>

typedef unsigned long long int size_t;

class Date{
    friend class Book;
    private:
        size_t day;
        size_t month;
        size_t year;        
    public:
        Date(size_t day, size_t month, size_t year);
    friend std::ostream& operator<<(std::ostream& os, const Date& objdate);
};