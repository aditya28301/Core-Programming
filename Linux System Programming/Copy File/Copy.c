#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#define 	BUFFER_SIZE	 4096
#define		TRUE		 1
#define 	FALSE		 0

typedef 	int status_t;

void 	Copy_file(int argc, char** argv);
void 	copy_(const char* source_file_path, const char* destination_file_path);
void 	print_help(void);
void	print_version(void);

int main(int argc, char* argv[]){
	if(argc == 1){
        	fprintf(stderr, "Usage error %s argument not enough\n", argv[0]);
        	exit(EXIT_FAILURE);
	}

    Copy_file(argc, argv);
    return EXIT_SUCCESS;
}

void print_version(void)
{
	puts("2024.1");
}
void Copy_file(int argc, char** argv){
	int ret;
	char* source_file_path = NULL;
	char* destination_file_path = NULL;

	status_t source_set = FALSE;
	status_t destination_set = FALSE;
	
	while((ret = getopt(argc, argv, "hs:vd:")) != -1){
		switch((char)ret){
			
			case 'v':
				print_version();
				exit(EXIT_SUCCESS);


			case 'h':
				print_help();
				exit(EXIT_SUCCESS);
			case 's':
				source_file_path = optarg;
				source_set = TRUE;			
					break;

			case 'd':
				destination_file_path = optarg;
				destination_set = TRUE;
					break;

			default:
				print_help();
				exit(EXIT_FAILURE);
					break;					
		}
	}
		
	if(source_set != destination_set)
	{
		print_help();
		exit(EXIT_FAILURE);		
	}

	if(source_set && destination_set)
	{
		copy_(source_file_path, destination_file_path);
		
	}

}

void print_help(void)
{
	static const char* str_msg =	"./Copy -h\tfor help\n\
./Copy -v\tfor help";
	puts(str_msg);	
}

void copy_(const char* source_file_path, const char* destination_file_path)
{
	int 	fd_src = -1;
	int 	fd_dest = -1;
	char 	buffer[BUFFER_SIZE];
	ssize_t read_byte;
	ssize_t write_byte;

	fd_src = open(source_file_path, O_RDONLY);
	if(fd_src == -1)
	{
		fprintf(stderr, "Source File Opening error path = %s , %s\n", source_file_path, strerror(errno));
		exit(EXIT_FAILURE);
	}

	fd_dest = open(	destination_file_path,
		O_RDWR	| 	O_CREAT  |	O_TRUNC,
		S_IRUSR	|	S_IWUSR  | 	S_IRGRP |	S_IROTH
		);


	if(fd_dest == -1)
	{
		fprintf(stderr, "Error in opening destination file = %s, %s\n", destination_file_path, strerror(errno));
	}
	
	while((read_byte = read(fd_src, buffer, BUFFER_SIZE)) > 0)
	{
		write_byte = write(fd_dest, buffer, read_byte);
		if(write_byte != read_byte)
		{
			fprintf(stderr, "Error in writing the file = %s, %s\n", destination_file_path, strerror(errno));
			exit(EXIT_FAILURE);
		}
	}
	
	
	if(read_byte == -1)
	{
		fprintf(stderr, "Error in reading the file = %s, %s\n", source_file_path, strerror(errno));	
		exit(EXIT_FAILURE);
	}		
	
	if(close(fd_src) == -1)
	{
		fprintf(stderr, "Error in closing file = %s, %s\n", source_file_path, strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(close(fd_dest) == -1)
	{
		fprintf(stderr, "Error in closing file = %s, %s\n", destination_file_path, strerror(errno));
		exit(EXIT_FAILURE);
	}	

	
	puts("Congratulation you file are sucessfully Copy");	
		
}
