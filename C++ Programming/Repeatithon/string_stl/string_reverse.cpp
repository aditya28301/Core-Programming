#include <iostream>
#include <cstring>

void strrev_(char* str);
void swap(char& s1, char& s2);

int main(void){
	char str[]= "aaaaaaaaaaaaaaaaaaaad";            
	strrev_(str);
	std::cout << str << std::endl;
	return EXIT_SUCCESS;
}	

void swap(char& s1, char& s2){
	char temp = 0;
	temp = s1;
	s1 = s2;
	s2 = temp;
}

void strrev_(char* str){

	size_t i = 0;
	size_t j = strlen(str) - 1;

	while(i < j){
		swap(str[i], str[j]);
		++i;
		--j;
	}
}
