#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef lives for L years. We are given a string S of length L where '1' is a good year
 * and '0' is a bad year. Chef goes to heaven if there exists some L' (1 <= L' <= L)
 * such that the number of good years in the first L' years is >= 50% of L'.
 * 
 * Let 'good' be the count of '1's in the prefix of length i (1-indexed).
 * The condition is: good / i >= 0.5
 * This is equivalent to: 2 * good >= i
 * 
 * We iterate through the string, maintaining a running count of good years.
 * At each year i, we check if 2 * good >= i. If this condition is met at any point,
 * Chef can go to heaven.
 * 
 * Time Complexity: O(L) per test case, O(sum of L) total.
 * Space Complexity: O(L) to store the string.
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_years = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current year is i + 1
        // Condition: good_years / (i + 1) >= 0.5
        // Equivalent to: 2 * good_years >= i + 1
        if (2 * good_years >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}