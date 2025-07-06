#include <cstdlib>
#include <signal.h>
#include <unistd.h>
#include <iostream>
int main(void){

	pid_t pid = getpid();
	
	if((kill(pid, 2) != -1)){
		std::cout <<"PROCESS KILL" << std::endl;
	}
	return EXIT_SUCCESS;
}
