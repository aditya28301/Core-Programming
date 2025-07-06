#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define TRUE 	1
#define FALSE	0
#define BUFFER 	4096

char* 	ignoreBlank(const char* source_file);
void	f_print(const char* source_file);
size_t 	split(const char* orginalString, char*** splitBuffer);
 
int 	main(int argc, char* argv[]){

	if(argc < 2){
		fprintf(stderr, "Not enough argument\n");
		exit(EXIT_FAILURE);
	}

	char* switchOption = (char*)calloc(argc + 1, sizeof(char));
	if(switchOption == NULL){
		fprintf(stderr, "Error in allocating the meomary\n");
		exit(EXIT_FAILURE);
	}
	
	char* current_string =  NULL;
	char* source_file = NULL;
	int count = 0;
	for(size_t i = 1; i < argc; ++i){
		current_string = argv[i];
		if(current_string[0] == '-' && current_string[1] != '\0'){
			switchOption[count++] = current_string[1]; 
		}
		else{
			source_file = current_string;
			count = 1;
		}
	} 

	switchOption[count] = '\0';
	
	int print = FALSE;
	int blank = FALSE;

	for(int i = 0; i < count; ++i){
		//puts("enter in switch for loop");
		switch(switchOption[i]){
			case 'v':
				print = TRUE;
				//puts("print");
				break;
			case 's':
				blank = TRUE;
				//puts("blank");
				break;
			default:
				print = TRUE;
				blank = TRUE;
				//puts("print");
				//puts("blank");
				break;			
		}
	}
	char* destination_file = NULL;
	if(print == TRUE && blank == TRUE){
		destination_file = ignoreBlank(source_file);
		f_print(destination_file);
	}
	else if(print == TRUE){
		f_print(source_file);
	}

	free(switchOption);
	switchOption = NULL;
	puts("");
	puts("Programe terminated succesfully");
	return(EXIT_SUCCESS);
}

char* ignoreBlank(const char* source_file){
	int fd_read = 0;
	int fd_write = 0;
	ssize_t read_byte = 0;
	size_t len = 0;
	int should_write = FALSE;
	int write_byte = 0;
	char buffer[BUFFER + 1];
	static const char destination_file[] = "save_text.txt";
	char** splitBuffer = NULL;
	size_t splitBufferLen = 0;

	fd_read = open(source_file, O_RDONLY);
	if(fd_read == -1){	
		fprintf(stderr, "Error in opening file in read mode = %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	fd_write = open("save_text.txt", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if(fd_write == -1){
		fprintf(stderr, "Error in opening file in write mode = %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	} 

	while((read_byte = read(fd_read, buffer, BUFFER)) > 0){
		buffer[read_byte] = '\0';
		splitBufferLen = split(buffer, &splitBuffer);
		len  = strlen(buffer);
		char* current_string = NULL;
		for(size_t i = 0; i < splitBufferLen; ++i){
			should_write = FALSE;
			current_string = splitBuffer[i];
			for(int j = 0; j < strlen(current_string); ++j){ 
				if(current_string[j] != ' ' && current_string[j] != '\n' && current_string[j] != '\t'){
					should_write = TRUE;
					break;
				}
			}						
				if(should_write){
					write_byte = write(fd_write, current_string, strlen(current_string));
					if(write_byte != (ssize_t)strlen(current_string)){
						fprintf(stderr, "Error in writing data into the file= %s\n",
						strerror(errno));
						close(fd_read);
						close(fd_write);
						exit(EXIT_FAILURE);
					}
					write(fd_write, "\n", 1);		
				}
			}
		}

	for(size_t i = 0; i < splitBufferLen; ++i){
		free(splitBuffer[i]);
		splitBuffer[i] = NULL;
	}
	free(splitBuffer);	
	splitBuffer = NULL;

	if(close(fd_read)){
		fprintf(stderr, "Error occured closing file =%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if(close(fd_write)){
		fprintf(stderr, "Eror occured closing file = %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	return (char*)destination_file;
}

void f_print(const char* destination_file){
	int fd_read = 0;
	ssize_t read_byte = 0;
	char buffer[BUFFER];
	
	fd_read = open(destination_file, O_RDONLY);
	if(fd_read  == -1){
		fprintf(stderr, "Error in opening file in read mode =%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	while((read_byte = read(fd_read, buffer, BUFFER)) > 0){
		write(STDOUT_FILENO, buffer, read_byte);
	}

	if(close(fd_read)){
		fprintf(stderr, "Error in closing the file = %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
	
size_t split(const char* originalString, char*** splitBuffer){	
	size_t	count = 0;
	size_t 	len = strlen(originalString);
	size_t 	countByte = 0;
	char* 	stringConcat = NULL;
	char** 	tempSplitBuffer = NULL;

	stringConcat = (char*)calloc(BUFFER + 1, sizeof(char));
	if(stringConcat == NULL){
		fprintf(stderr, "Error in allocating the meomary");
		exit(EXIT_FAILURE);
	}
	
	for(size_t i = 0; i <= len; ++i){
		if(originalString[i] == '\n' || originalString[i] == '\0'){
			stringConcat[count] = '\0';
			tempSplitBuffer = (char**)realloc(tempSplitBuffer, (countByte + 1) *  sizeof(char*));
			countByte += 1; 
			tempSplitBuffer[countByte - 1] = stringConcat;
			stringConcat = NULL;
			if(i < len){
				stringConcat  = (char*)calloc(BUFFER + 1, sizeof(char));
				if(stringConcat == NULL){
					fprintf(stderr, "Error in allocating the meomary");	
					exit(EXIT_FAILURE);
				}
			}	
			count = 0;
		}
		else{
			stringConcat[count++] = originalString[i];
		}
	}
	*splitBuffer = tempSplitBuffer;
	return countByte;
}
