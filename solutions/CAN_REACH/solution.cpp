#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The student starts at (0, 0) and moves by exactly K in either the x or y direction.
 * This means after n moves, the x-coordinate will be a multiple of K (x = a * K)
 * and the y-coordinate will be a multiple of K (y = b * K), where a and b are 
 * integers representing the net number of steps taken in the x and y directions.
 * 
 * Therefore, for the student to reach (x, y), both x and y must be divisible by K.
 * Since the moves can be positive or negative, we check if x % K == 0 and y % K == 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // Check if both coordinates are divisible by K.
        // The problem states K >= 1, so division by zero is not an issue.
        if (x % k == 0 && y % k == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}