#include <iostream>
#include <string>

void strcpy_(char* destination, const char* source);
size_t strlen_(const char* string);

int main(void){
	const char* s1 = "aditya ashok darekarasdasdasdasdasdasdasasasdasdasasasd";
	char* s2 = new char[strlen_(s1) + 1];
	strcpy_(s2, s1);
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	return EXIT_SUCCESS;
}
size_t strlen_(const char* string){
	size_t len = 0;
	for(size_t i = 0; string[i] !='\0'; ++i){
		len += 1;
	} 
	return len;
}
void strcpy_(char* destination, const char* source){
	size_t len = 0;
	len = strlen_(source);	
	for(size_t i = 0; source[i] != '\0'; ++i){
		destination[i] = source[i];
	}
	destination[len] = '\0'
}
