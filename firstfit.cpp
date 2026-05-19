#include <iostream>
using namespace std;

int main() {

    int nb, np;

    cout << "Enter number of blocks: ";
    cin >> nb;

    cout << "Enter number of processes: ";
    cin >> np;

    int block[nb], process[np];
    int allocated[nb], blockNo[np], fragment[np];

    // Initialize allocated array
    for(int i = 0; i < nb; i++) {
        allocated[i] = 0;
    }

    // Input block sizes
    cout << "\nEnter block sizes:\n";
    for(int i = 0; i < nb; i++) {
        cout << "Block " << i + 1 << ": ";
        cin >> block[i];
    }

    // Input process sizes
    cout << "\nEnter process sizes:\n";
    for(int i = 0; i < np; i++) {
        cout << "Process " << i + 1 << ": ";
        cin >> process[i];
    }

    // First Fit Logic
    for(int i = 0; i < np; i++) {

        blockNo[i] = -1;

        for(int j = 0; j < nb; j++) {

            if(allocated[j] == 0 && block[j] >= process[i]) {

                blockNo[i] = j + 1;
                allocated[j] = 1;
                fragment[i] = block[j] - process[i];

                break;
            }
        }
    }

    // Output
    cout << "\nProcess\tProcess Size\tBlock No\tFragment\n";

    for(int i = 0; i < np; i++) {

        cout << "P" << i + 1 << "\t" << process[i] << "\t\t";

        if(blockNo[i] != -1)
            cout << blockNo[i] << "\t\t" << fragment[i];
        else
            cout << "Not Allocated";

        cout << endl;
    }

    return 0;
} 