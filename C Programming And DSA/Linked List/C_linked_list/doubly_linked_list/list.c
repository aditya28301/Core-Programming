#include "list.h"

// Interface function
node_t* create_list(){
	node_t* head_node = NULL;
	head_node = get_node(0);
	return (head_node);
}

void insert_start(node_t* head_node, data_t new_data){
	
	generic_insert(head_node, get_node(new_data), head_node->next);
}

void insert_end(node_t* head_node, data_t new_data){
	
	generic_insert(get_last_node(head_node), get_node(new_data), get_last_node(head_node)->next);
}

void insert_after(node_t* head_node, data_t e_data, data_t new_data){
	
	node_t* data_node = NULL;
	data_node = find_data_node(head_node, e_data);
	if(data_node == NULL){
		puts("INVALID INPUT");
		return;
	}
	generic_insert(data_node, get_node(new_data), data_node->next);
}

void insert_before(node_t* head_node, data_t e_data, data_t new_data){
	
	node_t* data_node = NULL;
	data_node = find_data_node(head_node, e_data);
	if(data_node == NULL){
		puts("INVALID DATA");
		return;
	}	
	generic_insert(data_node->prev, get_node(new_data), data_node);
}

void get_start(node_t* head_node){
	if(isEmpty(head_node)){
		puts("LIST IS EMPTY");
		return;
	}
	
	printf("Get_start() = %lu", head_node->next->data);
}

void get_end(node_t* head_node){

	if(isEmpty(head_node)){
		puts("LIST IS EMPTY");
		return;
	}

	node_t* last_node = get_last_node(head_node);

	printf("last_node() = %lu",last_node->data);
	
}

void pop_start(node_t* head_node){

	if(isEmpty(head_node)){
		puts("LIST IS EMPT");
		return;
	}
	
	printf("pop_start() = %lu\n", head_node->next->data);
	generic_delete(head_node, head_node->next);
}

void pop_end(node_t* head_node){

	printf("pop_end() = %lu", get_last_node(head_node)->data);
	generic_delete(get_last_node(head_node)->prev, get_last_node(head_node));
}

void remove_node(node_t* head_node, data_t del_data){
	generic_delete(find_data_node(head_node, del_data)->prev, find_data_node(head_node, del_data));	
}

void get_len(node_t* head_node){
	node_t* run = head_node->next;
	size_t len = 0;

	while(run != NULL){
		len = len + 1;
		run = run->next;	
	}
	
	printf("LENGTH OF LIST = %lu", len);
}

status_t isEmpty(node_t* head_node){
	if(head_node->next == NULL && head_node->prev == NULL){
		return TRUE;
	}
	return FALSE;
}

void show_list(node_t* head_node){
	
	printf("[START]->");
	
	if(head_node != NULL){
		node_t* run = head_node->next;
		while(run != NULL){
			printf("[%lu]->", run->data);
			run = run->next;	
		}
	}
	printf("<-[END]");
}

void destroy_list(node_t** p_head_node){
	node_t* head_node = *p_head_node;
	
	node_t* run = head_node->next;
	while(run->next != NULL){
		run = run->next;
		free(run->prev);
	}

	free(run);
	free(head_node);
	*p_head_node = NULL;
}

// Helper function
node_t* get_node(data_t new_data){
	node_t* new_node = NULL;
	new_node = (node_t*)xmalloc(sizeof(node_t));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = new_data;
	return (new_node);
}

void* xmalloc(data_t new_required_byte){

	void* ptr = NULL;
	ptr = malloc(new_required_byte);
	if(ptr == NULL){
		puts("Error in allocating the meomary");
	}
	return ptr;
}

static void generic_insert(node_t* start, node_t* mid, node_t* end){
	
	mid->next = end;
	mid->prev = start;
	start->next = mid;
	if(end != NULL)
		end->prev = mid;
}

static node_t* get_last_node(node_t* head_node){
	
	node_t* run = head_node;
	
	while(run->next != NULL){
		run = run->next;
	}	
	return run;
}

static node_t* find_data_node(node_t* head_node, data_t s_data){

	node_t* run = head_node->next;
	while(run != NULL){
		if(run->data == s_data)
			return run;
		run = run->next;
	}
	return NULL;
}

static void generic_delete(node_t* start, node_t* del_node){
		
	start->next = del_node->next;

	if(del_node->next != NULL){
		del_node->next->prev = start;
	}		
	free(del_node);
}





