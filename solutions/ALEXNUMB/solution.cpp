#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given n distinct integers a_1, a_2, ..., a_n.
 * We need to find the number of pairs (i, j) such that 1 <= i, j <= n, i != j, and a_i < a_j.
 * 
 * Since all integers are distinct, for any two distinct indices i and j, 
 * either a_i < a_j or a_j < a_i.
 * 
 * The total number of pairs (i, j) with i != j is n * (n - 1).
 * Because exactly one of (a_i < a_j) or (a_j < a_i) must be true for any pair of distinct indices,
 * exactly half of the total pairs (i, j) where i != j will satisfy a_i < a_j.
 * 
 * Number of pairs = (n * (n - 1)) / 2.
 * 
 * Constraints:
 * n <= 100,000.
 * n * (n - 1) / 2 can be up to ~5 * 10^9, which exceeds the range of a 32-bit integer.
 * We must use long long to store the result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Read the n integers. 
        // Note: The values of a_i do not actually affect the count because 
        // they are all distinct, so the condition a_i < a_j will always 
        // be satisfied by exactly half of the pairs of distinct indices.
        long long temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
        }

        // Calculate nC2 = n * (n - 1) / 2
        long long result = (n * (n - 1)) / 2;
        cout << result << "\n";
    }

    return 0;
}