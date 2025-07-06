#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Technical_details.hpp"
#include "Payment.hpp"
#include "Address.hpp"
#include "product_details.hpp"

typedef unsigned long long int size_t;

class Watch{
    private:
        std::string watch_name;
        size_t watch_rating;
        Technical_details o_Technical_Details;
        Payment o_Payment_Details;
        Address o_Address_Details;
        Product_details o_Product_Details;
        std::string order_status = "Ordered";

    public:
        Watch(
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
            std::string i_Dimension,
            std::string s_Resolution,
            std::string s_Display_type
        );
    friend std::ostream& operator<<(std::ostream& os, const Watch& objwatch);
};

