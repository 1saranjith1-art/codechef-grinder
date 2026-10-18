#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n be the number of trial sessions.
 * Cost of n sessions = n coins.
 * Remaining budget = Y - n.
 * Discount percentage = n * D %.
 * Discounted membership price = X * (1 - (n * D) / 100).
 * Chef can purchase if: (Y - n) >= X * (1 - (n * D) / 100).
 * 
 * Constraints:
 * 1 <= Y <= X <= 50.
 * Since X is at most 50, n cannot exceed 50 (because if n > Y, he has no money left).
 * We can iterate n from 0 to 50 to find the minimum n that satisfies the condition.
 * If no such n exists in the range [0, Y], output -1.
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // Check n from 0 up to Y
    for (int n = 0; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // Discounted price = X - (X * n * D) / 100
        // To avoid floating point issues, use:
        // remaining_budget >= X - (X * n * D) / 100
        // Multiply by 100: 100 * (Y - n) >= 100 * X - X * n * D
        
        if (100 * remaining_budget >= 100 * X - X * n * D) {
            cout << n << "\n";
            return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}