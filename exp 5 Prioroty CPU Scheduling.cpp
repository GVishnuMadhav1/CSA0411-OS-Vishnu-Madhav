#include <stdio.h>

struct Process {
    int pid;       // Process ID
    int bt;        // Burst time
    int priority;  // Priority (lower value = higher priority)
    int wt;        // Waiting time
    int tat;       // Turnaround time
};

int main() {
    int n, i, j;
    struct Process p[20], temp;
    int total_wt = 0, total_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time and priority for process %d: ", p[i].pid);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    // Sort by priority (ascending order = higher priority first)
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (p[i].priority > p[j].priority) {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // First process has waiting time = 0
    p[0].wt = 0;

    // Calculate waiting time
    for (i = 1; i < n; i++) {
        p[i].wt = 0;
        for (j = 0; j < i; j++) {
            p[i].wt += p[j].bt;
        }
        total_wt += p[i].wt;
    }

    // Calculate turnaround time = burst + waiting
    for (i = 0; i < n; i++) {
        p[i].tat = p[i].bt + p[i].wt;
        total_tat += p[i].tat;
    }

    // Print results
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].bt, p[i].priority, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / n);

    return 0;
}

