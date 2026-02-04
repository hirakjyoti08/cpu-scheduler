#include <iostream>
#include <queue>
#include <algorithm>
#include "Scheduler.h"
#include "Metrics.h"

using namespace std;

void roundRobin(vector<Process> p, int quantum) {
    cout << "\n=== Round Robin (Q = " << quantum << ") ===\n";

    sort(p.begin(), p.end(), [](auto& a, auto& b) {
        return a.arrival < b.arrival;
    });

    queue<int> q;
    vector<bool> inQueue(p.size(), false);

    int time = 0;
    q.push(0);
    inQueue[0] = true;

    cout << "Gantt Chart: ";

    while (!q.empty()) {
        int i = q.front();
        q.pop();

        int exec = min(quantum, p[i].remaining);
        cout << "| " << p[i].pid << " ";

        p[i].remaining -= exec;
        time += exec;

        for (int j = 0; j < p.size(); j++) {
            if (!inQueue[j] && p[j].arrival <= time && p[j].remaining > 0) {
                q.push(j);
                inQueue[j] = true;
            }
        }

        if (p[i].remaining > 0) {
            q.push(i);
        } else {
            p[i].completion = time;
            p[i].turnaround = time - p[i].arrival;
            p[i].waiting = p[i].turnaround - p[i].burst;
        }
    }

    cout << "|\n";
    printMetrics(p);
}
