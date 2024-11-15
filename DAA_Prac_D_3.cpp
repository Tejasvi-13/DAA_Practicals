#include <iostream>
#include <vector>
using namespace std;

void printAllSubsets(vector<int>& arr) {
    int n = arr.size();
    int subsetCount = 1 << n;  // Total subsets is 2^n

    for (int mask = 0; mask < subsetCount; ++mask) {
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // Check if the i-th bit in mask is set
                cout << arr[i] << " ";
            }
        }
        cout << endl;  // Newline for each subset
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    cout << "All subsets of the array are:" << endl;
    printAllSubsets(arr);
    return 0;
}
