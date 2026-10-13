#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each insurance costs X dollars.
 * Commission per insurance = 20% of X = 0.2 * X = X / 5.
 * Let N be the number of insurances sold.
 * Total earnings = N * (X / 5).
 * We need Total earnings >= 100.
 * N * (X / 5) >= 100
 * N * X >= 500
 * N >= 500 / X
 * Since N must be an integer, N = ceil(500 / X).
 * 
 * Using integer arithmetic, ceil(A / B) can be calculated as (A + B - 1) / B.
 * So, N = (500 + X - 1) / X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate minimum N such that N * (x / 5.0) >= 100
        // Which simplifies to N * x >= 500
        // N = ceil(500 / x)
        long long ans = (500 + x - 1) / x;
        
        cout << ans << "\n";
    }

    return 0;
}