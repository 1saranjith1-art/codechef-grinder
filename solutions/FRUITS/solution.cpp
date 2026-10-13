#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We can perform at most K operations.
 * Each operation allows us to increase the count of the fruit that has a smaller quantity by 1.
 * Our goal is to minimize |N - M|.
 * 
 * Strategy:
 * 1. Identify which fruit is smaller.
 * 2. Use the K coins to increase the smaller count until it equals the larger count or we run out of coins.
 * 3. If we run out of coins before they are equal, the difference is (larger - (smaller + K)).
 * 4. If we reach equality, the difference is 0.
 */

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    // Ensure n is the smaller value to simplify logic
    if (n > m) {
        swap(n, m);
    }

    // Now n <= m. We want to increase n using k coins.
    // The difference is m - n.
    // We can increase n by at most k.
    
    long long diff = m - n;
    
    if (k >= diff) {
        // We can make them equal or even surpass, but since we want minimum difference,
        // we stop at equality (diff 0).
        cout << 0 << "\n";
    } else {
        // We use all k coins to reduce the difference.
        cout << (diff - k) << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}