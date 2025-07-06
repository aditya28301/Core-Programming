#include "Watch.hpp"

Watch::Watch(
            std::string s_Watch_name,
            size_t i_watch_rating,
            std::string s_Operating_system,
            std::initializer_list <std::string> l_Special_feature,
            std::string s_Connectivity_technology,
            std::string s_wireless_communication_medium,
            std::string s_Battery_cell_composition,
            std::string s_Product_description,
            double d_Watch_price,
            std::initializer_list <std::string> l_Payment_option,
            std::initializer_list <std::string> l_Offers,
            std::string s_Seller_address,
            std::string s_Seller_name,
            size_t i_Seller_ISBN,
            std::string s_Dimension,
            std::string s_Resolution,
            std::string s_Display_type
) : watch_name(s_Watch_name),
    watch_rating(i_watch_rating),
    o_Technical_Details(s_Operating_system, l_Special_feature, s_Connectivity_technology, s_wireless_communication_medium, s_Battery_cell_composition, s_Product_description),
    o_Payment_Details(d_Watch_price,l_Payment_option, l_Offers),
    o_Address_Details(s_Seller_address, s_Seller_name, i_Seller_ISBN),
    o_Product_Details(s_Dimension, s_Resolution, s_Display_type){

    std::cout <<"All Details are received Order in-progress " << std::endl; 
}


std::ostream& operator<<(std::ostream& os, const Watch& objwatch){
    os << "Watch Name = " << objwatch.watch_name << std::endl;
    os << "Rating  = " << objwatch.watch_rating << std::endl;
    os << objwatch.o_Technical_Details << std::endl;
    os <<objwatch.o_Payment_Details << std::endl;
    os <<objwatch.o_Address_Details << std::endl;
    os <<objwatch.o_Product_Details << std::endl;
    os <<"Order_status is = " << objwatch.order_status << std::endl;
    return os;
}
