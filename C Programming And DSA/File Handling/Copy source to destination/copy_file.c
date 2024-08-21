#include "copy_file.h"

status_t copyFile(const char* source_string, const char* destination_string)
{
	char buffer[BUFFER_SIZE];

	FILE* hFile1 = NULL;
	FILE* hFile2 = NULL;
		
	hFile1 = fopen(source_string, "r");
	if(hFile1 == NULL){
		fprintf(stderr, "Error in opening file");
		fclose(hFile1);
		return(EXIT_FAILURE);
	}

	hFile2 = fopen(destination_string, "w");
	if(hFile2 == NULL){
		fprintf(stderr, "Error in opening file");
		fclose(hFile2);
		return(EXIT_FAILURE);
	}

	while(fgets(buffer, BUFFER_SIZE, hFile1) != NULL){
		fputs(buffer, hFile2);
		memset(buffer, 0, BUFFER_SIZE);
	}		

	fclose(hFile1);
	fclose(hFile2);
	
	hFile1 = NULL;
	hFile2 = NULL;
	
	return (SUCCESS);
}