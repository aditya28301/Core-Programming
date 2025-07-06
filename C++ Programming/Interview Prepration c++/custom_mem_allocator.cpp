#include <cstdio>
#include <cstdlib>
#include <iostream>

#define POOL_SIZE 1024 * 1024

struct block{

	size_t size;
	int free;
	struct block* next;
};

char mem_pool[POOL_SIZE];

struct block* init();
struct block* my_alloc(struct block* header);

int main(void){

	struct block* header = init();
	
	my_alloc(header, 200);
	
}

struct block* init(){
	
	struct block* header = (struct block*)mem_pool;
	header->size = POOL_SIZE - sizeof(struct block
	header->free = 1;
	header->next = NULL;
			
}

struct block* my_alloc(struct block* header, size_t required_size){

	struct block* run = header;

	while(run != NULL){
		if(header->free && header->size >= requried_size){

			if(header->size > required_block + sizeof(struct block)){

				struct block* new_block = (char*)header + sizeof(struct block) + required_size;
	
				new_block->size = header->size - requried_size - sizeof(struct block);
		
				new_block->free = 0;
	
				new_block->next = NULL;

				header->size = required_size;
				header->next = new_block;

			}	

			header->free = 0;
		
			return (char*)header + sizeof(struct block);
		}
	
			run = run->next;	
	}	                                                                                                                                                                                                                                                                                                                                          	
}


:w2q
:wq

















