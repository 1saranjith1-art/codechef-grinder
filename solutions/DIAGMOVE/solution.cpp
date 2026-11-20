#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The allowed moves are (i+1, j+1), (i+1, j-1), (i-1, j+1), (i-1, j-1).
 * Notice that in every move, both the x-coordinate and the y-coordinate change by 1 or -1.
 * This means the parity of the sum of coordinates (x + y) remains invariant in terms of 
 * its change relative to the number of steps.
 * 
 * Let (x, y) be the target. After k steps, the new coordinates (x', y') satisfy:
 * x' = sum(dx_i) where dx_i in {1, -1}
 * y' = sum(dy_i) where dy_i in {1, -1}
 * 
 * Note that (x' + y') = sum(dx_i + dy_i).
 * Since dx_i and dy_i are both odd (1 or -1), their sum (dx_i + dy_i) is always even (2, 0, or -2).
 * Therefore, the sum of the coordinates (x + y) must always be even if we start at (0, 0).
 * 
 * If (x + y) is even, we can reach the point. If (x + y) is odd, we cannot.
 * We can check this using (x + y) % 2 == 0. Since x and y can be negative, 
 * we use abs(x + y) % 2 == 0 or simply (x + y) % 2 == 0 (in C++, -1 % 2 is -1, 
 * so we check if the result is 0).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The sum of coordinates must be even for the point to be reachable.
        // (x + y) % 2 == 0 handles both positive and negative sums correctly
        // because 0 % 2 is 0, and any even number % 2 is 0.
        if ((x + y) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}