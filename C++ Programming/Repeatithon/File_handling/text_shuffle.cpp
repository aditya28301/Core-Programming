#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class text_shuffle{
	private:
		std::string file_name;		
	public:
		text_shuffle(std::string file) : file_name(file) { 
		}
		
		static void shuffle_logic(std::vector<std::string>& vec){
			int ascii_char;
			std::string line;
			for(size_t i = 0; i < vec.size(); ++i){
				line = vec[i];
				for(size_t j = 0; j < line.size(); ++j){
					
					if(line[j] == 'z'){
						line[j] = 'a';
					}
					else{
						ascii_char = (int)line[j];
						line[j] = (char)ascii_char + 1; 
					}	
				}
				vec[i] = line;		
			}
		}

		void processing_text(void) {
			std::fstream r_w_file;
			std::vector<std::string> line_vec;
			r_w_file.open(file_name, std::ios::in | std::ios::out);
			std::string line;

			// read all line and stored in a vector
			if(r_w_file.is_open()){
				while(getline(r_w_file, line)){
					line_vec.push_back(line);					
				}				
			
			}	
			else{
				std::cout <<"Error in opening file" << std::endl;
				exit(EXIT_FAILURE);
			}		

			r_w_file.close(); 
			r_w_file.open(file_name, std::ios::in | std::ios::out);

			//processed the all line

			shuffle_logic(line_vec);			

			//Write all line a file
			
			for(size_t i = 0; i < line_vec.size(); ++i){
				r_w_file << line_vec[i];	
			}

			r_w_file.close();	
		} 
};
int main(int args, char* argv[]){
	if(args < 2){ std::cerr <<"Not enough argument" << std::endl; return EXIT_FAILURE;}
	
	std::vector<text_shuffle> file;
	file.reserve(args - 1);
	

	for(size_t i = 1; i < args; ++i){
		file.emplace_back(argv[i]);
		file.back().processing_text();
	}	
	return EXIT_SUCCESS;
}
