#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<int> arrivalTime(n), burstTime(n), remainingTime(n);
    vector<int> completionTime(n), waitingTime(n), turnaroundTime(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Arrival Time for Process P" << i + 1 << ": ";
        cin >> arrivalTime[i];
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }
    int complete = 0, currentTime = 0, minIndex = -1;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    vector<pair<int, int>> ganttChart; // {StartTime, ProcessID}
    vector<int> ganttTimes;

    while (complete < n)
    {
        minIndex = -1;
        int minRemaining = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arrivalTime[i] <= currentTime && remainingTime[i] > 0 && remainingTime[i] < minRemaining)
            {
                minRemaining = remainingTime[i];
                minIndex = i;
            }
        }
        if (minIndex == -1)
        {
            currentTime++;
            continue;
        }
        if (ganttChart.empty() || ganttChart.back().second != minIndex)
        {
            ganttChart.push_back({currentTime, minIndex});
        }
        remainingTime[minIndex]--;
        currentTime++;
        if (remainingTime[minIndex] == 0)
        {
            complete++;
            completionTime[minIndex] = currentTime;
            turnaroundTime[minIndex] = completionTime[minIndex] - arrivalTime[minIndex];
            waitingTime[minIndex] = turnaroundTime[minIndex] - burstTime[minIndex];
            totalWaitingTime += waitingTime[minIndex];
            totalTurnaroundTime += turnaroundTime[minIndex];
        }
    }

    for (auto entry : ganttChart)
    {
        ganttTimes.push_back(entry.first);
    }
    ganttTimes.push_back(currentTime);

    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << endl;
    }
    cout << "Average Waiting Time: " << (double)totalWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << (double)totalTurnaroundTime / n << endl;

    cout << "\nGantt Chart: \n";

    // Print the top row (process blocks)
    cout << "|";
    for (int i = 0; i < ganttChart.size(); i++)
    {
        int processId = ganttChart[i].second + 1;
        int width = ganttTimes[i + 1] - ganttTimes[i]; // Width of the block
        cout << " P" << processId << " ";
        for (int j = 1; j < width; j++)
            cout << " "; // Add extra spaces for wider blocks
        cout << "|";
    }
    cout << endl;

    // Print the bottom row (time intervals)
    for (size_t i = 0; i < ganttTimes.size(); i++)
    {
        cout << ganttTimes[i];
        if (i < ganttTimes.size() - 1)
        {
            int width = ganttTimes[i + 1] - ganttTimes[i]; // Width of the block
            for (int j = 0; j < width + 2; j++)
                cout << " "; // Match width of the process blocks
        }
    }
    cout << endl;
    return 0;
}
