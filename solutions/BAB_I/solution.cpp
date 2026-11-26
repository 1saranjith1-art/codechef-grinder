#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum X such that for all A_i, A_i is not in [-X, X].
 * This is equivalent to saying:
 * For all i, |A_i| > X.
 * 
 * Let B_i = |A_i|. The condition becomes B_i > X for all i.
 * This means X < B_i for all i.
 * Therefore, X < min(|A_i|).
 * 
 * Since X must be a non-negative integer, the maximum such X is min(|A_i|) - 1.
 * 
 * However, there is a constraint: if 0 is present in the array, then |0| = 0.
 * The condition |A_i| > X becomes 0 > X.
 * Since X must be non-negative (X >= 0), there is no such X if 0 is in the array.
 * 
 * Also, if min(|A_i|) - 1 < 0, then no such non-negative X exists.
 * This happens if min(|A_i|) = 0 (i.e., 0 is in the array).
 */

void solve() {
    int N;
    cin >> N;
    
    long long min_abs = -1;
    bool zero_exists = false;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        long long abs_val = abs(val);
        
        if (abs_val == 0) {
            zero_exists = true;
        }
        
        if (min_abs == -1 || abs_val < min_abs) {
            min_abs = abs_val;
        }
    }
    
    if (zero_exists) {
        cout << -1 << "\n";
    } else {
        // The condition is |A_i| > X.
        // So X < min(|A_i|).
        // Since X is an integer, max X = min(|A_i|) - 1.
        long long ans = min_abs - 1;
        if (ans < 0) {
            cout << -1 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
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