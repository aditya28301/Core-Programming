#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

size_t max_consecutive_count(std::vector<size_t>& vec);

int main(void){
	std::vector<size_t> vec={0, 0, 0, 0,  1, 1};
	size_t count = 0;
	
	count = max_consecutive_count(vec);
	std::cout <<"Maximum consecutive count is = " << count << std::endl;

	std::cout <<"Programme terminated sucesfully" << std::endl;
	return EXIT_SUCCESS;
}

size_t max_consecutive_count(std::vector<size_t>& vec){
	size_t count = 0;
	size_t final_count = 0;

	for(size_t i = 0 ; i < vec.size(); ++i){
			
		if(vec[i] == 0){
			if(count > final_count){
				final_count = count;
			}
			count = 0;
			continue;
		}
		++count;
	}

	if(count > final_count){
		final_count = count;	
	}
	
	return final_count;
}
