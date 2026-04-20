#include <stdio.h>
#include <conio.h>   // for kbhit() and getch()

#define N 5

int state[N]; // 0 = thinking, 1 = hungry, 2 = eating
int mutex = 1;

void wait(int *s) {
    (*s)--;
}

void signal(int *s) {
    (*s)++;
}

void test(int i) {
    if(state[i] == 1 &&
       state[(i + 4) % N] != 2 &&
       state[(i + 1) % N] != 2) {

        state[i] = 2;
        printf("Philosopher %d is Eating\n", i + 1);
    }
}

void take_fork(int i) {
    wait(&mutex);

    state[i] = 1;
    printf("Philosopher %d is Hungry\n", i + 1);

    test(i);

    signal(&mutex);
}

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

    for(i = 0; i < N; i++)
        state[i] = 0;

    printf("Press ENTER to stop...\n");

    while(1) {
        for(i = 0; i < N; i++) {
            take_fork(i);
            put_fork(i);
        }

        // Check if key is pressed
        if(kbhit()) {
            char ch = getch();
            if(ch == 13) { // ENTER key
                break;
            }
        }
    }

    printf("\nProgram Stopped.\n");

    return 0;
}
