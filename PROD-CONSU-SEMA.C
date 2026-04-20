#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int buffer[MAX];
int in = 0, out = 0;

// Semaphores
int mutex = 1;
int full = 0;
int empty = MAX;

// Wait function
void wait(int *s) {
    (*s)--;
}

// Signal function
void signal(int *s) {
    (*s)++;
}

// Producer
void produce(int item) {
    if(empty == 0) {
        printf("Buffer is Full!\n");
        return;
    }

    wait(&empty);
    wait(&mutex);

    buffer[in] = item;
    printf("Produced item: %d\n", item);
    in = (in + 1) % MAX;

    signal(&mutex);
    signal(&full);
}

// Consumer
void consume() {
    int item;

    if(full == 0) {
        printf("Buffer is Empty!\n");
        return;
    }

    wait(&full);
    wait(&mutex);

    item = buffer[out];
    printf("Consumed item: %d\n", item);
    out = (out + 1) % MAX;

    signal(&mutex);
    signal(&empty);
}

// Main
int main() {
    int choice, item;

    while(1) {
        printf("\n--- Producer Consumer ---\n");
        printf("1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item: ");
                scanf("%d", &item);
                produce(item);
                break;

            case 2:
                consume();
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
