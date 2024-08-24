//Greedy Strategy-3
/*Implement a problem of minimum work to be done per day to CO2
finish given tasks within D days problem.
Statement: Given an array task[] of size N denoting amount of
work to be done for each task, the problem is to find the minimum
amount of work to be done on each day so that all the tasks can be
completed in at most D days. Note: On one day work can be done
for only one task.
Input: task[] = [3, 4, 7, 15], D = 10 Output: 4
Input: task[] = [30, 20, 22, 4, 21], D = 6 Output: 22
*/


#include <iostream>
#include <algorithm>
#include <climits> // For INT_MAX
#include <cmath>   // For ceil function
using namespace std;

// Function to check if all tasks can be completed within 'maxWork' work per day
bool ct(int maxWork, int tasks[], int nTasks, int days) {
    int tdRequired = 0;

    for (int i = 0; i < nTasks; i++) {
        // Calculate the number of days required for the current task
        int requiredDays = ceil(static_cast<double>(tasks[i]) / maxWork);
        tdRequired += requiredDays;

        // If more days are required than available, return false
        if (tdRequired > days) {
            return false;
        }
    }

    // If total days required are within the limit, return true
    return tdRequired <= days;
}

// Function to find the minimum work per day to complete all tasks within the given number of days
int findMinWork(int tasks[], int nTasks, int maxDays) {
    int minWork = 1;
    int maxWork = INT_MAX;

    // Set the upper bound for maxWork to the maximum value in tasks
    for (int i = 0; i < nTasks; i++) {
        maxWork = max(maxWork, tasks[i]);
    }

    // Variable to store the minimum work per day required
    int optimalDailyWork = maxWork;

    while (minWork <= maxWork) {
        int midWork = minWork + (maxWork - minWork) / 2;

        // If it's possible to complete tasks within 'maxDays' with 'midWork' per day
        if (ct(midWork, tasks, nTasks, maxDays)) {
            optimalDailyWork = midWork;
            maxWork = midWork - 1; // Try for a smaller maximum work per day
        } else {
            minWork = midWork + 1; // Increase the work per day
        }
    }

    return optimalDailyWork;
}

// Driver Code
int main() {
    int nTasks;
    cout << "Enter the number of tasks: ";
    cin >> nTasks;

    int* tasks = new int[nTasks]; // Dynamic array to hold task work values
    cout << "Enter the work for each task: ";
    for (int i = 0; i < nTasks; i++) {
        cin >> tasks[i];
    }

    int maxDays;
    cout << "Enter the number of days: ";
    cin >> maxDays;

    int result = findMinWork(tasks, nTasks, maxDays);
    cout << "Minimum work per day to complete all tasks in " << maxDays << " days is: " << result << endl;

    delete[] tasks; // Clean up the dynamically allocated array
    return 0;
}