#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The cities are numbered 1, 2, 3, 4, ...
 * Roads exist:
 * 1. Between (2i+1) and (2i+2) for i >= 0.
 *    This means: (1,2), (3,4), (5,6), ...
 *    Condition: |a - b| == 1 AND (min(a, b) is odd)
 * 
 * 2. Between consecutive odd numbers: (1,3), (3,5), (5,7), ...
 *    Condition: |a - b| == 2 AND (a is odd AND b is odd)
 * 
 * 3. Between consecutive even numbers: (2,4), (4,6), (6,8), ...
 *    Condition: |a - b| == 2 AND (a is even AND b is even)
 * 
 * Combining these:
 * - If |a - b| == 1:
 *      They are connected if the smaller one is odd.
 *      Example: (1,2) -> |1-2|=1, min=1 (odd) -> YES
 *      Example: (2,3) -> |2-3|=1, min=2 (even) -> NO
 * - If |a - b| == 2:
 *      They are connected if both are odd or both are even.
 *      This is equivalent to saying (a % 2 == b % 2).
 * - Otherwise:
 *      NO.
 */

void solve() {
    long long a, b;
    cin >> a >> b;

    long long diff = abs(a - b);

    if (diff == 1) {
        // Case 1: Adjacent numbers. 
        // Connected if the smaller one is odd.
        // If min(a, b) is odd, then min(a, b) % 2 != 0.
        if (min(a, b) % 2 != 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else if (diff == 2) {
        // Case 2 & 3: Difference of 2.
        // Connected if both are odd or both are even.
        if (a % 2 == b % 2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // No other roads exist.
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    if (!(cin >> q)) return 0;
    while (q--) {
        solve();
    }
    return 0;
}