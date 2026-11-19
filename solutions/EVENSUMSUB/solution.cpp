#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the length of the longest subarray with an even sum.
 * A subarray sum from index i to j is even if:
 * (PrefixSum[j] - PrefixSum[i-1]) is even.
 * This happens if PrefixSum[j] and PrefixSum[i-1] have the same parity (both even or both odd).
 * 
 * Given N is small (up to 50), an O(N^2) approach is perfectly efficient.
 * We can iterate over all possible subarrays [i, j] and check their sum.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int max_len = 0;

    // Iterate over all possible starting points
    for (int i = 0; i < N; ++i) {
        long long current_sum = 0;
        // Iterate over all possible ending points
        for (int j = i; j < N; ++j) {
            current_sum += A[j];
            // Check if the sum of subarray A[i...j] is even
            if (current_sum % 2 == 0) {
                int current_len = j - i + 1;
                if (current_len > max_len) {
                    max_len = current_len;
                }
            }
        }
    }

    cout << max_len << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}