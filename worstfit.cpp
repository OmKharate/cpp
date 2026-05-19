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

    // Worst Fit Logic
    for(int i = 0; i < np; i++) {

        int worst = -1;

        for(int j = 0; j < nb; j++) {

            if(allocated[j] == 0 && block[j] >= process[i]) {

                if(worst == -1 || block[j] > block[worst]) {
                    worst = j;
                }
            }
        }

        if(worst != -1) {

            blockNo[i] = worst + 1;
            allocated[worst] = 1;
            fragment[i] = block[worst] - process[i];
        }
        else {
            blockNo[i] = -1;
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