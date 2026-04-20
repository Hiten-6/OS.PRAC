#include <stdio.h>

int main() {
    int n, i, time = 0, remain, tq;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], rt[n], wt[n], tat[n], ct[n];

    // Input Burst Time
    printf("Enter Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    remain = n;

    printf("\nExecution Order:\n");

    // Round Robin Logic
    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                printf("P%d ", i + 1);

                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    rt[i] = 0;
                    ct[i] = time;   // Completion Time
                    remain--;
                }
            }
        }
    }

    // Calculate WT and TAT
    for(i = 0; i < n; i++) {
        tat[i] = ct[i];          // since AT = 0
        wt[i] = tat[i] - bt[i];
    }

    // Output Table
    printf("\n\nProcess\tBT\tCT\tWT\tTAT\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, bt[i], ct[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
