#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>

void* f_thread(void* args);
int main(void){
	pthread_t thread_1;
	pthread_t thread_2;
	int id1 = 1;
	int id2 = 2;

	if(pthread_create(&thread_1, NULL, f_thread, &id1) != 0){
		fprintf(stderr, "Error in creating thread =%s", 
			strerror(errno));
		exit(EXIT_FAILURE);
	}
	
	if(pthread_create(&thread_2, NULL, f_thread, &id2) != 0){
                fprintf(stderr, "Error in creating thread =%s",
                        strerror(errno));
                exit(EXIT_FAILURE);
        }

	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	puts("Program terminated succesfully");
	return EXIT_SUCCESS;
}

void* f_thread(void* args){
	sleep(1);
	printf("Thread_id :%d Execution Started\n",
		*(int*)args);
	int localVar = 100;
	
	printf("Thread id : %d, PID : %d\n",
		*(int*)(args), getpid());
	printf("LocalVarible Address =%llu\n",
		(unsigned long long int)&localVar);
	printf("Thread_id :%d Execution Ended\n",
                *(int*)args);
	sleep(1);
	return NULL;
}
