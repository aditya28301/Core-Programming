#pragma once

#include <iostream>
#include <string>
#include <vector>

typedef unsigned long long int size_t;
class Address{
    private:
        std::string Seller_address;
        std::string Seller_name;
        size_t ISBN_number;
    public:
        Address(
                std::string s_Seller_address, 
                std::string s_Seller_name,
                size_t i_ISBN_number
            );
    friend std::ostream& operator<<(std::ostream& os, const Address& objadd);
};


