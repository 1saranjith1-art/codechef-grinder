#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (i, j) such that 1 <= i < j <= N and A[i] * A[j] > 0.
 * A[i] * A[j] > 0 if and only if:
 * 1. Both A[i] and A[j] are positive.
 * 2. Both A[i] and A[j] are negative.
 * 
 * If we have 'pos' count of positive numbers and 'neg' count of negative numbers:
 * - The number of ways to choose two positive numbers is pos * (pos - 1) / 2.
 * - The number of ways to choose two negative numbers is neg * (neg - 1) / 2.
 * - Zeroes do not contribute to any positive product.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    cin >> N;
    
    long long pos_count = 0;
    long long neg_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val > 0) {
            pos_count++;
        } else if (val < 0) {
            neg_count++;
        }
    }
    
    // Calculate combinations nC2 = n * (n - 1) / 2
    long long ans = (pos_count * (pos_count - 1)) / 2 + (neg_count * (neg_count - 1)) / 2;
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}