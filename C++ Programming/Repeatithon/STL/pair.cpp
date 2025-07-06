#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <utility>

int main(void){

	std::pair<int, int> p;
	p.first = 10;
	p.second = 20;

	std::cout << p.first << p.second << std::endl;

	std::pair<int, std::pair<int, int>> p2;
	
	p2.first = 100;
	p2.second.first = 200;
	p2.second.second = 300;

	std::cout << p2.first << std::endl;
	std::cout << p2.second.first << std::endl;
	std::cout << p2.second.second << std::endl;
					
	return EXIT_SUCCESS;
}
