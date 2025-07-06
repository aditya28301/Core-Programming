#include "Address.hpp"

Address::Address(std::string s_address, std::string d_address) : seller_address(s_address), delivery_mode(d_address){

};

std::ostream& operator<<(std::ostream& os , const Address& objAddress){
    std::cout <<"Seller Address = " << objAddress.seller_address << std::endl;
    std::cout <<"Delivery Mode  = " << objAddress.delivery_mode << std::endl;
    return os;
}