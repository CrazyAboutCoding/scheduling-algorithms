#include <iostream>
#include "scheduler.h"
using namespace std;

int main() {
    Scheduler scheduler;

    scheduler.addProcess(1, 0, 10);
    scheduler.addProcess(2, 2, 5);
    scheduler.addProcess(3, 4, 3);
    scheduler.addProcess(4, 6, 8);

    scheduler.runFCFS();
    scheduler.runHRRN();
    
    cout<<"Process ID\tArrival Time\tBurst Time\tWaiting Time\tResponse Ratio\n";
    for(const auto& process : scheduler.getProcesses()){
        cout<<process.getId()<<"\t\t"<<process.getArrivalTime()<<"\t\t"<<process.getBurstTime()<<"\t\t"
                <<process.getWaitingTime()<<"\t\t"<<process.getResponseRatio()<<"\n";
    }

    return 0;
}
