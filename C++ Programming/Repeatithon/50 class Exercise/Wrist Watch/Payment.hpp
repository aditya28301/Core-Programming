#pragma once

#include <string>
#include <vector>
#include <iostream>

class Payment{
    private:
        double price;
        std::vector <std::string> Payment_options;
        std::vector <std::string> Offers;
        std::string Payment_status = "Payment Done";
    public:
        Payment(
                double d_price, 
                std::initializer_list <std::string> l_Payment_options,
                std::initializer_list <std::string> l_Offers
            );
    friend std::ostream& operator<<(std::ostream& os, const Payment& objpay);
};  

