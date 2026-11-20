#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at X1 and moves at +1 per second. After t seconds, his position is P1 = X1 + t.
 * Friend is at X2 and moves at +2 per second. After t seconds, his position is P2 = X2 + 2t.
 * 
 * They meet if P1 = P2 for some t >= 0.
 * X1 + t = X2 + 2t
 * X1 - X2 = 2t - t
 * X1 - X2 = t
 * 
 * Since t must be non-negative (t >= 0), the condition for them to meet is:
 * X1 - X2 >= 0
 * X1 >= X2
 * 
 * If X1 >= X2, they will meet at time t = X1 - X2.
 * If X1 < X2, the friend is already ahead and moving faster, so they will never meet.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2;
        cin >> x1 >> x2;

        // Based on the derivation X1 >= X2
        if (x1 >= x2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}