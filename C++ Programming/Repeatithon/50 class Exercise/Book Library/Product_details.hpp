#pragma once

#include <string>
#include <iostream>

class Product_details{
    friend class Book;
    private:
        std::string ISBN_number;
        std::string Publisher_name;
        size_t Edition;
    public:
        Product_details(std::string i_ISBN_number, std::string s_Publisher_name, size_t i_Edition);
    friend std::ostream& operator<<(std::ostream& os , const Product_details& objproduct_details);
};  