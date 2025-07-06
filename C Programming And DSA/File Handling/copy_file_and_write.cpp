#include <cstdio>
#include <cstring>
#include <cerrno>
#include <iostream>

#define BUFFER_SIZE 4096

int main(void){

	FILE* fps = fopen("source.txt", "r");
	if(fps == NULL){
		printf("ERROR IN OPENING FILE = source.txt =, REASON %s", strerror(errno));
		exit(EXIT_FAILURE);
	}

	FILE* fpd = fopen("destination.txt", "w+");
	if(fpd == NULL){
		printf("ERROR IN OPENING FILE = source.txt =, REASON %s", strerror(errno));
                exit(EXIT_FAILURE);
	}

	char read_string[BUFFER_SIZE];
	size_t write_byte;
	while(fgets(read_string, BUFFER_SIZE, fps) != NULL){
		fputs(read_string, fpd);
		if(ferror(fpd))
		{
			//std::cout << strlen(read_string) << std::endl;
			//std::cout << write_byte << std::endl;
			printf("ERROR IN WRITING CHAR FILE = Source.txt, REASON = %s", 
			strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	if(fclose(fps) == EOF){
		printf("ERROR IN CLOSING FILE = source.txt =, REASON %s", strerror(errno));
		exit(EXIT_FAILURE);
	}

	if(fclose(fpd) == EOF){
        	printf("ERROR IN CLOSING FILE = destination.txt =, REASON %s", strerror(errno));
                exit(EXIT_FAILURE);
        }

	return EXIT_SUCCESS;
}

