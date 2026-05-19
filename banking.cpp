#include <iostream>
using namespace std;

int main() {

    int n, r;

    cout << "Enter number of processes: ";
    cin >> n;

    cout << "Enter number of resources: ";
    cin >> r;

    int alloc[n][r], max[n][r], need[n][r];
    int avail[r];

    // Input Allocation Matrix
    cout << "\nEnter Allocation Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            cin >> alloc[i][j];
        }
    }

    // Input Max Matrix
    cout << "\nEnter Max Matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            cin >> max[i][j];
        }
    }

    // Input Available Resources
    cout << "\nEnter Available Resources:\n";
    for(int i = 0; i < r; i++) {
        cin >> avail[i];
    }

    // Calculate Need Matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    bool finish[n] = {false};

    int safeSeq[n];
    int count = 0;

    while(count < n) {

        bool found = false;

        for(int i = 0; i < n; i++) {

            if(!finish[i]) {

                int j;

                for(j = 0; j < r; j++) {

                    if(need[i][j] > avail[j]) {
                        break;
                    }
                }

                // Process can execute
                if(j == r) {

                    for(int k = 0; k < r; k++) {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;

                    finish[i] = true;

                    found = true;
                }
            }
        }

        // Unsafe State
        if(!found) {
            cout << "\nSystem is NOT in safe state";
            return 0;
        }
    }

    // Safe State
    cout << "\nSystem is in SAFE state";

    cout << "\nSafe Sequence: ";

    for(int i = 0; i < n; i++) {

        cout << "P" << safeSeq[i];

        if(i != n - 1)
            cout << " -> ";
    }

    return 0;
}