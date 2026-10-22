#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is alternating if the parity of adjacent elements is different.
 * This means for any index i, parity(A[i]) != parity(A[i+1]).
 * There are only two possible patterns for an alternating array of length N:
 * Pattern 1: Starts with Odd (Odd, Even, Odd, Even, ...)
 * Pattern 2: Starts with Even (Even, Odd, Even, Odd, ...)
 * 
 * We can calculate the number of changes required to match Pattern 1 and Pattern 2,
 * then take the minimum of the two.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // count1: changes needed if we force the pattern starting with Odd (1)
    // count2: changes needed if we force the pattern starting with Even (0)
    int count1 = 0;
    int count2 = 0;

    for (int i = 0; i < N; ++i) {
        int parity = A[i] % 2;
        
        // Pattern 1: Expected parity at index i is (i % 2 == 0 ? 1 : 0)
        int expected1 = (i % 2 == 0) ? 1 : 0;
        if (parity != expected1) {
            count1++;
        }

        // Pattern 2: Expected parity at index i is (i % 2 == 0 ? 0 : 1)
        int expected2 = (i % 2 == 0) ? 0 : 1;
        if (parity != expected2) {
            count2++;
        }
    }

    cout << min(count1, count2) << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}