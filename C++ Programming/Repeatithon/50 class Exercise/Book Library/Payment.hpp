#pragma once

#include <iostream>
#include <string>
typedef unsigned long long int size_t;

class Payment{
    friend class Book;
    private:
        size_t kindle;
        size_t paperback;
        size_t hardcover;

    public:
        Payment(
                size_t i_kindle, 
                size_t i_paperback, 
                size_t i_hardcover
            );

    friend std::ostream& operator<<(std::ostream& os, const Payment& objpayment);
};