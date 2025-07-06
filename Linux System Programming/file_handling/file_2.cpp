#include <cstdio>
#include <cstdlib>
#include <fcntl.h>
#include <cerrno>
#include <cstring>
#include <ctime>

#define SUCCESS 1
#define FALSE 	2
#define BUFFER	1024

typedef int status_t;

status_t copy_file(char* source_file, char* destination_file);
int main(int args, char* argv[]){
	if(args != 3){
		puts("Not enough argument");
		exit(EXIT_FAILURE);
	}
	status_t status = FALSE;
	char* source_file = argv[1];
	char* destination_file = argv[2];
	
	printf("source_file = %s\n", source_file);
	printf("destination_file = %s\n", destination_file);

	status = copy_file(source_file, destination_file);
	if(status != FALSE){
		puts("Success");
	}
	puts("Programe terminated succesfully");
	return EXIT_SUCCESS;
}

status_t copy_file(char* source_file, char* destination_file){

	FILE* read_fd = NULL;
	FILE* write_fd = NULL;
	FILE* log_fd = NULL;
	int write_byte = 0;
	int read_byte = 0;
	time_t current_time = 0;
	char* timeString = NULL;
	char rBuffer[BUFFER];
	log_fd = fopen("log.txt", "a+");
	if(log_fd == NULL){
		printf("Error in creating log_file = %s", strerror(errno));
		exit(EXIT_FAILURE);
	}
	read_fd = fopen(source_file, "r");
	if(read_fd == NULL){
		timeString = ctime(&current_time);
		fprintf(log_fd,"%s|%s|%s\n",timeString, source_file, strerror(errno));
		fflush(log_fd);
		exit(EXIT_FAILURE);	
	}
	write_fd = fopen(destination_file, "w");
	if(write_fd == NULL){
		timeString = ctime(&current_time);
                fprintf(log_fd,"%s|%s|%s\n",timeString, destination_file, strerror(errno));
                fflush(log_fd);
                exit(EXIT_FAILURE);
	}

	while((read_byte = fread(rBuffer, sizeof(char), BUFFER, read_fd)) > 0){
			write_byte = fwrite(rBuffer, sizeof(char), read_byte, write_fd);
			if(write_byte != read_byte){
				timeString = ctime(&current_time);
                		fprintf(log_fd,"%s|%s|%s\n",timeString, destination_file, strerror(errno));
                		fflush(log_fd);
                		exit(EXIT_FAILURE);
			}
			timeString = ctime(&current_time);
			fprintf(log_fd,"%s|%s|%s\n",timeString, destination_file,"data Write\n");
			fflush(log_fd);
	}
	if(read_byte == 0){
		timeString = ctime(&current_time);
        	fprintf(log_fd,"%s|%s|%s\n",timeString, source_file, strerror(errno));
                fflush(log_fd);
                exit(EXIT_FAILURE);
	}
	if(fclose(read_fd) == -1){
		timeString = ctime(&current_time);
        	fprintf(log_fd,"%s|%s|%s\n",timeString, source_file, strerror(errno));
       		fflush(log_fd);
                exit(EXIT_FAILURE);
	}

	if(fclose(write_fd) == -1){
                timeString = ctime(&current_time);
                fprintf(log_fd,"%s|%s|%s\n",timeString, destination_file, strerror(errno));
                fflush(log_fd);
                exit(EXIT_FAILURE);
        }
	 if(fclose(log_fd) == -1){
                timeString = ctime(&current_time);
                fprintf(stdout,"%s|%s|%s\n",timeString, "log.txt", strerror(errno));
                fflush(log_fd);
                exit(EXIT_FAILURE);
        }
	return SUCCESS;
}
