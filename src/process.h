#ifndef PROCESS_H
#define PROCESS_H

class Process{
private:
    int id;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    double responseRatio;

public:
    Process(int id, int arrivalTime, int burstTime);

    void calculateResponseRatio(int currentTime);
    void updateWaitingTime(int currentTime);

    int getId() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getWaitingTime() const;
    double getResponseRatio() const;
};

#endif