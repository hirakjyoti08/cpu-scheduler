#include <iostream>
#include <climits>
#include "Scheduler.h"
#include "Metrics.h"

using namespace std;

AlgoStats sjfNonPreemptive(vector<Process> p) {
    cout << "\n=== SJF (Non-Preemptive) ===\n";

    int n = p.size();
    int time = 0, completed = 0;

    vector<bool> done(n, false);

    cout << "Gantt Chart: ";

    while (completed < n) {
        int idx = -1;
        int minBurst = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (!done[i] && p[i].arrival <= time && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        cout << "| " << p[idx].pid << " ";

        time += p[idx].burst;

        p[idx].completion = time;
        p[idx].turnaround = time - p[idx].arrival;
        p[idx].waiting = p[idx].turnaround - p[idx].burst;

        done[idx] = true;
        completed++;
    }

    cout << "|\n";

    printMetrics(p);
    return computeAverages("SJF (NP)", p);
}
