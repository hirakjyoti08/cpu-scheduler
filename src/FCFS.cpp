#include <iostream>
#include <algorithm>
#include "Scheduler.h"
#include "Metrics.h"

using namespace std;

void fcfs(vector<Process> p) {
    cout << "\n=== FCFS ===\n";

    sort(p.begin(), p.end(), [](auto& a, auto& b) {
        return a.arrival < b.arrival;
    });

    int time = 0;
    cout << "Gantt Chart: ";

    for (auto& proc : p) {
        if (time < proc.arrival)
            time = proc.arrival;

        cout << "| " << proc.pid << " ";
        time += proc.burst;

        proc.completion = time;
        proc.turnaround = time - proc.arrival;
        proc.waiting = proc.turnaround - proc.burst;
    }

    cout << "|\n";
    printMetrics(p);

}
