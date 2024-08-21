#include "copy_file.h"

int main(int argc, char* argv[]){
	status_t status;

	if(argc < 3){
		fprintf(stderr, "UsageError: Not enough argument\n");
		exit(EXIT_FAILURE);
	} 
	const char* destination_string = NULL;
	destination_string = argv[argc - 1];

	for(size_t i = 1; i < argc - 1; ++i)
	{
		status = copyMultiFile(argv[i], destination_string);
		if(status != SUCCESS){
			fprintf(stderr, "ERROR IN OPENING FILE STATUS = %s\n", "FAILED");
			exit(EXIT_FAILURE);
		}
		printf("[%llu] FILE SUCCESFULLY COPYIED\n", i+1);
	}

	puts("Programme Terminated Sucessfully");
	exit(EXIT_SUCCESS);
}

