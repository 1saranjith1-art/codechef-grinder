#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N coins with values v_1, v_2, ..., v_N.
 * We need to select two distinct coins such that the absolute difference 
 * between their values is minimized.
 * 
 * Approach:
 * 1. If we sort the array of coin values, the minimum difference between any 
 *    two elements must occur between adjacent elements in the sorted array.
 * 2. Proof: Suppose we have sorted values a <= b <= c. The difference (c - a) 
 *    is (c - b) + (b - a). Since (c - b) >= 0 and (b - a) >= 0, it follows 
 *    that (c - a) >= (c - b) and (c - a) >= (b - a). Thus, the minimum 
 *    difference must be between adjacent elements.
 * 3. Algorithm:
 *    a. Sort the array of size N.
 *    b. Iterate from i = 0 to N-2 and calculate v[i+1] - v[i].
 *    c. Keep track of the minimum difference found.
 * 
 * Complexity:
 * - Time: O(N log N) due to sorting, where N is the number of coins.
 * - Space: O(N) to store the coin values.
 * - Constraints: Sum of N <= 5 * 10^5, which fits well within the 1s time limit.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    
    // Sort the coin values to bring potential pairs with minimum difference together
    sort(v.begin(), v.end());
    
    // Initialize min_diff with a large value
    long long min_diff = LLONG_MAX;
    
    // Compare adjacent elements
    for (int i = 0; i < n - 1; ++i) {
        long long diff = v[i + 1] - v[i];
        if (diff < min_diff) {
            min_diff = diff;
        }
        // Optimization: if diff is 0, it's the absolute minimum possible
        if (min_diff == 0) break;
    }
    
    cout << min_diff << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}