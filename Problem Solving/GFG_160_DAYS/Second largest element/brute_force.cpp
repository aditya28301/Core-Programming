#include <cstdio> 
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>

void sort(size_t* arr, size_t size);
ssize_t second_largest(size_t* arr, size_t size);
void merge_sort(size_t* arr, size_t low, size_t high);
void merge(size_t* arr, size_t low, size_t mid, size_t high);

int main(int args, const char* argv[]){
	if(args < 2){
		fprintf(stderr, "Argument is not enough\n");
		return EXIT_FAILURE;
	}
	size_t size = std::stoi(argv[1]);
	
	if(size <= 0){
		fprintf(stderr, "Bad size allocation\n");
		return EXIT_FAILURE;
	}

	srand(time(0));
	size_t* arr = new size_t[size];

	for(size_t i = 0; i < size; ++i){
		arr[i] = rand() % 10000 + 1;
	}

	sort(arr, size);
	size_t sl = second_largest(arr, size);

	std::cout << std::endl << "Second largest element = " << sl << std::endl;

	std::cout << std::endl;
	delete[] arr;
	return EXIT_SUCCESS;
}

ssize_t second_largest(size_t* arr, size_t size){
	for(ssize_t i = size-2; i >= 0; --i){
		if(arr[i] != arr[size-1])
			return arr[i];
	}	
	return -1;
}

void sort(size_t* arr, size_t size){
	merge_sort(arr, 0, size-1);
}

void merge_sort(size_t* arr, size_t low, size_t high){
	if(low >= high)
		return;

	size_t mid = (low + high) / 2;
	merge_sort(arr, low, mid);
	merge_sort(arr, mid + 1, high);
	merge(arr, low, mid, high); 		
}

void merge(size_t* arr, size_t low, size_t mid, size_t high){
	std::vector <size_t> temp;
	
	size_t idx = low;
	size_t idx2 = mid+1;

	for(; idx <= mid && idx2 <= high;){
		if(arr[idx] <= arr[idx2]){
			temp.push_back(arr[idx]);
			++idx;
		}
		else{
			temp.push_back(arr[idx2]);
			++idx2;
		}
	}

	while(idx <= mid){
		temp.push_back(arr[idx]);
		++idx;
	}

	while(idx2 <= high){ 
		temp.push_back(arr[idx2]);
		++idx2;	
	}

	for(size_t i = low; i <= high; ++i){
		arr[i] = temp[i - low];
	}
}






