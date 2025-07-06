#include <cstdlib>
#include <iostream>
#include <cerrno>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <getopt.h>
#include <cstring>

const int BUFFER_SIZE = 4096;

void print_version();
void print_help();
void copy_file(const char* source_path, const char* destination_path);

char buffer[BUFFER_SIZE];

int main(int argc, char* argv[]){

	if(argc == 1){
		std::cerr<<"Not enough argument" << std::endl;
		exit(EXIT_FAILURE);
	}
	
	const char* source_path = 0;
	const char* destination_path = 0;
	const char* option = "hvs:d:";
	int option_return;
	bool source_flag = false;
	bool destination_flag = false;

	while((option_return = getopt(argc, argv, option)) != -1){
		switch(option_return){
			case 'v':
				print_version();
				exit(EXIT_SUCCESS);
		
			case 'h':
				print_help();
				exit(EXIT_SUCCESS);
		
			case 's':
				source_flag = true;
				source_path = optarg;
				break;
			case 'd':
				destination_flag = true;
				destination_path = optarg;
				break;

			default:
				print_help();
				exit(EXIT_FAILURE);
		}
	}

	if(source_flag != destination_flag){
		print_help();
		exit(EXIT_FAILURE);
	}


	if(source_flag && destination_flag){
		copy_file(source_path, destination_path);
	}
	
	std::string command = std::string("vim ") + source_path;
	system(command.c_str());
	return EXIT_SUCCESS;
}

	void copy_file(const char* source_path, const char* destination_path){
	
	// File open in read mode
	
		int file_descriptor_source;
		int file_descriptor_destination;
		size_t read_byte = 0;
		size_t write_byte = 0;

		file_descriptor_source = open(source_path, O_RDONLY);
		if(file_descriptor_source == -1){
			std::cerr <<"Failed to open source_file = " << source_path <<"Reason() = " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}

		file_descriptor_destination = open(destination_path,
						O_RDWR | O_CREAT | O_TRUNC,
						S_IRUSR | S_IWUSR | S_IROTH
					);

		if(file_descriptor_destination == -1){
			std::cerr <<"Failed to open destination file = " << destination_path <<"Reason = " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}	 

		
		while((read_byte = read(file_descriptor_source, buffer, BUFFER_SIZE)) > 0){
			write_byte = write(file_descriptor_destination, buffer, read_byte);
			if(read_byte != write_byte){
				std::cerr <<"Failed to write file = " << destination_path <<"reason = " << strerror(errno) << std::endl;
				exit(EXIT_FAILURE);
			}
			
		}

		if(read_byte == -1){
			std::cerr <<"read error in reading = " << source_path << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}
	
		if(close(file_descriptor_source) == -1){
			std::cerr << "Error in closing the file = " << source_path <<"Reason = " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}

		if(close(file_descriptor_destination) == -1){
			std::cerr <<"Error in closing the file = " << destination_path <<"Reason = " << strerror(errno) << std::endl;
			exit(EXIT_FAILURE);
		}	 

	std::cout <<"FILE SUCCESFULLY COPIED" << std::endl;
	std::cout <<"SOURCE FILE = " << source_path << std::endl;
	std::cout <<"DESTINATION FILE = " << destination_path << std::endl;
}

void print_help(){
	std::cout <<"h for help" << std::endl;
	std::cout <<"v for version" << std::endl;
	std::cout <<"s for soruce_file" << std::endl;
	std::cout <<"d for destination_file" << std::endl;
}

void print_version(){
	std::cout <<"Version = 1.0.1" << std::endl;
}
