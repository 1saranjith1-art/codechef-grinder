#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to form a binary string of length N with exactly K islands.
 * Each island must have a distinct length.
 * Let the lengths of the K islands be l_1, l_2, ..., l_K.
 * Since they must be distinct, the smallest possible sum of lengths is 
 * 1 + 2 + 3 + ... + K = K * (K + 1) / 2.
 * 
 * Between K islands, we need at least K-1 '1's to separate them if they are 
 * not at the ends. However, the definition of an island is a substring of 0s 
 * bounded by 1s or the ends of the string.
 * 
 * Let's visualize the structure:
 * If we have K islands, we need at least K-1 '1's to separate them.
 * Example: [Island 1] 1 [Island 2] 1 ... 1 [Island K]
 * Total length = (sum of lengths of islands) + (number of 1s).
 * 
 * To minimize the number of 1s:
 * - If an island is at the start or end, it doesn't necessarily need a '1' on that side.
 * - However, to have K distinct islands, we need at least K-1 '1's to separate them.
 * - Total length N >= (sum of lengths) + (K - 1).
 * - Minimum sum of lengths = K(K+1)/2.
 * - So, N >= K(K+1)/2 + K - 1.
 * 
 * Let's check:
 * K=1: N >= 1(2)/2 + 0 = 1. (Correct)
 * K=2: N >= 2(3)/2 + 1 = 4. (Sample 4: N=7, K=2 -> 7 >= 4, YES)
 * K=3: N >= 3(4)/2 + 2 = 8. (Sample 3: N=6, K=3 -> 6 < 8, NO)
 * 
 * The condition is N >= K*(K+1)/2 + K - 1.
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // The minimum length required for K distinct islands:
    // We need K islands of lengths 1, 2, ..., K.
    // Sum of lengths = K*(K+1)/2.
    // To separate K islands, we need at least K-1 ones.
    // Total length = K*(K+1)/2 + (K-1).
    
    long long min_len = (K * (K + 1)) / 2 + (K - 1);
    
    if (N >= min_len) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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