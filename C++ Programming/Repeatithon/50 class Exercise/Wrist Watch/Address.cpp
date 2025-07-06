#include "Address.hpp"

Address::Address(
                std::string s_Seller_address, 
                std::string s_Seller_name,
                size_t i_ISBN_number
            ) : 
                Seller_address(s_Seller_address),
                Seller_name(s_Seller_name),
                ISBN_number(i_ISBN_number){
                    std::cout <<"Address Details are received" << std::endl;
                }

std::ostream& operator<<(std::ostream& os, const Address& objadd){
    os <<"Address Details " << std::endl;
    os <<"Seller address = " << objadd.Seller_address << std::endl;
    os <<"Seller Name = " << objadd.Seller_name << std::endl;    
    os <<"ISBN Number = " << objadd.ISBN_number << std::endl;
    return os;
}