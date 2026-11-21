#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array elements are restricted to {1, 2, 3}.
 * A pair (B_i, B_j) sums to 4 if:
 * 1. (1, 3) or (3, 1)
 * 2. (2, 2)
 * 
 * To make the array "good", we must ensure no such pairs exist.
 * - If we keep any 1s, we cannot keep any 3s.
 * - If we keep any 2s, we can keep at most one 2 (because 2+2=4).
 * 
 * Strategy:
 * Let c1 = count of 1s, c2 = count of 2s, c3 = count of 3s.
 * 
 * Option 1: Keep only 1s and at most one 2.
 *   Number of elements kept = c1 + (c2 > 0 ? 1 : 0)
 *   Deletions = N - (c1 + (c2 > 0 ? 1 : 0))
 * 
 * Option 2: Keep only 3s and at most one 2.
 *   Number of elements kept = c3 + (c2 > 0 ? 1 : 0)
 *   Deletions = N - (c3 + (c2 > 0 ? 1 : 0))
 * 
 * We take the minimum of these two options.
 */

void solve() {
    int N;
    cin >> N;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 1) c1++;
        else if (a == 2) c2++;
        else if (a == 3) c3++;
    }

    int keep2 = (c2 > 0 ? 1 : 0);
    
    // Option 1: Keep all 1s and at most one 2
    int opt1 = c1 + keep2;
    
    // Option 2: Keep all 3s and at most one 2
    int opt2 = c3 + keep2;
    
    int max_kept = max(opt1, opt2);
    cout << N - max_kept << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}