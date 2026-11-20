#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * The number of slices X is reached by starting with 2^k slices (where 2^k <= X)
 * and cutting (X - 2^k) of those slices into two.
 * Each cut turns 1 slice of size (1/2^k) into 2 slices of size (1/2^(k+1)).
 * Thus, we have 2 * (X - 2^k) smaller slices and (2^k - (X - 2^k)) larger slices.
 * 
 * To find 2^k efficiently:
 * For a 64-bit integer, the largest power of 2 <= X is 1LL << (63 - __builtin_clzll(X)).
 */

void solve() {
    long long X;
    if (!(cin >> X)) return;

    // __builtin_clzll returns the number of leading zeros in the 64-bit representation.
    // 63 - __builtin_clzll(X) gives the index of the highest set bit.
    long long p = 1LL << (63 - __builtin_clzll(X));

    if (p == X) {
        cout << 0 << "\n";
    } else {
        // Number of smaller slices is 2 * (X - p)
        cout << 2 * (X - p) << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}