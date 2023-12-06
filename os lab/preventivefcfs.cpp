#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
public:
    int pid;
    int arrival_time;
    int burst_time;

    Process(int id, int arrival, int burst) : pid(id), arrival_time(arrival), burst_time(burst) {}
};

bool compareArrivalTime(const Process &p1, const Process &p2) {
    return p1.arrival_time < p2.arrival_time;
}

int main() {
    int n; // Number of processes
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes;

    // Input process details
    for (int i = 1; i <= n; i++) {
        int arrival, burst;
        cout << "Enter arrival time for process " << i << ": ";
        cin >> arrival;
        cout << "Enter burst time for process " << i << ": ";
        cin >> burst;
        processes.push_back(Process(i, arrival, burst));
    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int currentTime = 0; // Current time
    vector<Process> queue; // Queue for processes

    double totalTurnaroundTime = 0;
    double totalWaitingTime = 0;

    // Process the tasks
    while (!processes.empty()) {
        // Check for arrived processes and add them to the queue
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrival_time <= currentTime) {
                queue.push_back(*it);
                it = processes.erase(it);
            } else {
                break; // Processes are sorted by arrival time, so we can break early
            }
        }

        if (queue.empty()) {
            // If no processes in the queue, move time forward to the next process arrival
            currentTime = processes[0].arrival_time;
            continue;
        }

        // Sort the queue by burst time (FCFS)
        sort(queue.begin(), queue.end(), [](const Process &p1, const Process &p2) {
            return p1.burst_time < p2.burst_time;
        });

        // Execute the first process in the queue
        Process currentProcess = queue[0];
        cout << "Executing Process " << currentProcess.pid << " from time " << currentTime << " to time " << currentTime + currentProcess.burst_time << endl;

        totalWaitingTime += currentTime - currentProcess.arrival_time;
        totalTurnaroundTime += currentTime + currentProcess.burst_time - currentProcess.arrival_time;

        currentTime += currentProcess.burst_time;
        queue.erase(queue.begin());
    }

    // Calculate and print the average waiting time and average turnaround time
    double numProcesses = static_cast<double>(n);
    double avgWaitingTime = totalWaitingTime / numProcesses;
    double avgTurnaroundTime = totalTurnaroundTime / numProcesses;

    cout << "Average Waiting Time: " << avgWaitingTime << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime << endl;

    return 0;
}

