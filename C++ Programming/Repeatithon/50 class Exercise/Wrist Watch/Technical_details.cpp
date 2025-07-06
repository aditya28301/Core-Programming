#include "Technical_details.hpp"

Technical_details::Technical_details(
                        std::string s_Operating_system,
                        std::initializer_list <std::string> l_Special_features,
                        std::string s_Connectivity_technology,
                        std::string s_Wireless_communication,
                        std::string s_Battery_cell_composition,
                        std::string s_Product_description
                    ) : Operating_system(s_Operating_system),
                        Special_features(l_Special_features),
                        Connectivity_technology(s_Connectivity_technology),
                        Wireless_communication_medium(s_Wireless_communication),
                        Battery_cell_composition(s_Battery_cell_composition),
                        Product_description(s_Product_description){
                        std::cout <<"Technical Details are received " << std::endl;

                    }

std::ostream& operator<<(std::ostream& os, const Technical_details& objtdetails){
    os <<"Technical Details " << std::endl;
    os <<"Operating Systemm = " << objtdetails.Operating_system << std::endl;
    os <<"Special Features " << std::endl;
    for(size_t i = 0; i < objtdetails.Special_features.size(); ++i){
        os <<objtdetails.Special_features[i];
        if(i != objtdetails.Special_features.size() - 1)
            os <<",";
    }
    os <<"Connectivity_technology = " << objtdetails.Connectivity_technology << std::endl;
    os <<"Wireless Communication medium = " << objtdetails.Wireless_communication_medium << std::endl;
    os <<"Battery cell composition = " << objtdetails.Battery_cell_composition << std::endl;
    os <<"Product Description = " << objtdetails.Product_description << std::endl;
    return os;
}