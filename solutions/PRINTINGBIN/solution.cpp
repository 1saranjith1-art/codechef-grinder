#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Score(B) is the number of transitions (0 to 1 or 1 to 0) in the array.
 * We need to find an array C such that C != A and Score(C) == Score(A).
 * 
 * Case 1: N = 1
 * If A = [0], C = [1]. If A = [1], C = [0].
 * Score is always 0. This works.
 * 
 * Case 2: N > 1
 * If we flip every bit in the array (0 becomes 1, 1 becomes 0), the transitions 
 * remain exactly the same. If A_i != A_{i+1}, then (1-A_i) != (1-A_{i+1}).
 * Thus, Score(A) == Score(flipped A).
 * Since A != flipped A (because N >= 1), flipping all bits is a valid solution.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Flipping all bits: 0 -> 1, 1 -> 0
    // This preserves the number of transitions (Score) and ensures A != C.
    for (int i = 0; i < N; ++i) {
        cout << (1 - A[i]) << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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