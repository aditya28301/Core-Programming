#include <cstdlib>
#include <iostream>
#include "iList.hpp"

// Symbolic constant
const int TRUE	=	1;
const int FALSE	=	0;

// Typedefination statement
typedef int status_t;
typedef size_t data_t;

// class decleration

class list;

class node{
	friend class list;
	private:
		size_t data;
		node* next;

	public: 
		node(data_t new_data);
};

class list : public Ilist{
	private:
		node* head_node;
		static void generic_insert(node* start, node* mid, node* end);
		static void generic_delete(node* start, node* d_node);
		node* find_node(data_t s_data);
		void get_end_prev_node(node** prev, node** current);  
		void get_data_prev_current_node(node** prev, node** current, data_t s_data);
	public:
		list();
		~list();
		void insert_start(data_t new_data);
		void insert_end(data_t new_data);
		void insert_after(data_t e_data, data_t new_data);
		void insert_before(data_t e_data, data_t new_data);
		void get_start();
		void get_end();
		void pop_start();
		void pop_end();
		void remove_data(data_t d_data);
		void get_len();
		void show_list();
		status_t isEmpty();
};
