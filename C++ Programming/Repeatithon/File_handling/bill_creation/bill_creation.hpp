#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

class File{
	private:
		std::string file_name;

	public:	
		std::vector<std::string> transaction_id;
		std::vector<std::string> customer_id;
		std::vector<std::string> status;

		File(std::string);
		void initiate_bill_run(void);
		void Generate_bill(void);
		void extract_Transaction_id(std::string line);
		void extract_Customer_id(std::stringr line);
		void extract_Status(std::string line);	
};	
