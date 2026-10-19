#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The air conditioner takes X minutes to drop from X degrees to X-1 degrees.
 * To go from N to M, we need to drop the temperature (N - M) times.
 * 
 * Let the current temperature be T_curr.
 * To go from T_curr to T_curr - 1, it takes T_curr minutes.
 * 
 * Total time = (N) + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum.
 * The sum of integers from 1 to N is N*(N+1)/2.
 * The sum of integers from 1 to M is M*(M+1)/2.
 * The required sum is (Sum from 1 to N) - (Sum from 1 to M).
 * Total time = (N * (N + 1) / 2) - (M * (M + 1) / 2).
 * 
 * Constraints: N <= 40. The maximum result will be roughly 40*41/2 = 820,
 * which fits easily into a standard integer.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Calculate sum from M+1 to N
        // Formula: (N*(N+1)/2) - (M*(M+1)/2)
        long long total_time = (n * (n + 1) / 2) - (m * (m + 1) / 2);
        
        cout << total_time << "\n";
    }

    return 0;
}