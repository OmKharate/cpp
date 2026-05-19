#include <iostream>
using namespace std;

// Structure for Process
struct Process
{
    int pid;
    int at;
    int bt;
    int tat;
    int wt;
    int rbt;   // original burst time
};

int main()
{
    int n, tq;
    int y = 0;   // completed processes
    int x = 0;   // current CPU time
    int i = 0;   // process index

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter Time Quantum: ";
    cin >> tq;

    Process p[n];

    
    for (int j = 0; j < n; j++)
    {
        cout << "Enter AT and BT for Process " << j + 1 << ": ";
        cin >> p[j].at >> p[j].bt;

        p[j].pid = j + 1;
        p[j].rbt = p[j].bt;
        p[j].tat = 0;
        p[j].wt = 0;
    }

    
    while (true)
    {
        bool executed = false;

        if (p[i].bt > 0 && p[i].at <= x)
        {
            executed = true;

            if (p[i].bt > tq)
            {
                x = x + tq;
                p[i].bt = p[i].bt - tq;
            }
            else
            {
                x = x + p[i].bt;
                p[i].bt = 0;

                p[i].tat = x - p[i].at;
                p[i].wt = p[i].tat - p[i].rbt;

                y++;
            }
        }

        
        if (y == n)
        {
            break;
        }

        
        if (!executed)
        {
            x++;
        }

       
        if (i == n - 1)
        {
            i = 0;
        }
        else
        {
            i++;
        }
    }


    cout << "\nProcess\tAT\tBT\tTAT\tWT\n";

    for (int j = 0; j < n; j++)
    {
        cout << "P" << p[j].pid << "\t"
             << p[j].at << "\t"
             << p[j].rbt << "\t"
             << p[j].tat << "\t"
             << p[j].wt << endl;
    }

    return 0;
}