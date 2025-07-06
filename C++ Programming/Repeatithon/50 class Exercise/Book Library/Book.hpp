#pragma once 

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "Payment.hpp"
#include "Address.hpp"
#include "Product_details.hpp"
#include "Date.hpp"

typedef unsigned long long int size_t;

class Book{
    private:
        std::string s_Book_name;
        std::string s_Book_desc;
        std::vector <std::string> author_name;
        Payment o_Payment;
        Address o_Address;
        Product_details o_Product_details;
        size_t Rating;
        Date o_Date;
    public:
        Book(
            std::string book_name, 
            std::string book_desc, 
            std::initializer_list <std::string> authors,
            size_t kindle,
            size_t paperback,
            size_t hardcover,
            std::string seller_address,
            std::string delivery_mode,
            std::string ISBN_number,
            std::string publisher_name,
            size_t Edition,
            size_t month_of_publication,
            size_t year_of_publication,
            size_t day_of_publication,
            size_t Rating
        );
    friend std::ostream& operator<<(std::ostream& os, const Book& objbook);
};