#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3*x + 4*y = N, where x, y >= 0.
 * This is a variation of the Frobenius Coin Problem (or Change-Making Problem).
 * For two coprime numbers a and b, the largest number that cannot be expressed 
 * as a*x + b*y is (a*b - a - b).
 * Here, a=3 and b=4. The largest number that cannot be formed is (3*4 - 3 - 4) = 5.
 * Numbers that cannot be formed: 1, 2, 5.
 * All other positive integers can be formed:
 * 3 = 3*1
 * 4 = 4*1
 * 6 = 3*2
 * 7 = 3*1 + 4*1
 * 8 = 4*2
 * 9 = 3*3
 * 10 = 3*2 + 4*1
 * ... and so on.
 */

void solve() {
    int n;
    cin >> n;
    
    // Based on the analysis, N cannot be formed if N is 1, 2, or 5.
    if (n == 1 || n == 2 || n == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}