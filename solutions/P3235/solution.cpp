#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given a permutation P of length N.
 * L_i = count of elements P[j] such that j < i and P[j] < P[i].
 * R_i = count of elements P[j] such that j > i and P[j] > P[i].
 * We need to count indices i where L_i == R_i.
 * 
 * Constraints: N <= 100.
 * An O(N^2) approach per test case is perfectly acceptable given N=100 and T=10^4.
 * Total complexity: O(T * N^2) = 10^4 * 10^4 = 10^8 operations, which fits within 1s.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    int count = 0;
    for (int i = 0; i < N; ++i) {
        int L_i = 0;
        int R_i = 0;

        // Calculate L_i: elements to the left smaller than P[i]
        for (int j = 0; j < i; ++j) {
            if (P[j] < P[i]) {
                L_i++;
            }
        }

        // Calculate R_i: elements to the right greater than P[i]
        for (int j = i + 1; j < N; ++j) {
            if (P[j] > P[i]) {
                R_i++;
            }
        }

        if (L_i == R_i) {
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}