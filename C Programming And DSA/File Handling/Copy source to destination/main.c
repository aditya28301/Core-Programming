#include "copy_file.h"

int main(int argc, char* argv[]){
	status_t status;

	if(argc != 3){
		fprintf(stderr, "UsageError: Not enough argument\nsourcefile= %s,destination file= %s", argv[1], argv[2]);
		exit(EXIT_FAILURE);
	} 
	
	status = copyFile(argv[1], argv[2]);
	if(status != SUCCESS){
		fprintf(stderr, "ERROR IN OPENING FILE STATUS = %s\n", "FAILED");
		exit(EXIT_FAILURE);
	}

	puts("Programme Terminated Sucessfully");
	exit(EXIT_SUCCESS);
}

