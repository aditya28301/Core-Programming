/*
ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम्।
उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात्॥
*/
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm> // For sorting the vector

const int COUNT = 10;

std::vector<size_t> find_missing_number(std::vector<size_t>& vec);
int brute_force_find_missing_number(std::vector<size_t>& vec, size_t N);
int better_find_missing_number(std::vector<size_t>& vec, size_t N);
int optimal_find_missing_number(std::vector<size_t>& vec, size_t N);

std::vector<size_t> find_missing_number(std::vector<size_t>& vec)
{
	std::vector<size_t> temp;
	for(size_t i = 0; i < vec.size() - 1; ++i){
		if((vec[i] + 1) != vec[i + 1])
			temp.push_back(vec[i] + 1);
	}			
	return temp;
}

int main(void){
	std::vector<size_t> vec ={1, 2, 3, 5};

	int missing_number = -1;
	missing_number = optimal_find_missing_number(vec, 5);
	
	std::cout <<"Missing number is = " << missing_number << std::endl;
	return EXIT_SUCCESS;
}

int optimal_find_missing_number(std::vector<size_t>& vec, size_t N){
	int xor_vector_number_add = 0;
	int xor_one_to_n_add = 0;	
	int missing_number = 0;

	for(size_t i = 0; i < N - 1; ++i){
		xor_vector_number_add = xor_vector_number_add ^ vec[i];
		xor_one_to_n_add = xor_one_to_n_add ^ (i + 1);
	}
                                                                                                   
	xor_one_to_n_add = xor_one_to_n_add ^ N;
	
	missing_number = xor_vector_number_add ^ xor_one_to_n_add;

	return missing_number;	
}
int better_find_missing_number(std::vector<size_t>& vec, size_t N){
	int vector_number_addition = 0;
	int one_to_n_addition = 0;
	int missing_number = 0;
	
	for(size_t i = 0; i < vec.size(); ++i){
		vector_number_addition = vector_number_addition + vec[i];
	}			

	for(size_t i = 1; i <= N; ++i){
		one_to_n_addition = one_to_n_addition + i;
	}

	missing_number = one_to_n_addition - vector_number_addition;

	return missing_number;
}

int brute_force_find_missing_number(std::vector<size_t>& vec, size_t N)
{
	//bool status = true;
	size_t j = 0;
	for(size_t i = 1; i <= N; ++i)
	{       
		for(; j < N - 1;){
			if(i != vec[j])
				return i;
			break;	
		}       
		++j;                                                                                                                                                     
	}
	std::cout <<"No element were missing " << std::endl;
}
