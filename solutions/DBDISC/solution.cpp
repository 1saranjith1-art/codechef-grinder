#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the more expensive item be M = max(A[i], A[j]) and the other be m = min(A[i], A[j]).
 * The discount on M is min(M/2, 100).
 * The final cost is m + (M - min(M/2, 100)).
 * We need to maximize B[i] + B[j] such that final cost <= K.
 * 
 * Constraints:
 * N <= 100, A_i, B_i, K <= 400.
 * An O(N^2) approach per test case is perfectly fine (100 * 100^2 = 1,000,000 operations).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_tastiness = 0;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long cost1 = A[i];
            long long cost2 = A[j];
            
            long long M = max(cost1, cost2);
            long long m = min(cost1, cost2);
            
            // Discount is min(50% of M, 100)
            long long discount = min(M / 2, 100LL);
            long long final_cost = m + (M - discount);
            
            if (final_cost <= K) {
                possible = true;
                max_tastiness = max(max_tastiness, B[i] + B[j]);
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
    }
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