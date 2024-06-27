#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};
void findWaitingTime(vector<Process>& processes) {
    processes[0].waitingTime = 0;
    for (size_t i = 1; i < processes.size(); i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}
void findTurnaroundTime(vector<Process>& processes) {
    for (size_t i = 0; i < processes.size(); i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}
void findAverageTimes(vector<Process>& processes) {
    int totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (const auto& process : processes) {
        totalWaitingTime += process.waitingTime;
        totalTurnaroundTime += process.turnaroundTime;
    }
    double avgWaitingTime = (double) totalWaitingTime / processes.size();
    double avgTurnaroundTime = (double) totalTurnaroundTime / processes.size();
    cout << fixed << setprecision(2);
    cout << "Average waiting time: " << avgWaitingTime << endl;
    cout << "Average turnaround time: " << avgTurnaroundTime << endl;
}
void displayProcessInfo(const vector<Process>& processes) {
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (const auto& process : processes) {
        cout << "P" << process.id << "\t" 
             << process.burstTime << "\t\t" 
             << process.waitingTime << "\t\t" 
             << process.turnaroundTime << "\n";
    }
}
int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        cout << "Enter burst time for process " << processes[i].id << ": ";
        cin >> processes[i].burstTime;
    }
    findWaitingTime(processes);
    findTurnaroundTime(processes);
    displayProcessInfo(processes);
    findAverageTimes(processes);
    return 0;
}

