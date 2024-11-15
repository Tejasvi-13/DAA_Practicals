#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void findDistinctSubsets(vector<int>& arr) {
    // Sort the array to handle duplicates
    sort(arr.begin(), arr.end());
    set<vector<int>> subsets;  // Use a set to store unique subsets
    int n = arr.size();

    // Loop over all possible subsets
    for (int mask = 0; mask < (1 << n); ++mask) {
        vector<int> subset;
        
        // Build the subset for the current mask
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {  // Check if i-th bit is set
                subset.push_back(arr[i]);
            }
        }
        
        // Insert subset into the set
        subsets.insert(subset);
    }

    // Print all unique subsets
    cout << "Distinct subsets are:\n";
    for (const auto& subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
}

int main() {
    vector<int> arr = {1, 2, 2};
    findDistinctSubsets(arr);
    return 0;
}
