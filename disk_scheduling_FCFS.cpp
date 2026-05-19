#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, initial, totalHeadMovement = 0;

    cout << "Enter number of requests: ";
    cin >> n;

    int RQ[n];

    cout << "Enter the request sequence: ";
    for(int i = 0; i < n; i++) {
        cin >> RQ[i];
    }

    cout << "Enter initial head position: ";
    cin >> initial;

    cout << "\nSeek Sequence: " << initial;

    for(int i = 0; i < n; i++) {

        totalHeadMovement += abs(RQ[i] - initial);

        initial = RQ[i];

        cout << " -> " << RQ[i];
    }

    cout << "\n\nTotal Head Movement = "
         << totalHeadMovement << endl;

    cout << "Average Seek Time = "
         << (float)totalHeadMovement / n << endl;

    return 0;
}