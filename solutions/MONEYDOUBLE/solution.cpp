#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has X rupees initially and Y years.
 * Each year, he can either:
 * 1. Add 1000: X = X + 1000
 * 2. Double: X = X * 2
 * 
 * Since Y is very small (up to 10), we want to maximize X.
 * Comparing the two operations:
 * If X < 1000, adding 1000 is always better than doubling (X + 1000 > 2X).
 * If X > 1000, doubling is always better than adding 1000 (2X > X + 1000).
 * If X = 1000, both operations result in 2000.
 * 
 * Therefore, the greedy strategy is:
 * In each year, compare (X + 1000) and (X * 2) and pick the maximum.
 * Since Y is at most 10, a simple loop per test case is O(Y), which is O(1) per test case.
 * Total complexity: O(T * Y), which is well within the 1s time limit for 10^5 test cases.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        for (int i = 0; i < y; ++i) {
            // Greedy choice: at each step, take the maximum of the two options
            long long add_option = x + 1000;
            long long double_option = x * 2;
            
            if (add_option > double_option) {
                x = add_option;
            } else {
                x = double_option;
            }
        }

        cout << x << "\n";
    }

    return 0;
}