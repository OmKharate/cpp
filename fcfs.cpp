#include<iostream>
using namespace std;

class Process{
public:
    int pid;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int tat;  // Turn Around Time
    int wt;   // Waiting Time
    int start_time;
};

int main(){

    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    Process p[n];

    // Input
    for(int i = 0; i < n; i++){
        cout << "Enter Arrival Time and Burst Time for Process " << i + 1 << ": ";
        cin >> p[i].at >> p[i].bt;
        p[i].pid = i + 1;
    }

    // Sort by Arrival Time
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(p[j].at > p[j + 1].at){
                swap(p[j], p[j + 1]);
            }
        }
    }

    // FCFS Scheduling Calculation
    for(int i = 0; i < n; i++){

        if(i == 0){
            p[i].start_time = p[i].at;
        }
        else{
            if(p[i].at > p[i - 1].ct)
                p[i].start_time = p[i].at;
            else
                p[i].start_time = p[i - 1].ct;
        }

        p[i].ct = p[i].start_time + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }

    // Totals
    int ttat = 0;
    int twt = 0;

    for(int i = 0; i < n; i++){
        ttat += p[i].tat;
        twt += p[i].wt;
    }

    float avg_tat = (float)ttat / n;
    float avg_wt = (float)twt / n;

    // Output Table
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i = 0; i < n; i++){
        cout << p[i].pid << "\t"
             << p[i].at << "\t"
             << p[i].bt << "\t"
             << p[i].ct << "\t"
             << p[i].tat << "\t"
             << p[i].wt << "\n";
    }

    cout << "\nAverage Turn Around Time = " << avg_tat;
    cout << "\nAverage Waiting Time = " << avg_wt;

    return 0;
}