#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = sum_{i=1 to M} sum_{j=1, j!=i to M} (A_i * A_j)
 * Let S = sum(A_i).
 * Then S^2 = (sum A_i)^2 = sum(A_i^2) + sum_{i!=j} (A_i * A_j)
 * Therefore, f(A) = S^2 - sum(A_i^2).
 * 
 * When we split an element C_i into X and Y (where X+Y = C_i),
 * the new sum S remains the same.
 * The term sum(A_i^2) changes from C_i^2 to X^2 + Y^2.
 * Since X, Y > 0 and X+Y = C_i, X^2 + Y^2 = X^2 + (C_i - X)^2 = 2X^2 - 2*C_i*X + C_i^2.
 * To maximize f(A), we need to minimize sum(A_i^2).
 * To minimize X^2 + Y^2 given X+Y = C_i, we should make X and Y as small as possible.
 * The smallest positive integer is 1.
 * Thus, we should split every C_i into C_i ones.
 * 
 * If we split every C_i into C_i ones, the final array consists of S ones, where S = sum(C_i).
 * The number of elements M = S.
 * f(A) = S^2 - sum(1^2 for k=1 to S) = S^2 - S = S * (S - 1).
 * 
 * Since S can be up to 2*10^5 * 10^9 = 2*10^14, we must perform calculations modulo 998244353.
 */

void solve() {
    int N;
    cin >> N;
    long long S = 0;
    long long MOD = 998244353;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        S = (S + val) % MOD;
    }
    
    // Result is S * (S - 1) mod MOD
    long long ans = (S * (S - 1 + MOD)) % MOD;
    cout << ans << "\n";
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