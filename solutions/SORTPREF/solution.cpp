#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to sort the array A. An operation at index i (1-indexed) costs A[i] 
 * and sorts the prefix A[1...i].
 * After the operation, the array becomes: 1, 2, ..., i, A[i+1], ..., A[N].
 * This is sorted if and only if A[i+1...N] is equal to {i+1, i+2, ..., N}.
 * 
 * We iterate through all possible i from 1 to N. If the condition holds,
 * the cost is A[i-1] (using 0-based indexing for the array).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Check if already sorted
    bool sorted = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] != i + 1) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << 0 << "\n";
        return;
    }

    int min_cost = INT_MAX;
    // Try performing an operation at index i (1-based)
    for (int i = 1; i <= N; ++i) {
        // Check if suffix A[i...N-1] is {i+1, ..., N}
        bool possible = true;
        for (int j = i; j < N; ++j) {
            if (A[j] != j + 1) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            min_cost = min(min_cost, A[i - 1]);
        }
    }

    cout << min_cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}