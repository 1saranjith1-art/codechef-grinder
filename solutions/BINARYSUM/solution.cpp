#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * A binary string of length N with no two adjacent digits equal must be alternating.
 * Pattern 1: 010101...
 * Pattern 2: 101010...
 * 
 * If N is even:
 * Pattern 1 (01...01): N/2 ones.
 * Pattern 2 (10...10): N/2 ones.
 * Possible K: N/2.
 * 
 * If N is odd:
 * Pattern 1 (01...0): N/2 ones.
 * Pattern 2 (10...1): (N+1)/2 ones.
 * Possible K: N/2 or (N+1)/2.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;

    if (N % 2 == 0) {
        if (K == N / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    } else {
        if (K == N / 2 || K == (N + 1) / 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}