#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N colours of balloons.
 * The i-th colour balloon costs i rupees.
 * We are given A_i, the number of balloons of colour i.
 * The total cost is the sum of (A_i * i) for all i from 1 to N.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= 100.
 * Maximum possible cost per test case: 
 * Sum_{i=1 to 100} (100 * i) = 100 * (100 * 101 / 2) = 100 * 5050 = 505,000.
 * This fits well within a standard 32-bit integer, but using long long is safer 
 * and good practice in competitive programming.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        long long A_i;
        cin >> A_i;
        // The i-th colour has cost i
        total_cost += (A_i * i);
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}