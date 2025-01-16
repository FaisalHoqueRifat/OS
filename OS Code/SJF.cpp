#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin>>n;
    vector<int> processID(n), burstTime(n), waitingTime(n), turnaroundTime(n);
    for (int i = 0; i < n; i++)
    {
        processID[i] = i + 1;
        cout << "Enter Burst Time for Process P" << processID[i] << ": ";
        cin >> burstTime[i];
    }
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (burstTime[j] < burstTime[minIndex]) 
            {
                minIndex = j;
            }
        }
        swap(burstTime[i], burstTime[minIndex]);
        swap(processID[i], processID[minIndex]);
    }

    waitingTime[0] = 0;
    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    for (int i = 0; i < n; i++) 
    {
        turnaroundTime[i] = waitingTime[i] + burstTime[i];
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++) 
    {
        cout << "P" << processID[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
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