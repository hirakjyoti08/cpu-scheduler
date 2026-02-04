#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "Process.h"
#include "Summary.h"

AlgoStats fcfs(std::vector<Process> processes);
AlgoStats sjfNonPreemptive(std::vector<Process> processes);
AlgoStats roundRobin(std::vector<Process> processes, int quantum);

#endif
