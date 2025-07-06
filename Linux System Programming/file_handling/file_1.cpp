#include <cstdlib>
#include <cstdio>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <cstring>

#define BUFFER 1024
#define SUCCESS 1
#define FAILURE 0

typedef int status_t;

status_t copy_data(char* source_file, char* destination_file);
int main(int argc, char* argv[]){

	if(argc != 3){
		puts("Not enought argument");
		exit(EXIT_FAILURE);
	}

	char* source_file_path = NULL;
	char* destination_file_path = NULL;
	status_t status = FAILURE;

	source_file_path = argv[1];
	destination_file_path = argv[2];

	printf("Source_path = %s\n", source_file_path);
	printf("Destination_path = %s\n", destination_file_path);
	status = copy_data(source_file_path, destination_file_path);
	if(status == SUCCESS){
		puts("SUCCESS");
	}

	puts("Programe terminated sucesfully");
	return EXIT_SUCCESS;
}

status_t copy_data(char* source_file, char* destination_file){
	
	int read_fd;
	int write_fd;
	char rBuffer[BUFFER];
	int read_byte;
	int write_byte;

	read_fd = open(source_file, O_RDONLY);
	if(read_fd == -1){
		printf("Error in opening file = %s", strerror(errno));
		return EXIT_FAILURE; 
	}
	write_fd = open(destination_file, O_RDWR | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IROTH);
	if(write_fd == -1){
		printf("Error in opening file in write mode = %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	while((read_byte = read(read_fd, rBuffer, BUFFER)) > 0){
		write_byte = write(write_fd, rBuffer, read_byte);
		if(write_byte == -1){
			printf("Error occured on writing file = %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
		if(write_byte != read_byte){
			printf("Error in write byte in a file = %s", strerror(errno));
			exit(EXIT_FAILURE);
		}
	} 

	if(close(read_fd) == -1){
		printf("Error in closing the file = %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	if(close(write_fd == -1)){
		printf("Error in closing the file = %s", strerror(errno));
		exit(EXIT_FAILURE);
	}

	return SUCCESS;
}
