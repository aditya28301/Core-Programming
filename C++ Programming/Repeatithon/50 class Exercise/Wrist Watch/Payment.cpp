#include "Payment.hpp"

Payment::Payment(
            double d_price, 
            std::initializer_list <std::string> l_Payment_options,
            std::initializer_list <std::string> l_Offers
        ) : price(d_price),
            Payment_options(l_Payment_options),
            Offers(l_Offers){
                std::cout <<"Payment details are received" << std::endl;
            }

std::ostream& operator<<(std::ostream& os, const Payment& objpay){
    os <<"Payment Details " << std::endl;
    os <<"Payment Options  = ";
    for(size_t i = 0; i < objpay.Payment_options.size(); ++i){
        os <<objpay.Payment_options[i];
        if(i != objpay.Payment_options.size() - 1)
            os << ",";
    }
    os << std::endl;
    os <<"Offers = ";
    for(size_t i = 0; i < objpay.Offers.size(); ++i){
        os <<objpay.Offers[i];
        if(i != objpay.Offers.size() - 1)
            os << ",";
    }   
    os << std::endl;
    os <<"Payment Status = " << objpay.Payment_status << std::endl;
    return os;
}