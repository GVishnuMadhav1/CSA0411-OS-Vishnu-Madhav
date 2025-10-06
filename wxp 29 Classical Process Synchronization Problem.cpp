#include <stdio.h>
#include <stdlib.h>

// Function declarations
void producer();
void consumer();
void wait(int *);
void signal(int *);

// Global variables
int mutex = 1;   // ensures mutual exclusion
int full = 0;    // counts full slots
int empty = 3;   // counts empty slots
int item = 0;    // item counter

int main() {
    int choice;

    printf("\n--- PRODUCER-CONSUMER PROBLEM SIMULATION ---\n");
    printf("Buffer size = 3\n");

    while (1) {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer is full! Producer is waiting...\n");
                break;

            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer is empty! Consumer is waiting...\n");
                break;

            case 3:
                exit(0);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Wait (P) operation
void wait(int *S) {
    (*S)--;
}

// Signal (V) operation
void signal(int *S) {
    (*S)++;
}

// Producer process
void producer() {
    wait(&mutex);
    wait(&empty);
    signal(&full);
    item++;
    printf("Producer produces item %d\n", item);
    signal(&mutex);
}

// Consumer process
void consumer() {
    wait(&mutex);
    wait(&full);
    signal(&empty);
    printf("Consumer consumes item %d\n", item);
    item--;
    signal(&mutex);
}

