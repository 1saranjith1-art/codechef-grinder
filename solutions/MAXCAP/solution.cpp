#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift has two constraints:
 * 1. Maximum number of people: 8
 * 2. Maximum weight capacity: 500 kg
 * 
 * Given X friends each weighing Y kg:
 * - Total weight = X * Y
 * - Condition 1: X <= 8
 * - Condition 2: X * Y <= 500
 * 
 * Both conditions must be satisfied for the answer to be "YES".
 * Constraints: 1 <= T <= 1000, 1 <= X, Y <= 100.
 * Since X*Y <= 10000, standard 'int' is sufficient to prevent overflow.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // Check both constraints:
        // 1. Number of people must be <= 8
        // 2. Total weight must be <= 500
        if (x <= 8 && (x * y) <= 500) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}