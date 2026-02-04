#ifndef PROCESS_H
#define PROCESS_H

#include <string>

struct Process {
    std::string pid;
    int arrival;
    int burst;
    int remaining;

    int completion = 0;
    int waiting = 0;
    int turnaround = 0;
};

#endif
