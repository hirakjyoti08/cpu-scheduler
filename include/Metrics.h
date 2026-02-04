#ifndef METRICS_H
#define METRICS_H

#include <vector>
#include <string>
#include "Process.h"
#include "Summary.h"

void printMetrics(const std::vector<Process>& processes);

AlgoStats computeAverages(const std::string& algoName,
                          const std::vector<Process>& processes);

#endif
