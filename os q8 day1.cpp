#include <stdio.h>

int main() {
    int n, burst[10], quantum, remaining[10], time = 0, total_waiting = 0, total_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter burst time for each process:\n");
    for (int i = 0; i < n; i++) scanf("%d", &burst[i]);

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    for (int i = 0; i < n; i++) remaining[i] = burst[i];

    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                done = 0;
                if (remaining[i] > quantum) {
                    time += quantum;
                    remaining[i] -= quantum;
                } else {
                    time += remaining[i];
                    total_waiting += time - burst[i];
                    total_turnaround += time;
                    remaining[i] = 0;
                }
            }
        }
        if (done == 1) break;
    }

    printf("Average Waiting Time: %.2f\n", (float)total_waiting / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround / n);
    return 0;
}

