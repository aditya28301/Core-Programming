#include "list.h"

// Interface function
node_t* create_list(void){
	node_t* head_node = NULL;
	head_node = get_node(0);
	head_node->next = head_node;
	head_node->prev = head_node;
}

void insert_start(node_t* head_node, data_t new_data){
	generic_insert(head_node, get_node(new_data), head_node->next);	
}

void insert_end(node_t* head_node, data_t new_data){
	generic_insert(head_node->prev, get_node(new_data), head_node);
}

void insert_after(node_t* head_node, data_t e_data, data_t new_data){
	node_t* s_node = find_node(head_node, e_data);
	generic_insert(s_node, get_node(new_data), s_node->next);
}

void insert_before(node_t* head_node, data_t e_data, data_t new_data){
	node_t* s_node = find_node(head_node, e_data);
	generic_insert(s_node->prev, get_node(new_data), s_node);
}

void get_start(node_t* head_node){
	if(isEmpty(head_node) == TRUE)
	{
		puts("LIST EMPTY");
		return;
	}
	printf("get_start() = %lu\n", head_node->next->data);
}

void get_end(node_t* head_node){
	if(isEmpty(head_node) == TRUE){
		puts("LIST EMPTY");
		return;
	}
	printf("get_end() = %lu\n", head_node->prev->data);
}

void pop_start(node_t* head_node){
	if(isEmpty(head_node) == TRUE){
		puts("LIST IS EMPTY");
		return;
	}

	printf("pop_start() = %lu\n", head_node->next->data);
	generic_delete(head_node, head_node->next);
}

void pop_end(node_t* head_node){
	if(isEmpty(head_node) == TRUE){
		puts("LIST IS EMPTY");
		return;
	}
	printf("pop_end() = %lu\n", head_node->prev->data);
	generic_delete(head_node, head_node->prev);
}

void remove_node(node_t* head_node, data_t del_node){
	node_t* s_node = find_node(head_node, del_node);
	if(s_node == NULL){
		puts("INVALID DATA");
		return;
	}

	generic_delete(head_node, s_node);
}

status_t isEmpty(node_t* head_node){
	if(head_node->next == head_node)
		return TRUE;

	return FALSE;
}

void get_len(node_t* head_node){
	node_t* run = head_node->next;
	data_t len = 0;

	while(run != head_node){
		len = len + 1;
		run = run->next;	
	}
	printf("LEN OF LINKED LIST IS = %lu\n", len);
}

void show_list(node_t* head_node){
	node_t* run = head_node->next;
	printf("[START]->");
	while(run != head_node){
		printf("[%lu]->", run->data);
		run = run->next;	
	}
	printf("[END]\n");
}

void destroy_list(node_t** p_head_node){
	node_t* head_node = *p_head_node;
	node_t* run = NULL;
	node_t* run_next = head_node->next;
		
	while(run_next != head_node){
		run = run_next->next;
		free(run_next);
		run_next = run;
	}
		
	free(head_node);
	*p_head_node = NULL;
}

// Auxilairy function
static void generic_insert(node_t* start, node_t* mid, node_t* end){
	
	mid->next = end;
	mid->prev = start;
	start->next = mid;
	end->prev = mid;
}

static void generic_delete(node_t* head_node, node_t* del_node){
	del_node->prev->next = del_node->next;
	del_node->next->prev = del_node->prev;
	free(del_node);
}
 
static node_t* find_node(node_t* head_node, data_t s_data){
	node_t* run = head_node->next;
	while(run != head_node){
		if(run->data == s_data)
			return run;
		run = run->next;
	}
	return NULL;
}

// Helper function
node_t* get_node(data_t new_data){
	node_t* new_node = (node_t*)xmalloc(sizeof(node_t));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = new_data;
	return (new_node);
}

void* xmalloc(data_t new_required_byte){
	void* ptr = NULL;
	ptr = malloc(new_required_byte);
	if(ptr == NULL)
	{
		puts("Error in allocating the meomary");
		exit(EXIT_FAILURE);
	}
	return ptr;
}

