#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * We can choose A1 = X - 1, A2 = X, and A3 = X + 1.
 * Let's check the conditions:
 * 1. Mean: ((X - 1) + X + (X + 1)) / 3 = 3X / 3 = X. (Correct)
 * 2. Distinct: X-1, X, X+1 are always distinct. (Correct)
 * 3. Range: 1 <= A_i <= 1000.
 *    Given 2 <= X <= 100:
 *    - Minimum A1 = 2 - 1 = 1. (Valid)
 *    - Maximum A3 = 100 + 1 = 101. (Valid, since 101 <= 1000)
 * 
 * This simple construction works for all given constraints.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Output the constructed triplet
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}