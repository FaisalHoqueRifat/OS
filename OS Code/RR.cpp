#include<bits/stdc++.h>
using namespace std;
int main() 
{
    int n, timeQuantum;

    // Input number of processes and time quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> timeQuantum;

    vector<int> burstTime(n), remainingTime(n), waitingTime(n, 0), turnaroundTime(n, 0);
    vector<pair<int, int>> ganttChart; // To store process execution and its time

    // Input burst times
    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    queue<int> readyQueue; // Queue for processes
    for (int i = 0; i < n; i++) {
        readyQueue.push(i); // Add all processes to the queue initially
    }

    int currentTime = 0;
    while (!readyQueue.empty()) {
        int currentProcess = readyQueue.front();
        readyQueue.pop();

        // Execute the process
        ganttChart.push_back({currentProcess + 1, currentTime}); // Record process and start time
        if (remainingTime[currentProcess] <= timeQuantum) {
            // Process completes execution
            currentTime += remainingTime[currentProcess];
            turnaroundTime[currentProcess] = currentTime;
            waitingTime[currentProcess] = turnaroundTime[currentProcess] - burstTime[currentProcess];
            remainingTime[currentProcess] = 0;
        } else {
            // Process partially executes and goes back to the queue
            currentTime += timeQuantum;
            remainingTime[currentProcess] -= timeQuantum;
            readyQueue.push(currentProcess); // Add process back to the queue
        }
    }

    // Add the final time to the Gantt Chart
    ganttChart.push_back({-1, currentTime}); // -1 indicates end of execution

    // Display Gantt Chart with Time
    cout << "\nGantt Chart:\n";
    for (size_t i = 0; i < ganttChart.size() - 1; i++) {
        cout << "| P" << ganttChart[i].first << " ";
    }
    cout << "|\n";
    for (int i = 0; i < ganttChart.size(); i++)
    {
        cout << ganttChart[i].second << " ";
    }
    cout << "\n";

    // Display process details
    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }

    // Calculate averages
    double totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    cout << "Average Waiting Time: " << totalWaitingTime / n << "\n";
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << "\n";

    return 0;
}
