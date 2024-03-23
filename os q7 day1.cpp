#include <stdio.h>

int main() {
    int n, burst[10], waiting = 0, turnaround = 0, temp;
    float avg_waiting, avg_turnaround;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) scanf("%d", &burst[i]);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (burst[i] > burst[j]) {
                temp = burst[i];
                burst[i] = burst[j];
                burst[j] = temp;
            }
        }
        waiting += burst[i];
        turnaround += waiting + burst[i];
    }
    avg_waiting = (float)waiting / n;
    avg_turnaround = (float)turnaround / n;
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);
    return 0;
}

