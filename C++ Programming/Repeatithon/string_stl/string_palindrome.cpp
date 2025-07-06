#include <iostream>
#include <cstring>

bool isPalindrom(const char* str);
int main(void){
	const char* str = "madam";
	std::cout << isPalindrom(str) << std::endl;
	return EXIT_SUCCESS;
}

bool isPalindrom(const char* string){
	size_t i = 0;
	size_t j = strlen(string) - 1;
	
	while(i < j){
		if(string[i] != string[j]){
			return false;
		}
		++i;
		--j;
	}
	return true;
}

