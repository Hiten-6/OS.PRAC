#include <stdio.h>

int main() {
    int nb, np, i, j;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter size of each block:\n");
    for(i = 0; i < nb; i++) {
        printf("Block %d: ", i + 1);
        scanf("%d", &block[i]);
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &np);

    int process[np], allocation[np];

    printf("Enter size of each process:\n");
    for(i = 0; i < np; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &process[i]);
        allocation[i] = -1; // not allocated
    }

    // Best Fit Logic
    for(i = 0; i < np; i++) {
        int bestIndex = -1;

        for(j = 0; j < nb; j++) {
            if(block[j] >= process[i]) {
                if(bestIndex == -1 || block[j] < block[bestIndex]) {
                    bestIndex = j;
                }
            }
        }

        if(bestIndex != -1) {
            allocation[i] = bestIndex;
            block[bestIndex] -= process[i];
        }
    }

    // Output
    printf("\nProcess\tSize\tBlock No\n");

    for(i = 0; i < np; i++) {
        printf("P%d\t%d\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
