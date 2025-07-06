#include "wordCount.h"

status_t wordCount(int count, char* string[]){
	char buffer[BUFFER_SIZE];
	FILE* file = NULL;

	size_t word = 0;
	size_t line = 0;
	size_t character = 0;
	size_t Total = 0;

	printf("LINE\t\tWORD\t\tCHAR\n");
	puts("------\t\t----\t\t----");
	for(size_t i = 1; i < count; ++i){
		word = 0;
		line = 0;
		character = 0;

		file = fopen(string[i], "r");
		if(file == NULL){
			fprintf(stderr, "ERROR OCCURED WHILE OPENING THE FILE\n");
			continue;
		}

		while(fgets(buffer, BUFFER_SIZE, file) != NULL){ 
			line+= 1;
			fileCount(buffer, &word, &line, &character);
			memset(buffer, 0, BUFFER_SIZE);
		}
		Total+= line;
		printf("%zu\t\t%zu\t\t%zu\n", line, word, character);
		fclose(file);
		file = NULL;
	}
	printf("Total lines are = %llu\n", Total);
	return (SUCCESS);
}

void fileCount(const char* buffer, size_t* word, size_t* line, size_t* ch){
	int inword = 0;
	
	for(size_t i =0 ; buffer[i] != '\0'; ++i)
	{
		if(buffer[i] != ' '  && buffer[i] != '\n' && buffer[i] != '\t')
		{
			*ch = *ch + 1;
			if(!inword)
			{
				*word = *word + 1;
				inword = 1;
			}
		}

		else
		{
			inword = 0;
		}
	}
}