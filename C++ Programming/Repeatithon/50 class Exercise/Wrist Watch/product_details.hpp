#pragma once

#include <iostream>
#include <string>
#include <vector>

class Product_details{
    private:
        std::string Dimension;
        std::string Resolution;
        std::string Display;

    public: 
        Product_details(
                        std::string s_Dimension,
                        std::string s_Resolution,
                        std::string s_Display
                    );
    friend std::ostream& operator<<(std::ostream& os, const Product_details& objprod);
};