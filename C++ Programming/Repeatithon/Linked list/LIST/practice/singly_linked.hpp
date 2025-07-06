#include <cstdio>
#include <cstdlib>
#include <iostream>

typedef int status_t;

const int TRUE = 1;
const int FALSE = 0;

class list{
friend class node;
	private:
		node* head_node;
		static void generic_insert(node* start, node* new_node, node* end);
		static void generic_delete(node* delete_node);
		static void find_last_node(node* head_node);
		static node* find_node_prev(node* e_node);
		static node* find_node(size_t s_data);
	public:
		list();
		~list();
		void insert_start(size_t new_data);
		void insert_end(size_t new_data);
		void insert_after(size_t e_data, size_t new_data);
		void insert_before(size_t e_data, size_t new_data);
		void pop_start();	
		void pop_end();
		void remove_node();
		void get_start();
		void get_end();
		size_t get_len();
		status_t isEmpty();
};

class node{
	private:
		size_t data;
		node* next;

	public:
		node(size_t new_data = 0);
	
};
