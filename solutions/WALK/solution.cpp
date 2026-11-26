#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let V be the initial velocity at the first segment.
 * At segment i (1-indexed), the velocity will be V - (i - 1).
 * The condition is: V - (i - 1) >= W[i] for all i from 1 to N.
 * Rearranging this: V >= W[i] + i - 1.
 * To satisfy this for all i, V must be at least the maximum value of (W[i] + i - 1).
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the input array (or O(1) if processed on the fly).
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long max_v = 0;
    for (int i = 0; i < n; ++i) {
        long long w;
        cin >> w;
        // The condition is V >= W[i] + i
        // Since i is 0-indexed here, the formula is W[i] + i
        long long required_v = w + i;
        if (required_v > max_v) {
            max_v = required_v;
        }
    }
    cout << max_v << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}