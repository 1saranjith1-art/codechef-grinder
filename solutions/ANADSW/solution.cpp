#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - N=1: Always sorted.
 * - N=2: Can only swap if |i-j| > 1. Impossible. Only sorted if A[0] <= A[1].
 * - N=3: Can swap (0, 2). Index 1 is isolated. A[1] must be the median of the three elements.
 * - N>=4: Can swap any two elements using an intermediate index. Always sortable.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        vector<int> B = A;
        sort(B.begin(), B.end());
        if (A[1] == B[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, we can swap any two elements.
        cout << "YES" << "\n";
    }
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