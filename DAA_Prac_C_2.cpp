#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
    bool dp[n + 1][sum + 1];

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;  // A sum of 0 can always be achieved with an empty subset
    }
    for (int j = 1; j <= sum; j++) {
        dp[0][j] = false; // A non-zero sum cannot be achieved with zero elements
    }

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1]) {
                dp[i][j] = dp[i - 1][j];  // Exclude the element
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]]; // Include or exclude the element
            }
        }
    }

    return dp[n][sum];
}

int main() {
    int set1[] = {3, 34, 4, 12, 5, 2};
    int sum1 = 9;
    int n1 = sizeof(set1) / sizeof(set1[0]);
    if (isSubsetSum(set1, n1, sum1)) {
        cout << "Subset with sum " << sum1 << " exists." << endl;
    } else {
        cout << "Subset with sum " << sum1 << " does not exist." << endl;
    }

    int set2[] = {3, 34, 4, 12, 5, 2};
    int sum2 = 30;
    int n2 = sizeof(set2) / sizeof(set2[0]);
    if (isSubsetSum(set2, n2, sum2)) {
        cout << "Subset with sum " << sum2 << " exists." << endl;
    } else {
        cout << "Subset with sum " << sum2 << " does not exist." << endl;
    }

    return 0;
}
