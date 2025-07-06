#include <fcntl.h>
#include <unistd.h>
#include <cerrno>
#include <getopt.h>
#include <iostream>
#include <cstring>

typedef int status_t;
const int BUFFER_SIZE = 4096;

void print_help(void);
void copy_file(const char* source_path, const char* destination_path);
void lowerToUpper(char* input_string);

int main(int argc, char* argv[]){

	size_t ret = 0;
	char* source_path = NULL;
	char* destination_path = NULL;
	const char* option_str = "s:d:";
	status_t source_status = false;
	status_t destination_status = false;

	while((ret = getopt(argc, argv, option_str))  != -1){
	
		switch((char)ret){
			
			case 's':
				if(optarg){
					source_status = true;
					source_path = optarg;
				}
				break;
			case 'd':
				if(optarg){
					destination_status = true;
					destination_path = optarg;
				}
				break;
			default:
				print_help();
				exit(EXIT_FAILURE);
		}
	}

	if(source_status != destination_status){
		print_help();
		exit(EXIT_FAILURE);
	}

	if(source_status && destination_status){
		copy_file(source_path, destination_path);
	}
	std::string str = std::string("vim ") + destination_path;
	system(str.c_str());
	
	return EXIT_SUCCESS;
}

void copy_file(const char* source_path, const char* destination_path){

	int fd_source;
	int fd_dest;
	size_t write_byte;

	fd_source = open(source_path, O_RDONLY);
	if(fd_source == -1){	
		std::cerr <<"ERROR IN OPENING FILE = "
		<< source_path <<"REASON = " << strerror(errno) << std::endl;
	}

	FILE* fp_src = fdopen(fd_source, "r");
	if(fp_src == NULL){
		std::cerr <<"ERROR IN OPENIING FILE = " << source_path 
		<<"REASON = " << strerror(errno) << std::endl; 
		close(fd_source);
		exit(EXIT_FAILURE);
	}
	
	fd_dest = open(destination_path, O_RDWR | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IROTH);
	if(fd_dest == -1){
		std::cerr <<"ERROR IN OPENING FILE = " << destination_path 
		<<"REASON = " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}

	FILE* fp_dest = fdopen(fd_dest, "w+");
        if(fp_dest == NULL){
                std::cerr <<"ERROR IN OPENIING FILE = " << destination_path
          	<<"REASON = " << strerror(errno) << std::endl;
                close(fd_dest);
                exit (EXIT_FAILURE);
        }

	char* line = (char*)malloc(BUFFER_SIZE + 1);
	while(fgets(&line[0], BUFFER_SIZE, fp_src) != NULL){
		if(ferror(fp_src)){
			std::cerr <<"ERROR IN READING FILE = " << source_path 
			<<"REASON = " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
		lowerToUpper(&line[0]);
		write_byte = write(fd_dest, line, strlen(line));
		if(write_byte != strlen(line)){
			std::cerr <<"ERROR IN A WRITING = " << destination_path 
			<<"REASON = " <<strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
	}	

	if(close(fd_source) == -1){
		std::cerr <<"ERROR IN CLOSING FILE = " <<source_path 
		<<"REASON = " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	
	if(close(fd_dest) == -1){
		std::cerr <<"ERROR IN CLOSING FILE = " << destination_path 
		<<"REASON = " << strerror(errno) << std::endl;
		exit(EXIT_FAILURE);
	}
	
	std::cout <<"LOWER CASE TO UPERCASE = DONE" << std::endl;
	std::cout <<"FILE COPIED SUCCSFULLY" << std::endl;
	
	free(line);
	line = 0;
}	

void lowerToUpper(char* input_string){
	unsigned char uppercase = 0;
	for(size_t i = 0; input_string[i] != '\0'; ++i){
		if(input_string[i] >= 'a' && input_string[i] <= 'z'){
			uppercase = (unsigned char)input_string[i] - 32;
			input_string[i] = (char)uppercase;
		}		
	}
}

void print_help(void){

	std::cout <<"-s - Source path" << std::endl;
	std::cout <<"-d - Destination path" << std::endl;
}

