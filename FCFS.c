
// FCFS CPU Scheduling Algorithm

#include <stdio.h>

int main() {
    int n, i;
    int bt[10], wt[10], tat[10];
    int total_wt = 0, total_tat = 0;
    float avg_wt, avg_tat;

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst times
    printf("Enter burst time of each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Calculate waiting time
    wt[0] = 0;

    for(i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Calculate turnaround time
    for(i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Calculate average waiting time and turnaround time
    avg_wt = (float) total_wt / n;
    avg_tat = (float) total_tat / n;

    // Display results
    printf("\nProcess\tBT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1,
               bt[i],
               wt[i],
               tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    return 0;
}