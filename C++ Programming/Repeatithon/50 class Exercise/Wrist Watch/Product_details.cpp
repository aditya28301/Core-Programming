#include "product_details.hpp"

Product_details::Product_details(
                std::string s_Dimension,
                std::string s_Resolution,
                std::string s_Display
            ) :
            Dimension(s_Dimension),
            Resolution(s_Resolution),
            Display(s_Display){
                std::cout <<"Product Details " << std::endl;
            }

std::ostream& operator<<(std::ostream& os, const Product_details& objprod){
    os <<"Product Information " << std::endl;
    os <<"Dimension = " << objprod.Dimension << std::endl;
    os <<"Resolution = " << objprod.Resolution << std::endl;
    os <<"Dispaly = " << objprod.Display << std::endl;
    return os;
}