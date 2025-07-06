#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

class reverse_string{
    private:
        std::string str;

    public:
        reverse_string(std::string& ref_str) : str(ref_str) { }

        void brute_approach(){
            std::vector<std::string> stored_string_reversed;
            bool space_found = false;
            std::string temp_string("");

            for(size_t i = 0; i != str.size(); ++i){
                if(str[i] == ' '){
                    space_found  = true;
                    //std::cout << temp_string << std::endl;
                    stored_string_reversed.push_back(temp_string);
                    temp_string.clear();
                }

                if(space_found != true){
                    temp_string.push_back(str[i]);
                    //std::cout << temp_string << std::endl;
                    
                }
                else{
                    temp_string.push_back(str[i]);
                    stored_string_reversed.push_back(temp_string);
                    temp_string.clear();
                    space_found = false;
                }
            }

            stored_string_reversed.push_back(temp_string);

                str = "";
                size_t count = stored_string_reversed.size() - 1;
                size_t loop = 0;
                size_t string_count = 0;        
                while(true){
                    if(count == 0 && loop == stored_string_reversed[count].size())
                        break;

                    if(loop >= stored_string_reversed[count].size()){
                        --count;
                        loop = 0;
                    }
    
                    str.push_back((stored_string_reversed[count])[loop++]);
                }
        }

        void show(){    
            std::cout << str;
        }

};

int main(void){
std::string input_string = "This is decent";
reverse_string obj(input_string);
obj.brute_approach();
obj.show();
std::cout << std::endl;
std::cout <<"Program temrinated succesfully" << std::endl;
}