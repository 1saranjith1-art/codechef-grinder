#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Total points played: S = P1 + P2.
 * The server changes every K points.
 * Number of full K-point intervals passed: blocks = (P1 + P2) / K.
 * 
 * - 0 to K-1 points: Chef serves (0 blocks)
 * - K to 2K-1 points: Cook serves (1 block)
 * - 2K to 3K-1 points: Chef serves (2 blocks)
 * - 3K to 4K-1 points: Cook serves (3 blocks)
 * 
 * Rule: If (blocks % 2 == 0), it is Chef's turn. Otherwise, it is Cook's turn.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long p1, p2, k;
        cin >> p1 >> p2 >> k;

        // Calculate total points and the number of completed K-point intervals
        long long total_points = p1 + p2;
        long long blocks = total_points / k;

        // Determine the server based on the parity of the blocks
        if (blocks % 2 == 0) {
            cout << "CHEF" << "\n";
        } else {
            cout << "COOK" << "\n";
        }
    }

    return 0;
}