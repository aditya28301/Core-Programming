#include <unistd.h>
#include <cerrno>
#include <iostream>
#include <cstdlib>
#include <cstring>

int global = 10;

int main(void){

	pid_t pid = fork();

	if(pid < 0 ){
		std::cerr <<"ERROR IN CREATING CHILD PROCESS REASON = " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	else if(pid == 0){
		std::cout <<"I AM CHILD PROCESS" << std::endl;
		for(size_t i = 0; i < 10; ++i){
			std::cout << i << std::endl;
		}
		//std::cout <<"I am child process = " << global <<std::endl;
	}
	else{
		std::cout <<"I am parent process = " << std::endl;
		 for(size_t i = 0; i < 5; ++i){
                        std::cout << i << std::endl;
                }
	}
	return EXIT_SUCCESS;
}
