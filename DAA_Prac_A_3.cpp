/*Divide and Conquer 
Implement a problem of smallest number with at 
least n trailing zeroes in factorial. 
Statement: Given a number n. The task is to find the 
smallest number whose factorial contains at least n 
trailing zeroes. 
Input : n = 1                  Output : 5  
Input : n = 6                  Output : 25 */
#include <iostream>
using namespace std;

// Function to count the number of trailing zeroes in the factorial of num
int countTrailingZeroes(int num) {
    int count = 0;
    while (num >= 5) {
        num /= 5;
        count += num;
    }
    return count;
}

// Function to find the smallest number whose factorial contains at least n trailing zeroes
int findMinFact(int n) {
    if (n == 0) return 0; // Special case, 0! = 1, which has no trailing zero

    int low = 0;
    int high = 5 * n;  // Upper bound heuristic

    while (low < high) {
        int mid = (low + high) / 2;
        if (countTrailingZeroes(mid) < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }
    return low;
}

int main() {
    int n;
    cout << "Enter the number of trailing zeroes required: ";
    cin >> n;

    int result = findMinFact(n);
    cout << "The smallest number whose factorial has at least " << n << " trailing zeroes is: " << result << endl;

    return 0;
}