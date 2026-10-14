#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) = G.
 * Since we have Y ones in total, the remaining ones (Y - G) can be placed 
 * before the first zero or after the last zero.
 * Thus, we need sum(g_i) <= Y.
 * Since each g_i >= K, the minimum sum is (X - 1) * K.
 * So, (X - 1) * K <= Y.
 * Therefore, K <= Y / (X - 1).
 * The largest integer K is floor(Y / (X - 1)).
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    // X zeros create X-1 internal gaps.
    // We need at least K ones in each of these X-1 gaps.
    // Total ones required = K * (X - 1).
    // This must be <= Y.
    // K <= Y / (X - 1).
    
    long long K = Y / (X - 1);
    cout << K << "\n";
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