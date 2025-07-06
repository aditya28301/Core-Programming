#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>

void file_sort(char* file_name);
void sort_fun(std::vector<ssize_t> &vec, size_t l, size_t r);
void merge(std::vector<ssize_t> &vec, size_t l, size_t m, size_t r);

int main(int argc, char* argv[]){
	if(argc < 2){
		std::cerr <<"Not enouth argumnet" << std::endl;
		exit(EXIT_FAILURE);
	}
	char* file_name = 0;
	file_name = argv[1];
	file_sort(file_name);
	std::cout <<"Success" << std::endl;
	return EXIT_SUCCESS;
}

void merge(std::vector<ssize_t> &vec, size_t l, size_t m, size_t r){
	size_t left = l;
	size_t right = m + 1;
	size_t mid = m;
	std::vector<ssize_t> temp;

	while(left <= mid && right <=  r){
		if(vec[left] <= vec[right]){
			temp.push_back(vec[left]);
			++left;
		}	
		else{
			temp.push_back(vec[right]);
			++right;
		}	
	}  	

	while(left <= mid){
		temp.push_back(vec[left]);
		++left;
	}

	while(right <= r){
		temp.push_back(vec[right]);
		++right;
	}

	for(size_t i = l; i <= r ; ++i){
		vec[i] = temp[i - l];	
	}
}

void sort_fun(std::vector<ssize_t> &vec, size_t l, size_t r){
	if(l >= r)
		return;

	size_t mid = (l + r) / 2;
	sort_fun(vec, l, mid);
	sort_fun(vec, mid+1, r);
	merge(vec, l, mid, r);

}

void file_sort(char* file_name){
	std::ifstream read_file;
	read_file.open(file_name, std::ios::in);
	std::string line;
	std::vector<ssize_t> arr;
	if(read_file.is_open()){
		while(std::getline(read_file, line)){
			arr.push_back(stoi(line));	
		}
		read_file.close();
	} 
	else{
		std::cout <<"Unable to open a file" << std::endl;
		exit(EXIT_FAILURE);
	}	
	
	sort_fun(arr, 0, arr.size() - 1);

	std::ofstream write_file;
	write_file.open(file_name, std::ios::out);
	
	if(write_file.is_open()){
		for(size_t i = 0; i < arr.size(); ++i)
			write_file << arr[i] << std::endl;
	}
	else{
		std::cout <<"Unable to open file in write mode" << std::endl;
		exit(EXIT_FAILURE);
	}

	write_file.close();
}
