#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum) {
    int dp[sum + 1] = {0};  // Initialize all dp elements to 0
    dp[0] = 1;              // Base case: one way to make sum 0 (no coins)

    // Iterate over each coin
    for (int i = 0; i < n; i++) {
        // Update dp array for all sums greater than or equal to coins[i]
        for (int j = coins[i]; j <= sum; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[sum];
}

int main() {
    int coins1[] = {1, 2, 3};
    int sum1 = 4;
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    cout << "Number of ways to make sum " << sum1 << " is " << countWays(coins1, n1, sum1) << endl;

    int coins2[] = {2, 5, 3, 6};
    int sum2 = 10;
    int n2 = sizeof(coins2) / sizeof(coins2[0]);
    cout << "Number of ways to make sum " << sum2 << " is " << countWays(coins2, n2, sum2) << endl;

    return 0;
}
