#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (using 1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half (indices 1 to N) and which one goes into the second half.
 * To maximize the sum of the first half, for each pair (A[i], A[2N + 1 - i]),
 * we should pick the maximum of the two values to be in the first half.
 * 
 * The pairs are:
 * (A[1], A[2N]), (A[2], A[2N-1]), ..., (A[N], A[N+1])
 * 
 * Total sum = sum_{i=1 to N} max(A[i], A[2N + 1 - i])
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    for (int i = 0; i < N; ++i) {
        // Pair index i with index (2N - 1 - i)
        // A[i] is the element at index i (0-indexed)
        // A[2N - 1 - i] is its mirror element
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
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