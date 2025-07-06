#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>


int main(void){
	std::vector<int> vec;

	vec.push_back(1200);
	vec.emplace_back(1300);
	
	std::cout << vec[0] << std::endl;
	std::cout << vec[1] << std::endl;
	std::cout << vec[2] << std::endl;
	std::vector<int> vec2(5,19);
	std::cout << "Size of vector = " << vec2.size() << std::endl;
	for(std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
		std::cout << *it << std::endl;			
	
	std::cout <<"deleting the element" << std::endl;
	vec2.erase(vec2.begin());
	for(std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
                std::cout << *it << std::endl;

	std::cout <<"Deleteing the element from start and end" << std::endl;	
	vec2.erase(vec2.begin() + 1, vec2.begin() + 2); 	
	for(std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
                std::cout << *it << std::endl;	

	std::cout <<"inserting the element" << std::endl;
	vec2.insert(vec2.begin(), 100);
	for(std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
        	std::cout << *it << std::endl;		

	std::cout <<"Inserting the two occurence" << std::endl;
	vec2.insert(vec2.begin() + 1, 2, 200);

	 for(std::vector<int>::iterator it = vec2.begin(); it != vec2.end(); ++it)
                std::cout << *it << std::endl;			
	return EXIT_SUCCESS;
}
