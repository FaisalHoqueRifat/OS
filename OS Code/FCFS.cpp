#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    vector<int> processIDs(n), burstTime(n), waitingTime(n), turnaroundTime(n);
    for (int i = 0; i < n; i++)
    {
        processIDs[i] = i + 1;
        cout << "Enter Burst Time for Process P" << processIDs[i] << ": ";
        cin >> burstTime[i];
    }
    waitingTime[0] = 0; // First process has no waiting time
    for (int i = 1; i < burstTime.size(); i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    for (int i = 0; i < burstTime.size(); i++)
    {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }
    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (size_t i = 0; i < processIDs.size(); i++)
    {
        cout << "P" << processIDs[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] <<endl;
    }


    double totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) 
    {
        totalWaitingTime += waitingTime[i];
        totalTurnaroundTime += turnaroundTime[i];
    }
    cout << "Average Waiting Time: " << totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << totalTurnaroundTime / n << endl;
}