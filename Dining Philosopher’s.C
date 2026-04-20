#include <stdio.h>

#define N 5

int state[N]; // 0 = thinking, 1 = hungry, 2 = eating

// Semaphore simulation
int mutex = 1;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

// Check if philosopher can eat
void test(int i) {
    if(state[i] == 1 &&
       state[(i + 4) % N] != 2 &&
       state[(i + 1) % N] != 2) {

        state[i] = 2;
        printf("Philosopher %d is Eating\n", i + 1);
    }
}

// Take chopsticks
void take_fork(int i) {
    wait(&mutex);

    state[i] = 1;
    printf("Philosopher %d is Hungry\n", i + 1);

    test(i);

    signal(&mutex);
}

// Put chopsticks
void put_fork(int i) {
    wait(&mutex);

    state[i] = 0;
    printf("Philosopher %d is Thinking\n", i + 1);

    test((i + 4) % N);
    test((i + 1) % N);

    signal(&mutex);
}

int main() {
    int i;

    // Initially all are thinking
    for(i = 0; i < N; i++)
        state[i] = 0;

    // Simulation
    for(i = 0; i < N; i++) {
        take_fork(i);
        put_fork(i);
    }

    return 0;
}
