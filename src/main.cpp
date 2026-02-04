#include <vector>
#include "Scheduler.h"
#include "Summary.h"

using namespace std;

int main() {
    vector<Process> processes = {
        {"P1", 0, 5, 5},
        {"P2", 1, 3, 3},
        {"P3", 2, 1, 1},
        {"P4", 3, 2, 2}
    };

    vector<AlgoStats> summary;

    summary.push_back(fcfs(processes));
    summary.push_back(sjfNonPreemptive(processes));
    summary.push_back(roundRobin(processes, 2));

    printSummary(summary);

    return 0;
}
