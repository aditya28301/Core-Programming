#pragma once

#include <iostream>
#include <string>
#include <vector>

class Technical_details{
    private:
        std::string Operating_system;
        std::vector <std::string> Special_features;
        std::string Connectivity_technology;
        std::string Wireless_communication_medium;
        std::string Battery_cell_composition;
        std::string Product_description;

    public:
        Technical_details(
                        std::string s_Operating_system,
                        std::initializer_list <std::string> l_Special_features,
                        std::string s_Connectivity_technology,
                        std::string s_Wireless_communication,
                        std::string s_Battery_cell_composition,
                        std::string s_Product_descriptionn
                    );
    friend std::ostream& operator<<(std::ostream& os, const Technical_details& objtdetails);
};