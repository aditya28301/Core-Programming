#include "Product_details.hpp"

Product_details::Product_details(std::string i_ISBN_number, std::string s_Publisher_name, size_t i_Edition) : ISBN_number(i_ISBN_number), Publisher_name(s_Publisher_name), Edition(i_Edition){

};  

std::ostream& operator<<(std::ostream& os , const Product_details& objproduct_details){
    std::cout <<"ISBN Number = " << objproduct_details.ISBN_number << std::endl;
    std::cout <<"Publisher Name = " << objproduct_details.Publisher_name << std::endl;
    std::cout <<"Editon = " << objproduct_details.Edition << std::endl;
    return os;
}