#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Let wA be the number of wins for team A, lA be the number of losses for team A, and dA be the number of draws.
 * Let wB be the number of wins for team B, lB be the number of losses for team B, and dB be the number of draws.
 * 
 * Since they play against each other:
 * - Every win for A is a loss for B (wA = lB)
 * - Every win for B is a loss for A (wB = lA)
 * - Every draw for A is a draw for B (dA = dB = d)
 * 
 * Scores:
 * X = 3 * wA + d
 * Y = 3 * wB + d
 * 
 * We want to minimize d.
 * From the equations:
 * X % 3 = d % 3
 * Y % 3 = d % 3
 * 
 * Since d is the number of draws, d must be non-negative.
 * Also, X = 3 * wA + d implies d = X % 3.
 * Since 0 <= X, Y <= 14, the remainder when divided by 3 is always 0, 1, or 2.
 * The minimum number of draws is simply X % 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The points from wins are always multiples of 3.
        // Any points not divisible by 3 must come from draws.
        // Since each draw gives 1 point to each team, the number of draws
        // must be equal to X % 3 (which is also equal to Y % 3).
        cout << (x % 3) << "\n";
    }

    return 0;
}