#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

class countWord{
    private:

        std::string source_file;
        std::ifstream file_read;
        size_t count;    
    public:
        countWord(std::string s_file) : source_file(s_file), file_read(s_file), count(0){
            std::cout <<"Log:: file path is passed constructor called here" << std::endl;
        }

        ~countWord(){
            std::cout <<"File close now" << std::endl;
            file_read.close();
        }

        void f_countWord(){
            std::string line;

             if(file_read.eof() == true){
                std::cout <<"End of file reached" << std::endl;
                file_read.close();
                return;
            }

            while(std::getline(file_read, line)){
                for(std::size_t i = 0; i != line.size(); ++i){
                    ++count;
                }
            }

            if(file_read.eof() == true){
                std::cout <<"End of file reached" << std::endl;
                file_read.close();
                return;
            }

            else if(file_read.fail() == true){
                std::cout <<"Logical error" << std::endl;
                file_read.close();
                exit(EXIT_FAILURE);
            }
            else{
                std::cout <<"Physical error" << std::endl;
                file_read.close();
                exit(EXIT_FAILURE);
            }
        }

        inline size_t get_count(){
            return count;
        }
};

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cerr <<"Not enough argument" << std::endl;
        exit(EXIT_FAILURE);
    }
    size_t count = 0;
    countWord obj1(argv[1]);
    obj1.f_countWord();
    std::cout <<"Count of character is = " << obj1.get_count() << std::endl;
    std::cout <<"Programe terminated sucessfully" << std::endl;
    return EXIT_SUCCESS;
}