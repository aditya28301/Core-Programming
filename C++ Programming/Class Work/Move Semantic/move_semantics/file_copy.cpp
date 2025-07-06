#include <iostream> 
#include <fstream> 
#include <string> 
#include <cstdlib> 
#include <cassert> 

int main(int argc, char* argv[])
{
    assert(argc >= 3); 

    std::fstream f_dest(argv[argc-1]); 
    f_dest.open(argv[argc-1], std::fstream::out | std::fstream::app); 
    
    for(int i = 1; i < argc-1; ++i)
    {
        std::fstream f_src(argv[i]); 
        f_src.open(argv[i], std::fstream::in); 
        
        std::string line; 
        while(f_src >> line)
            f_dest << line << std::endl; 

        f_src.close(); 
    }

    f_dest.close(); 

    return (0); 
}

// # app.exe src1.txt src2.txt src3.txt         srcn.txt dest.txt 
