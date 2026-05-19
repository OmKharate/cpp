#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n, head, totalHeadMovement = 0;

    cout << "Enter number of requests: ";
    cin >> n;

    int RQ[n];
    bool completed[n];

    cout << "Enter request sequence: ";
    for(int i = 0; i < n; i++) {
        cin >> RQ[i];
        completed[i] = false;
    }

    cout << "Enter initial head position: ";
    cin >> head;

    cout << "\nSeek Sequence: " << head;

    for(int i = 0; i < n; i++) {

        int min = 9999;
        int index = -1;

        // Find nearest request
        for(int j = 0; j < n; j++) {

            if(!completed[j]) {

                int distance = abs(RQ[j] - head);

                if(distance < min) {
                    min = distance;
                    index = j;
                }
            }
        }

        totalHeadMovement += min;

        head = RQ[index];

        completed[index] = true;

        cout << " -> " << head;
    }

    cout << "\n\nTotal Head Movement = "
         << totalHeadMovement << endl;

    cout << "Average Seek Time = "
         << (float)totalHeadMovement / n << endl;

    return 0;
}