#include <stdio.h>

struct Process {
    int id;
    int arrival;
    int burst; 
    int completion;
    int waiting;
    int turnaround;
};

void findCompletionTime(struct Process proc[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < proc[i].arrival) {
            currentTime = proc[i].arrival;
        }
        proc[i].completion = currentTime + proc[i].burst;
        currentTime = proc[i].completion;
    }
}

void findTurnaroundTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].turnaround = proc[i].completion - proc[i].arrival;
    }
}

void findWaitingTime(struct Process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].waiting = proc[i].turnaround - proc[i].burst;
    }
}

void printProcesses(struct Process proc[], int n) {
    printf("ID\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               proc[i].id, proc[i].arrival, proc[i].burst,
               proc[i].completion, proc[i].turnaround, proc[i].waiting);
    }
}

int main() {
    int n;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d%d", &proc[i].arrival, &proc[i].burst);
        proc[i].id = i + 1;
    }

    findCompletionTime(proc, n);
    findTurnaroundTime(proc, n);
    findWaitingTime(proc, n);

    printProcesses(proc, n);

    return 0;
}