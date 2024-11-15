#include <iostream>
#include <string>
using namespace std;

bool canTransform(string s1, string s2) {
    int i = 0, j = 0;
    
    // Iterate through both strings
    while (i < s1.length() && j < s2.length()) {
        // If characters match (s1[i] matches s2[j] directly or s1[i] is the lowercase of s2[j])
        if (s1[i] == s2[j] || (s1[i] >= 'a' && s1[i] <= 'z' && toupper(s1[i]) == s2[j])) {
            // Move both pointers forward
            i++;
            j++;
        } 
        // If s1[i] is a lowercase letter, skip it
        else if (s1[i] >= 'a' && s1[i] <= 'z') {
            i++;
        }
        else {
            // If no match and s1[i] can't be deleted or converted, return false
            return false;
        }
    }

    // If j has reached the end of s2, it means we can transform s1 to s2
    return j == s2.length();
}

int main() {
    string s1, s2;

    // Input strings
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    // Check if transformation is possible
    if (canTransform(s1, s2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
