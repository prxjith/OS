#include <iostream>
#include <vector>
using namespace std;
void calculateNeed(vector<vector<int>>& need, const vector<vector<int>>& max, const vector<vector<int>>& allocation, int P, int R) {
    for (int i = 0; i < P; ++i)
        for (int j = 0; j < R; ++j)
            need[i][j] = max[i][j] - allocation[i][j];
}

bool isSafe(const vector<int>& available, const vector<vector<int>>& max, const vector<vector<int>>& allocation, int P, int R) {
    vector<int> work = available;
    vector<bool> finish(P, false);
    vector<vector<int>> need(P, vector<int>(R));
    calculateNeed(need, max, allocation, P, R);
    while (true) {
        bool found = false;
        for (int i = 0; i < P; ++i) {
            if (!finish[i]) {
                bool possible = true;
                for (int j = 0; j < R; ++j) {
                    if (need[i][j] > work[j]) {
                        possible = false;
                        break;
                    }
                }
                if (possible) {
                    for (int j = 0; j < R; ++j)
                        work[j] += allocation[i][j];
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if (!found)
            break;
    }
    for (int i = 0; i < P; ++i) {
        if (!finish[i])
            return false;
    }
    return true;
}
int main() {
    int P, R;
    cout << "Enter the number of processes: ";
    cin >> P;
    cout << "Enter the number of resource types: ";
    cin >> R;
    vector<vector<int>> max(P, vector<int>(R));
    vector<vector<int>> allocation(P, vector<int>(R));
    vector<int> available(R);
    cout << "Enter the max matrix:\n";
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            cin >> max[i][j];
        }
    }
    cout << "Enter the allocation matrix:\n";
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            cin >> allocation[i][j];
        }
    }
    cout << "Enter the available resources:\n";
    for (int i = 0; i < R; ++i) {
        cin >> available[i];
    }
    if (isSafe(available, max, allocation, P, R)) {
        cout << "The system is in a safe state.\n";
    } else {
        cout << "Deadlock detected.\n";
    }
    return 0;
}
