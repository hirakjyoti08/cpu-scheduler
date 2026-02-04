#ifndef SUMMARY_H
#define SUMMARY_H

#include <vector>
#include <string>

struct AlgoStats {
    std::string name;
    double avgWT;
    double avgTAT;
};

void printSummary(const std::vector<AlgoStats>& summary);

#endif
