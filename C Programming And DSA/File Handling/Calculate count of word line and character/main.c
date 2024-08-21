#include "wordCount.h"

int main(int argc, char* argv[]){
	status_t status;
	if(argc < 2){
		fprintf(stderr, "NOT ENOUGH ARGUMENT\n");
		return (EXIT_FAILURE);
	}
	status = wordCount(argc, argv);
	if(status != SUCCESS)	
		puts("UNABLE TO OPEN FILE");
	puts("PROGRAMME TERMINATED SUCCESFULLY");
	return (EXIT_SUCCESS);
}