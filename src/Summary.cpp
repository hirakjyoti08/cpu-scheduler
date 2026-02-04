#include <iostream>
#include <iomanip>
#include "Summary.h"

using namespace std;

void printSummary(const vector<AlgoStats>& summary) {
    cout << "\n================== FINAL SUMMARY ==================\n";

    cout << left << setw(15) << "Algorithm"
         << setw(12) << "Avg WT"
         << setw(12) << "Avg TAT" << "\n";

    cout << "---------------------------------------------------\n";

    for (const auto& s : summary) {
        cout << left << setw(15) << s.name
             << setw(12) << fixed << setprecision(2) << s.avgWT
             << setw(12) << fixed << setprecision(2) << s.avgTAT
             << "\n";
    }

    cout << "===================================================\n";
}
