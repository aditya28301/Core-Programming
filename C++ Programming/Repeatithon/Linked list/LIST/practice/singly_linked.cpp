#include "singly_linked_list.hpp"

list :: list(size_t new_data) : head_node(new node){

}

node :: node(size_t new_data) : data(new_data), next(0){

}

list :: ~list(){ 
	if(head_node == 0) { std::cout << "Linked list is empty" << std::endl; exit(EXIT_FAILURE); }

	node* run_next = 0;
	node* run_prev = 0;

	run_next = head_node;
	
	for(; run_next != 0; ){
		run_prev = run_next;
		delete run_prev;
		run_next = run_prev;
	} 	
}

size_t list :: get_len(){
	size_t len = 0;
	
	for(node* run = head_node->next; run != 0; run = run->next){
		len += 1;
	}
	return len;
}

status_t isEmpty(){
	if(head_node == 0) { return TRUE; } 
	return FALSE;
}

void list :: generic_insert(node* prev, node* mid, node* next){	
	mid->next = next;
	prev->next = mid;
}

void list :: insert_start(size_t new_data){
	generic_insert(head_node, new node(new_data), head_node->next);
}

void list :: insert_end(size_t new_data){
	
if(head_node == 0) { return 0; }
	node* last_node = 0;
	last_node = find_last_node(head_node);
	generic_insert(last_node, new_node, last_node->next);
}

void list :: insert_after(size_t e_data, size_t new_data){
	node* e_node = 0;
	e_node = find_node(e_data);
	if(e_node == 0) { std::cout <<"Data to be search not found" << std::endl; return 0;}
	generic_insert(e_node, new node(new_data), e_node->next);
	return SUCCESsS;	
}

void list :: insert_before(size_t e_data, size_t new_data){
	node* prev_node = 0;
	prev_node = find_node_prev(e_data);
	generic_insert(prev_node, new node(new_data), prev_node->next);
	return SUCCESS;	
}

void list :: pop_start(){
	generic_delete(head_node->next);
	return SUCCESS;
} 

void list :: pop_end(){
	node* last_node = 0;
	last_node = find_last_node(head_node);
	generic_delete(last_node);
	return SUCCESS;
}

void list :: remove_node(size_t e_data){
	node* e_node = 0;
	node* prev_node = 0;

	e_node = find_node(e_data);
	generic_delete(e_node);	
	
	return SUCCESS;
}

node* list :: find_last_node(node* head_node){
	for(node* run = head_node, run->next != 0; run = run->next){
	}
	return run;
}

void list :: find_node_prev(size_t e_data){
	run_next = head_node;
	run_prev = 0;

	for(; run_next->data != e_data; ){
		run_prev = run_next;
		run_next = run_next->next;
	}
	return run_prev;
}

size_t list :: get_start(){
	if(head_node == 0) { std::cout << "linked list is empty" << std::endl; exit(EXIT_FAILURE); }
	return head_node->data;
}
 
size_t list :: get_end(){
	if(head_node == 0) { std::cout << "Linked list is empty" << std::endl; exit(EXIT_FAILURE); }
	node* last_node = 0;
	last_node = find_last_node(head_node);
	return last_node->data;		
}

void list :: generic_delete(node* delete_node){
	node* prev_node = 0;
	e_node = find_node_prev(delete_node);
	prev_node->next = delete_node->next;
}


