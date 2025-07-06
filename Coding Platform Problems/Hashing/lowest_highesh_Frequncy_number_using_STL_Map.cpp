#include <map>
#include <iostream>
#include <string>
#include <unordered_map>

void find_frequency(const std::string& str, size_t len);

int main(void){
    std::string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789"
                             "!@#$%^&*()-_=+[]{}|;:,.<>?/";
    find_frequency(str, str.length());
    std::cout <<"Program terminated sucesfully";
    return EXIT_SUCCESS;
}

void find_frequency(const std::string& str, size_t len){
    std::map<char, int> fmap;
    for(size_t i = 0; i < len; ++i){
        fmap[str[i]]++; 
    }
    
    size_t min = INT_MAX;
    for(std::map<char, int>::iterator it = fmap.begin(); it != fmap.end(); ++it){
        if(it->second < min)
            min = it->second;
    }

     for(std::map<char, int>::iterator it = fmap.begin(); it != fmap.end(); ++it){
        std::cout <<"character =     " <<it->first <<"    "<<"count =    " << it->second << std::endl;
    }
    std::cout<<std::endl;
    std::cout <<"Minimum frequncy count is  =    " << min << std::endl;

    size_t max = 0;
    for(std::map<char, int>::iterator it = fmap.begin(); it != fmap.end(); ++it){
        if(it->second > max)
            max = it->second;
    }
    std::cout <<"Maximum frequncy count is  =    " << max << std::endl;
}