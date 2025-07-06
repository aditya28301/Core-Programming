#include <unistd.h>
#include <iostream>

int main(void){

	pid_t pid;
	int x;
	x = fork();

	if(x == 0){
		std::cout <<"This is the child process X = " << x <<"," << std::endl;
		execlp("xclock");
	}
	else{
		std::cout <<"This is the parent process X = " << x <<"," << std::endl;
	}

	return EXIT_SUCCESS;
}
