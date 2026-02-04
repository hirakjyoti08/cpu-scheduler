#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"

void fcfs(std::vector<Process> processes);
void sjfNonPreemptive(std::vector<Process> processes);
void roundRobin(std::vector<Process> processes, int quantum);

#endif
