#include <iostream>
#include <fstream>
#include <cerrno>
#include <cstring>

using namespace std;
int main(void){
	
	fstream read_file("source.txt", ios::in);
	if(!read_file.is_open()){
		std::cerr <<"ERROR IN OPENING FILE = " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	fstream write_file("destination.txt", ios::in | ios::out);
	if(!write_file.is_open()){
		 std::cerr <<"ERROR IN OPENING FILE = " << strerror(errno) << std::endl;
                exit(EXIT_FAILURE);
	}
	std::string line;
		while (getline(read_file, line)) {
        	// Write the line and add back the newline that getline removed
        	if (!(write_file << line << '\n')) {
            		std::cerr << "ERROR WRITING TO FILE: " << strerror(errno) << std::endl;
            		return EXIT_FAILURE;
        	}
    	}
	
	
	read_file.close();
	write_file.close();
	return EXIT_SUCCESS;
}
