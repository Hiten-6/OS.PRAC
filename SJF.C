#include <stdio.h>

int main() {
    int n, i, j;

    // Step 1: Take input
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], wt[n], tat[n], p[n];

    // Input burst time
    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;  // store process number
    }

    // Step 2: Sort processes based on burst time (SJF logic)
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(bt[i] > bt[j]) {
                // swap burst time
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process number
                int temp2 = p[i];
                p[i] = p[j];
                p[j] = temp2;
            }
        }
    }

    // Step 4: Calculate Waiting Time
    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Step 4: Calculate Turnaround Time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    // Step 5: Display execution order
    printf("\nExecution Order (SJF): ");
    for(i = 0; i < n; i++) {
        printf("P%d ", p[i]);
    }

    // Display table
    printf("\n\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    // Calculate averages
    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
