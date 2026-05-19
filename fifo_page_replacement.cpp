#include <iostream>
using namespace std;

int main() {
    // 1. Define Data
    int nf, np;
    int hit = 0, fault = 0;
    int i, j, flag;
    int pos = 0;

    // Accept data from user
    cout << "Enter number of frames (nf): ";
    cin >> nf;

    cout << "Enter number of pages in reference string (np): ";
    cin >> np;

    int F[nf]; 
    int p[np];

    cout << "Enter the page reference string (space separated): ";
    for (i = 0; i < np; i++) {
        cin >> p[i];
    }

    // 2. Initialize Frames to -1
    for (i = 0; i < nf; i++) {
        F[i] = -1;
    }

    cout << "\nPage\t| Frame Status\t\t| Condition\n";

    // 3. FIFO Page Replacement
    for (i = 0; i < np; i++) {
        flag = 0;

        // Check for Hit
        for (j = 0; j < nf; j++) {
            if (F[j] == p[i]) {
                hit++;
                flag = 1;
                break;
            }
        }

        // If Fault occurs
        if (flag == 0) {
            F[pos] = p[i];
            pos++;
            fault++;

            if (pos == nf) {
                pos = 0;
            }
        }

        // Display Frames
        cout << p[i] << "\t| ";
        for (j = 0; j < nf; j++) {
            cout << F[j] << " ";
        }

        if (flag == 1) {
            cout << "\t\t| H\n";
        } else {
            cout << "\t\t| F\n";
        }
    }

    // 4. Ratios
    float hit_ratio = (float)hit / np;
    float miss_ratio = (float)fault / np;

    cout << "-------------------------------------------------\n";
    cout << "Total Hits   : " << hit << endl;
    cout << "Total Faults : " << fault << endl;
    cout << "Hit Ratio    : " << hit_ratio << endl;
    cout << "Miss Ratio   : " << miss_ratio << endl;

    return 0;
}
