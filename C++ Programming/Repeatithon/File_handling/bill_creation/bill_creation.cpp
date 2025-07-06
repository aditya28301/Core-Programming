#include "bill_creation.cpp"

File::File(std::string file) : file_name(file) {
	std::cout <<"" << std::endl; 
	}


void File::initiate_bill_run(void){


}

void File::extract_Transaction_id(std::string line){
 	size_t transaction_id_len = 0;

	std::string Process_line = strLine[i];

        start_pos = Process_line.find("TXN");
        end_pos = Process_line.find(" |");

        transaction_id_len = end_pos - start_pos;
	transaction_id.emplace_back(Process_line.substr(start_pos, transaction_id_len));
}


void File::extract_Customer_id(std::string line){
	size_t len = 0;
	size_t start_pos = 0;
	size_t end_pos = 0;

	start_pos = line.find("CUST");
	end_pos = line.find(" |");
	
	len = end_pos - start_pos;
	Customer_id.emplace_back(line.substr(start_pos, len));						
}

void File::extract_Status(std::string line){
	size_t len = 0;
	size_t start_pos = 0;
	size_t end_pos = 0;
	
	end_pos = line.size() - 1; 
	start_pos = line.find("Status: ");

	len = end_pos - start_pos;
	line = line.substr(start_pos, len);
	
	start_pos = line.find(": ");
	start_pos += 2;
	end_pos  = line.size() - 1;
	
	len = end_pos - start_pos;
	Status.emplace_back(line.substr(start_pos, len)); 
}

void File::Generate_bill(void){
	size_t start_pos;
	size_t end_pos;

	std::vector<std::string> strLine;
	std::list<std::string> transaction_id;
	
	std::fstream file;
	file.open(file_name, std::ios::in | std::ios::out);

	if(file.is_open()){
		while(get_line(file, line)){
				strLine.emplace_back(line);
			}	
		}

	for(size_t i = 0; i < strLine.size(); ++i){
		extract_Transaction_id(strLine[i]);
		extract_Customer_id(strLine[i]);
		extract_Status(strLine[i]);		
		}
}
