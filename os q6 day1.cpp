#include <stdio.h>

struct Process {
    int id;
    int burst;
    int priority;
};

int main() {
    int n, total_time = 0, min_priority = 9999, min_index = -1;
    float avg_waiting = 0, avg_turnaround = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        printf("Enter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst, &processes[i].priority);
        processes[i].id = i + 1;
    }

    for (int i = 0; i < n; i++) {
        min_priority = 9999;
        for (int j = 0; j < n; j++) {
            if (processes[j].burst > 0 && processes[j].priority < min_priority) {
                min_priority = processes[j].priority;
                min_index = j;
            }
        }
        total_time += processes[min_index].burst;
        avg_waiting += total_time;
        avg_turnaround += total_time;
        processes[min_index].burst = 0;
    }

    avg_waiting /= n;
    avg_turnaround /= n;
    printf("Average Waiting Time: %.2f\n", avg_waiting);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround);

    return 0;
}


