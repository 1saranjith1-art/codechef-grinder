#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles {0, k, 2k, ..., m*k} such that m*k <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on tiles {(N+1), (N+1)-k, (N+1)-2k, ...}.
 * This means the ball lands on tile x if (N+1 - x) is a multiple of k.
 * Mathematically, (N+1 - x) % k == 0, which is equivalent to (N+1) % k == x % k.
 * 
 * Constraints:
 * T <= 10^5, N <= 10^9.
 * We need O(1) per test case.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Forward journey check: x is a multiple of k
        bool forward = (x % k == 0);

        // Backward journey check: (N+1 - x) is a multiple of k
        // This is equivalent to (N + 1) % k == x % k
        bool backward = ((n + 1 - x) % k == 0);

        if (forward || backward) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}