#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points, we are left with (N - K) indices
 *    that must NOT be fixed points.
 * 2. Let M = N - K. We need to check if there exists a derangement of M elements.
 * 3. A derangement of M elements exists if and only if M != 1.
 *    - If M = 0, we have 0 elements left, which is a valid derangement (0 fixed points).
 *    - If M = 1, we have 1 element left, which must be a fixed point (P_i = i),
 *      so it is impossible to have 0 fixed points among these remaining elements.
 *    - If M >= 2, we can always form a derangement (e.g., swapping elements).
 * 
 * Therefore, the condition is:
 * - If K == N, it is always possible (the identity permutation).
 * - If K == N - 1, it is impossible (because if N-1 elements are fixed, the last one must be fixed too).
 * - Otherwise, it is always possible.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    if (K == N - 1) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
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