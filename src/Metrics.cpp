#include <iostream>
#include <iomanip>
#include "Metrics.h"

using namespace std;

void printMetrics(const vector<Process>& p) {
    double totalWT = 0, totalTAT = 0;

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for (const auto& proc : p) {
        cout << proc.pid << "\t"
             << proc.arrival << "\t"
             << proc.burst << "\t"
             << proc.completion << "\t"
             << proc.turnaround << "\t"
             << proc.waiting << "\n";

        totalWT += proc.waiting;
        totalTAT += proc.turnaround;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << totalWT / p.size();
    cout << "\nAverage Turnaround Time: " << totalTAT / p.size() << "\n";
}
