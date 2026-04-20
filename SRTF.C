#include <stdio.h>

int main() {
    int n, i, time = 0, completed = 0, min_index;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int at[n], bt[n], rt[n], ct[n], wt[n], tat[n];

    // Input
    printf("Enter Arrival Time and Burst Time:\n");
    for(i = 0; i < n; i++) {
        printf("P%d AT BT: ", i + 1);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    // Execution Order (Simple)
    printf("\nExecution Order:\n");

    while(completed < n) {
        min_index = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0) {
                if(min_index == -1 || rt[i] < rt[min_index]) {
                    min_index = i;
                }
            }
        }

        if(min_index == -1) {
            time++;
            continue;
        }

        printf("P%d ", min_index + 1);

        rt[min_index]--;

        if(rt[min_index] == 0) {
            completed++;
            ct[min_index] = time + 1;
        }

        time++;
    }

    // Calculations
    for(i = 0; i < n; i++) {
        wt[i] = ct[i] - at[i] - bt[i];
        tat[i] = wt[i] + bt[i];
    }

    // Table Output
    printf("\n\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    float total_wt = 0, total_tat = 0;

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], ct[i], wt[i], tat[i]);
        total_wt += wt[i];
        total_tat += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", total_wt / n);
    printf("Average Turnaround Time = %.2f\n", total_tat / n);

    return 0;
}
