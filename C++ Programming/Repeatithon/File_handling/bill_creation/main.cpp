#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stirng>
#include <vector>

int main(int args, char* argv[]){
	if(args < 2){
		std::cout <<" " << std::endl;
		exit(EXIT_FAILURE);
	}
		
	std::vector<File> file;
	
	for(size_t i = 1 ; i < args; ++i){
		file.emplace_back(argv[i]);		
	}
	return EXIT_SUCCESS;
}
