#include "process.h"

Process::Process(int id, int arrivalTime, int burstTime)
    : id(id), arrivalTime(arrivalTime), burstTime(burstTime), waitingTime(0), responseRatio(0) {}

void Process::calculateResponseRatio(int currentTime){
    responseRatio = (currentTime - arrivalTime + burstTime)/static_cast<double>(burstTime);
}

void Process::updateWaitingTime(int currentTime){
    waitingTime = currentTime - arrivalTime;
}

int Process::getId() const{
    return id;
}

int Process::getArrivalTime() const{
    return arrivalTime;
}

int Process::getBurstTime() const{
    return burstTime;
}

int Process::getWaitingTime() const{
    return waitingTime;
}

double Process::getResponseRatio() const{
    return responseRatio;
}