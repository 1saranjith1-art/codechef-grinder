#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the XOR sum of all elements A_1, A_2, ..., A_N.
 * If we remove no element, the XOR sum is S.
 * If we remove an element A_i, the new XOR sum is S ^ A_i.
 * We want to find min(S, min_{i=1 to N} (S ^ A_i)).
 * 
 * Complexity:
 * Calculating S takes O(N).
 * Calculating S ^ A_i for all i takes O(N).
 * Total time complexity per test case: O(N).
 * Sum of N over test cases is 3*10^5, so O(N) is well within the 1s time limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int total_xor = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_xor ^= A[i];
    }

    // Option 1: Don't remove any element
    int min_xor = total_xor;

    // Option 2: Remove exactly one element A[i]
    // The new XOR sum will be total_xor ^ A[i]
    for (int i = 0; i < N; ++i) {
        int current_xor = total_xor ^ A[i];
        if (current_xor < min_xor) {
            min_xor = current_xor;
        }
    }

    cout << min_xor << "\n";
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