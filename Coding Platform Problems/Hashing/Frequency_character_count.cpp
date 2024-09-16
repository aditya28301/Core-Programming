    #include <cstdio>
    #include <cstdlib>
    #include <iostream>
    #include <ctime>

    typedef unsigned long long int data_t;  
    void frequency_count(std::string s, data_t size);

    int main(void){
         std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                             "abcdefghijklmnopqrstuvwxyz"
                             "0123456789"
                             "!@#$%^&*()-_=+[]{}|;:,.<>?/";


        std::string long_string;
        int length = 100000000000000;  // Desired length of the string

        for (int i = 0; i < length; ++i) {
            long_string += characters[rand() % characters.size()];
        }
        // char* c_arr = 0;
        // std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        //                    "abcdefghijklmnopqrstuvwxyz"
        //                    "0123456789"
        //                    "!@#$%^&*()-_=+[]{}|;:,.<>?/";
        frequency_count(long_string, long_string.size()); 
        std::cout <<"Program terminated sucessfully";
        return 0;
    }

    void frequency_count(std::string s, data_t size){   
        data_t* hash_array = new data_t[256]();
        bool isPrinted[256] = {false};
        for(size_t i = 0; i < size; ++i){
            if(s[i] >= 'A' && s[i] <= 'Z')
                hash_array[s[i] - 'A'] += 1;
            else if(s[i] >= 'a' && s[i] <= 'z')
                hash_array[s[i] - 'a'] += 1;
            else
                hash_array[s[i]] += 1;
        }
        
        for(size_t i = 0; i < size; ++i){
            if((s[i] >= 'A' && s[i] <= 'Z') && isPrinted[s[i] - 'A'] == false){
                std::cout <<"char = " << s[i] << " " << "count = " << hash_array[s[i] - 'A'] << std::endl; 
                isPrinted[s[i] - 'A'] = true;
            }

            else if(((s[i] >= 'a' && s[i] <= 'z')) && (isPrinted[s[i] - 'a'] == false)){
                std::cout <<"char = " << s[i] << " " << "count = " << hash_array[s[i] - 'a'] << std::endl; 
                isPrinted[s[i] - 'a'] = true;
            }
            else{
                if((isPrinted[s[i]] == false)){
                    std::cout <<"char = " << s[i] << " " << "count = " << hash_array[s[i]] << std::endl; 
                    isPrinted[s[i]] = true;
                }       
            }
        }
        delete[] hash_array;
        hash_array = 0;
    }

    /*  10  2   3   10  1   */
