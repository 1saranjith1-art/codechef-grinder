#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB needs X points from Y matches.
 * Win = 2 points, Tie = 1 point, Loss = 0 points.
 * Let w be the number of wins, t be the number of ties, and l be the number of losses.
 * We have:
 * 1) w + t + l = Y
 * 2) 2*w + 1*t + 0*l = X
 * We want to minimize w.
 * From (2), t = X - 2*w.
 * Since t >= 0, we must have 2*w <= X, so w >= ceil(X/2).
 * Also, since w + t <= Y (because l >= 0), we have:
 * w + (X - 2*w) <= Y
 * X - w <= Y
 * w >= X - Y
 * 
 * Combining these, w >= max(0, X - Y).
 * Since we want the minimum w, the answer is max(0, X - Y).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // If X <= Y, we can get all points by tying matches (1 point each),
        // so 0 wins are required.
        // If X > Y, we need more points than the number of matches if we only tied.
        // Each win provides 2 points instead of 1.
        // Every win replaces a tie and adds 1 extra point.
        // We need (X - Y) extra points, so we need (X - Y) wins.
        if (X <= Y) {
            cout << 0 << "\n";
        } else {
            cout << (X - Y) << "\n";
        }
    }

    return 0;
}