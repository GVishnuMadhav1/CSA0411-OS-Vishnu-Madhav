#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Thread function
void* thread_function(void* arg) {
    int *num = (int*)arg;
    printf("Thread %d: Started execution.\n", *num);

    // Demonstrate pthread_exit
    printf("Thread %d: Exiting now.\n", *num);
    pthread_exit(NULL);   // Thread exits here
}

int main() {
    pthread_t t1, t2;
    int arg1 = 1, arg2 = 2;
    int ret;

    printf("\n--- THREAD DEMONSTRATION PROGRAM ---\n");

    // (i) CREATE THREADS
    ret = pthread_create(&t1, NULL, thread_function, &arg1);
    if (ret) {
        printf("Error creating thread 1\n");
        exit(EXIT_FAILURE);
    }

    ret = pthread_create(&t2, NULL, thread_function, &arg2);
    if (ret) {
        printf("Error creating thread 2\n");
        exit(EXIT_FAILURE);
    }

    // (ii) JOIN THREADS (wait for them to finish)
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("Main thread: Both threads have finished execution.\n");

    // (iii) EQUAL — Check if two thread IDs are equal
    if (pthread_equal(t1, t2))
        printf("Thread 1 and Thread 2 are equal (same thread).\n");
    else
        printf("Thread 1 and Thread 2 are NOT equal (different threads).\n");

    // (iv) EXIT — Main thread exits cleanly
    printf("Main thread exiting now.\n");
    pthread_exit(NULL);

    return 0;
}

