#include <vector>
#include "Scheduler.h"

using namespace std;

int main() {
    vector<Process> processes = {
        {"P1", 0, 5, 5},
        {"P2", 1, 3, 3},
        {"P3", 2, 1, 1},
        {"P4", 3, 2, 2}
    };

    fcfs(processes);
    sjfNonPreemptive(processes);
    roundRobin(processes, 2);

    return 0;
}
