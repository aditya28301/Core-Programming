#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define MAX 10

sem_t sem_odd;
sem_t sem_even;

void* print_odd(void* arg) {
    for (int i = 1; i <= MAX; i += 2) {
        sem_wait(&sem_odd);  // Wait for odd's turn
        std::cout << "Odd Thread: " << i << std::endl;
        sem_post(&sem_even); // Signal even thread
    }
    return NULL;
}

void* print_even(void* arg) {
    for (int i = 2; i <= MAX; i += 2) {
        sem_wait(&sem_even);  // Wait for even's turn
        std::cout << "Even Thread: " << i << std::endl;
        sem_post(&sem_odd);   // Signal odd thread
    }
    return NULL;
}

int main() {
    pthread_t tid_odd, tid_even;

    // Initialize semaphores
    sem_init(&sem_odd, 0, 1);   // Odd starts first
    sem_init(&sem_even, 0, 0);  // Even waits initially

    // Create threads
    pthread_create(&tid_odd, NULL, print_odd, NULL);
    pthread_create(&tid_even, NULL, print_even, NULL);

    // Wait for threads to finish
    pthread_join(tid_odd, NULL);
    pthread_join(tid_even, NULL);

    // Clean up
    sem_destroy(&sem_odd);
    sem_destroy(&sem_even);

    return 0;
}

