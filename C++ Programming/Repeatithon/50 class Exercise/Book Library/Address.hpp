#pragma once

#include <iostream>
#include <string>

class Address{
    friend class Book;
    private:
        std::string seller_address;
        std::string delivery_mode;
    public:
        Address(std::string s_address, std::string d_address);
    friend std::ostream& operator<<(std::ostream& os , const Address& objAddress); 
};