/*Implement a problem of maximize Profit by trading 
stocks based on given rate per day. 
Statement: Given an array arr[] of N positive integers 
which denotes the cost of selling and buying a stock on 
each of the N days. The task is to find the maximum 
profit that can be earned by buying a stock on or selling 
all previously bought stocks on a particular day. 
Input: arr[] = {2, 3, 5}                      Output: 5  
Input: arr[] = {8, 5, 1}                      Output: 0 */
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum profit
int mP(int* prices, int n)
{
	int profit = 0, cD = n - 1;

	// Start from the last day
	while (cD > 0) {

		int day = cD - 1;

		while (day >= 0
			&& (prices[cD]
				> prices[day])) {

			profit += (prices[cD]
					- prices[day]);

			day--;
		}
		cD = day;
	}

	// Return the profit
	return profit;
}


int main()
{
	// Given array of prices
	int prices[] = { 2, 3, 5 };

	int N = sizeof(prices) / sizeof(prices[0]);

	// Function Call
	cout << mP(prices, N);

	return 0;
}
