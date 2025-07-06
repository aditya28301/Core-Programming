#include <map>
#include <iostream>
#include <string>
#include <unordered_map>

void find_frequency(const std::string& str, size_t len);

int main(void){
    std::string str = "Aditya Ashok Darekar";
    find_frequency(str, str.length());
    std::cout <<"Program terminated sucesfully";
    return EXIT_SUCCESS;
}

void find_frequency(const std::string& str, size_t len){
    std::unordered_map<char, int> fmap;
    for(size_t i = 0; i < len; ++i){
        fmap[str[i]]++; 
    }

    for(std::unordered_map<char, int>::iterator it = fmap.begin(); it != fmap.end(); ++it){
        std::cout <<"character =     " <<it->first <<"    "<<"count =    " << it->second << std::endl;
    }
}