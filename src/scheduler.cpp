#include "scheduler.h"
#include <algorithm>
using namespace std;

Scheduler::Scheduler(){}

void Scheduler::addProcess(int id, int arrivalTime, int burstTime){
    processes.emplace_back(id, arrivalTime, burstTime);
}

void Scheduler::runFCFS(){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime()<b.getArrivalTime();
    });

    int currentTime = 0;
    for(auto& process : processes){
        currentTime = max(currentTime, process.getArrivalTime());
        process.updateWaitingTime(currentTime);
        currentTime += process.getBurstTime();
    }
}

void Scheduler::runHRRN(){
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.getArrivalTime()<b.getArrivalTime();
    });

    int currentTime = 0;
    for(auto& process : processes){
        currentTime = max(currentTime, process.getArrivalTime());
        process.calculateResponseRatio(currentTime);
        process.updateWaitingTime(currentTime);
        currentTime += process.getBurstTime();
    }
}

const vector<Process>& Scheduler::getProcesses() const{
    return processes;
}