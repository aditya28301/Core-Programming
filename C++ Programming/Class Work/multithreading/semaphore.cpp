
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* worker(void* arg) {
    int id = *((int*)arg);
    sem_wait(&sem);  // P (wait)
    std::cout << "Thread " << id << " entered critical section\n";
    sleep(2);
    std::cout << "Thread " << id << " leaving critical section\n";
    sem_post(&sem);  // V (signal)
    return NULL;
}

int main() {
    const int max_threads = 3;
    const int total_threads = 10;

    sem_init(&sem, 0, max_threads);

    pthread_t threads[total_threads];
    int ids[total_threads];

    for (int i = 0; i < total_threads; ++i) {
        ids[i] = i + 1;
        pthread_create(&threads[i], NULL, worker, &ids[i]);
    }

    for (int i = 0; i < total_threads; ++i) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}

