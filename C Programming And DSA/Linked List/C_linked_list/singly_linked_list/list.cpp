#include "list.hpp"
void* xmalloc(size_t new_required_byte){
	void* ptr = NULL;

	ptr = malloc(new_required_byte);
	if(ptr == NULL){
		puts("Error in allocating the meomary");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}

static node_t* get_node(data_t new_data){
	node_t* new_node = NULL;
	new_node = (node_t*)xmalloc(sizeof(node_t));	
	new_node->data = new_data;
	new_node->next = NULL;
	return (new_node);	
}

node_t* create_list(){
	//puts("Create list function is called here");
	node_t* head_node = NULL;
	head_node = get_node(0);
	//puts("Create list function is end here");
	return head_node;
}

void insert_start(node_t* head_node, size_t data){
    //puts("Insert_Start() function is called");
	node_t* new_node = NULL;
	new_node = get_node(data);
	new_node->next = head_node->next;
	head_node->next = new_node;
	//puts("Insert_Start() function is end()");
}                                           
                                                                                                                    
void insert_end(node_t* head_node, size_t data){
	node_t* run = NULL;
	run = head_node;

	while(run->next != NULL){
		run = run->next;
	}
	
	node_t* new_node = NULL;
	new_node = get_node(data);
	
	run->next = new_node;
}

void insert_before(node_t* head_node, size_t before_data, size_t data){
	node_t* run_prev = NULL;
	node_t* run_next = NULL;

	run_prev = head_node;
	run_next = head_node->next;

	while(run_next-> data != before_data){
		run_prev = run_next;
		run_next = run_next->next;
	}

	node_t* new_node = NULL;
	new_node = get_node(data);
	new_node->next = run_prev->next;
	run_prev->next = new_node;
}

void insert_after(node_t* head_node, size_t after_data, size_t data){
	node_t* run_prev = NULL;
	node_t* run_next = NULL;

	run_prev = head_node;	
	run_next = head_node->next;

	while(run_next->data != after_data){

		run_prev = run_next;
		run_next = run_next->next;
	}

	node_t* new_node = NULL;
	new_node = get_node(data);
	
	new_node->next = run_next->next;
	run_next->next = new_node;
}

void get_start(node_t* head_node){
	if(head_node->next == NULL){
		puts("LIST IS EMPTY");
		return;
	}

	printf("get_start() = %llu\n", head_node->next->data);
}

void get_end(node_t* head_node){

	node_t* run = NULL;
	run = head_node;

	while(run->next != NULL){
		run = run->next;
	}
	
	printf("get_end() = %llu\n", run->data);
}

void pop_start(node_t* head_node){

	node_t* del_node = head_node->next;
	head_node->next = del_node->next;

	free(del_node);
}

void pop_end(node_t* head_node){

	node_t* run_prev = NULL;
	node_t* run_next = NULL;

	run_prev = head_node;
	run_next = head_node->next;

	while(run_next->next != NULL){
		run_prev = run_next;
		run_next = run_next->next;
	}	

	run_prev->next = run_next->next;
}

void remove_node(node_t* head_node, size_t delete_data){
	if(head_node->next == NULL){
		puts("LINKED LIST IS EMPTY");
		return;
	}

	// puts("remove_node()");
		node_t* run_prev = NULL;
		node_t* run_next = NULL;

		run_prev = head_node;
		run_next = head_node->next;

		while(run_next != NULL){
			if(run_next->data == delete_data){
				break;
			}
			run_prev = run_next;
			run_next = run_next->next;
		}

		if(run_next == NULL){
			puts("INVALID DATA FOR DELETION");
			return;
		}

		run_prev->next = run_next->next;
		free(run_next);
		// puts("Remove_node() end");
}

void isEmpty(node_t* head_node){
	if(head_node->next == NULL){
		puts("LIST IS EMPTY");
		return;
	}
	else{
		puts("LIST IS NOT EMPTY");
	}
}

void get_len(node_t* head_node){
	node_t* run = NULL;
	size_t len = 0;
	run = head_node->next;
	
	while(run != NULL){
		len = len + 1;
		run = run->next;
	}
	printf("Lenght of linked list = %llu\n", len);
}

void find(node_t* head_node, size_t search_data){

	node_t* run = NULL;	
	run = head_node;

	while(run != NULL){
		if(run->data == search_data){
			printf("DATA IS FOUND = %llu\n", run->data);
			return;
		}
		run = run->next;
	}
	printf("INVALID DATA TO SEARCH\n");
}

void show_list(node_t* head_node){
	node_t* run = head_node->next;

	printf("[START]->");
	while(run->next != head_node){
		printf("[%llu]->", run->data);
		run = run->next;
	}
	printf("<-[END]\n");
}

void destroy_list(node_t** p_head_node){

	if(p_head_node == NULL){
		printf("LIST IS EMPTY");
		return;
	}

	node_t* head_node = *p_head_node;
	node_t* run_prev = NULL;
	node_t* run_next = NULL;

	run_next = head_node->next;

	while(run_next->next != NULL){
		run_prev = run_next->next;
		free(run_next);
		run_next = run_prev;
	}
	*p_head_node = NULL;
}
