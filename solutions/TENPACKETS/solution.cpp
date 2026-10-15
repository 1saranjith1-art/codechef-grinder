#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * Possible combinations to get 10 packets:
 * 1. Five 2-packs: 5 * X
 * 2. Two 4-packs and one 2-pack: 2 * Y + X
 * 
 * We need to find the minimum of these two values.
 * Note: Since Y <= 2X, buying 4 packets for Y is always better or equal to 
 * buying two 2-packs for 2X.
 * 
 * Constraints:
 * T <= 1000
 * 1 <= X < Y <= 100
 * Y <= 2X
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        // Option 1: 5 * 2-packs = 5 * X
        long long option1 = 5 * x;

        // Option 2: 2 * 4-packs + 1 * 2-pack = 2 * Y + X
        long long option2 = 2 * y + x;

        // Output the minimum
        cout << min(option1, option2) << "\n";
    }

    return 0;
}