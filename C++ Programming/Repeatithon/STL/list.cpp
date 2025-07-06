#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <list>
#include <utility>
#include <string>

int main(void){
	std::list<int> l1;

	l1.push_front(10);
	l1.push_front(20);
	l1.push_back(30);
	l1.push_back(40);
	l1.push_back(50);
	l1.push_back(60);
	
	std::list<std::pair<int, std::string>> l2;
	
	l2.emplace_front(10,"aditya");
	
	std::cout <<"Pair list" << std::endl;
	
	for(std::list<std::pair<int, std::string>>::iterator it = l2.begin(); it != l2.end(); ++it){
		std::cout << (*it).first <<" ";
		std::cout << (*it).second << " ";
	}

	std::cout << std::endl;			

        for(std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it){
                std::cout <<*it <<" ";
		std::cout <<*it <<" ";
	}

	std::cout <<"front()" << l1.front() << std::endl;
	std::cout <<"back()" << l1.back() << std::endl;

	std::cout<<"Pop front"<< std::endl;
	l1.pop_front();
	
	std::cout <<"pop back" << std::endl;
	l1.pop_back();
	
	for(std::list<int>::iterator it = l1.begin(); it != l1.end(); ++it)
		std::cout <<*it <<" ";
	
	l1.clear();
	std::cout << std::endl;	
	std::cout <<"Programe terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}
