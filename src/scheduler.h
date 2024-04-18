#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <vector>
#include "process.h"

class Scheduler{
private:
    std::vector<Process> processes;

public:
    Scheduler();

    void addProcess(int id, int arrivalTime, int burstTime);
    void runFCFS();
    void runHRRN();
    
    const std::vector<Process>& getProcesses() const;
};

#endif