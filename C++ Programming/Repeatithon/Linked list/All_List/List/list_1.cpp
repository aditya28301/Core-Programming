#include "list.hpp"

node::node(data_t new_data = 0) : data(new_data), next(0){ }

list::list() : head_node(new node){ }

list::~list(){
	node* run = 0;
	node* run_next = head_node->next;

	while(run_next != 0){
		run = run_next->next;
		delete run_next;
		run_next = run;
	}

	delete head_node;
	head_node = 0;
}

void list::insert_start(data_t new_data){
	generic_insert(head_node, new node(new_data), head_node->next);
}				

void list::insert_end(data_t new_data){
	node* prev		= 0;
	node* current 	= 0;

	get_end_prev_node(&prev, &current);
	if(prev == 0 && current == 0){
		std::cout <<"INVALID DATA" << std::endl;
		return;
	}
	generic_insert(prev, new node(new_data), current);
}

void list::insert_after(data_t e_data, data_t new_data){

		node* prev = 0;
		node* current = 0;

		get_data_prev_current_node(&prev, &current, e_data);
		if(prev == 0 && current == 0){
			std::cout <<"INVALID DATA" << std::endl;
			return;
		}
		generic_insert(current, new node(new_data), current->next);
}				                                                                                                                                                           

void list::insert_before(data_t e_data, data_t new_data){
	node* prev = 0;
	node* current = 0;

	get_data_prev_current_node(&prev, &current, e_data);
	if(prev == 0 && current == 0){
		std::cout <<"INVALID DATA" << std::endl;
		return;
	}
	generic_insert(prev, new node(new_data), current);
}

void list::get_start(){
	if(isEmpty() == TRUE){
		std::cout <<"LIST IS EMPTY" << std::endl;
		return;
	}
	std::cout <<"Get_Start()= " << head_node->next->data << std::endl;
}

void list::get_end(){
	if(isEmpty() == TRUE){
		std::cout <<"LIST IS EMPTY" << std::endl;
		return;
	}
	node* prev 		= 0;
	node* current 	= 0;

	get_end_prev_node(&prev, &current);
	std::cout <<"Get_end()= " << current->data << std::endl;
}

void list::pop_start(){
	if(isEmpty() == TRUE){
		std::cout <<"LIST IS EMPTY" << std::endl;
		return;
	}
	std::cout <<"pop_start()= " << head_node->next->data << std::endl;
	generic_delete(head_node, head_node->next);
}                                               

void list::pop_end(){
if(isEmpty() == TRUE){
		std::cout <<"LIST IS EMPTY" << std::endl;
		return;
	}
	node* prev 		= 0;
	node* current 	= 0;

	get_end_prev_node(&prev, &current);
	std::cout <<"pop_end()= " << head_node->next->data << std::endl;
	generic_delete(prev, current);
}

void list::remove_data(data_t d_data){
	if(isEmpty() == TRUE){
		std::cout <<"LIST IS EMPTY" << std::endl;
		return;
	}

	node* prev 		= 0;
	node* current 	= 0;
	get_data_prev_current_node(&prev, &current, d_data);
	if(prev == 0 && current == 0){
			std::cout <<"INVALID DATA" << std::endl;
			return;
	}
	generic_delete(prev, current);
}                                                                                                                                                                              

void list::get_len(){
	node* run = head_node->next;
	data_t len = 0;
	while(run != 0){
		len = len  + 1;	
		run = run->next;
	}
	std::cout <<"LEN OF LIST= " << len << std::endl;
}

void list::show_list(){
	node* run = head_node->next;
	std::cout <<"[START]->";
	while(run != 0){
		std::cout <<"[" << run->data <<"]->";
		run = run->next;
	}
	std::cout <<"[END]"<< std::endl;
}

void list::generic_insert(node* start, node* mid, node* end){
	mid->next = end;
	start->next = mid;
}

void list::generic_delete(node* start, node* d_node){
	start->next = d_node->next;
	delete d_node;
}

void list::get_data_prev_current_node(node** prev, node** current, data_t s_data){

	node* run 		= 0;
	node* run_next	= 0;

	if(head_node != 0){                      
		run = head_node;
		run_next = head_node->next;

		while(run_next != 0){
			if(run_next->data == s_data){
				break;
			}
			run = run_next;
			run_next = run_next->next;
		}
 
		if(run_next == 0 ){
			*prev = 0;
			*current = 0;	
			return;
		}
	}
		*prev = run;
		*current = run_next;
}

void list::get_end_prev_node(node** prev, node** current){

	node* run 		= 0;
	node* run_next	= 0;

	if(head_node != 0){
		run = head_node;
		run_next = head_node->next;

		while(run_next->next != 0){
			run = run_next;
			run_next = run_next->next;
		}
 		
		*prev = run;
		*current = run_next;
		return;
	}
	
	*prev = run;
	*current = run_next;
}

status_t list:: isEmpty(){
	if(head_node->next == 0){
		return TRUE;
	}
	return FALSE;
}

Ilist* Ilist:: getInstance(){
	return  new list;
}

void Ilist::released_instance(Ilist* obj){
	delete obj;
}




















