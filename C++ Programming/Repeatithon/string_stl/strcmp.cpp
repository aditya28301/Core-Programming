#include <iostream>
#include <string>

using status_t=long long int;

status_t string_compare(const char* s1, const char* s2);

int main(void){
	const char* s1 = "A";
	const char* s2 = "";	
	status_t ret;

	ret = string_compare(s1, s2);
	if(ret == 0){
		std::cout <<"BOTH STRING ARE SAME = " << ret << std::endl;
	}
	else if(ret > 0){
		std::cout <<"FIRST STRING IS GREATER THAN SECOND = " << "1" <<std::endl;
	}
	else{
		std::cout <<"FIRST STRING IS SMALLER THAN SECOND = " << "-1" << std::endl;
	}	
	
	std::cout <<"Programe terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}

status_t string_compare(const char* s1, const char* s2){
	size_t i = 0;

	while(s1[i] != '\0' && s2[i] != '\0'){	
		std::cout <<(unsigned char)s1[i] <<" " << (unsigned char)s2[i] << std::endl;
		if(s1[i] != s2[i]){
			//std::cout <<(size_t)s1[i] <<" " << (size_t)s2[i] << std::endl;
			return (static_cast<unsigned char>(s1[i]) - static_cast<unsigned char>(s2[i])); 	
		}
		++i;
	}
	//std::cout <<(size_t)s1[i] <<" " << (size_t)s2[i] << std::endl;
	return (static_cast<unsigned char>(s1[i]) - static_cast<unsigned char>(s2[i]));
}
