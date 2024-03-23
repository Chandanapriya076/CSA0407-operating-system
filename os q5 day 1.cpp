#include <stdio.h>

int main() {
    int n, burst[10], priority[10], waiting = 0, turnaround = 0;
    float avg_waiting, avg_turnaround;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time and priority for each process:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &burst[i], &priority[i]);
        waiting += burst[i];
        turnaround += waiting;
    }
    avg_waiting = (float)waiting / n;
    avg_turnaround = (float)turnaround / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
    return 0;
}

