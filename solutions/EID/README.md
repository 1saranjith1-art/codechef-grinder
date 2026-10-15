# [Chef and Eid (EID)](https://www.codechef.com/problems/EID)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ coins with various values, we need to select two distinct coins such that the absolute difference between their values is minimized. We are required to output this minimum difference.

## Intuition & Mathematical Observation
To minimize the difference $|v_i - v_j|$ between any two elements in a set, the most efficient approach is to sort the array first. 

**Why sorting works:**
Consider three sorted values $a \le b \le c$. The difference between the two furthest elements is $(c - a)$. We can express this as:
$$(c - a) = (c - b) + (b - a)$$
Since both $(c - b) \ge 0$ and $(b - a) \ge 0$, it is mathematically guaranteed that $(c - a)$ will always be greater than or equal to either $(c - b)$ or $(b - a)$. 

Therefore, the minimum difference between any two elements in a set must exist between two **adjacent** elements in the sorted version of that set. By sorting the array in $O(N \log N)$ time and performing a single linear scan to compare adjacent elements, we can find the global minimum difference efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N$ is the number of coins. The dominant factor is the sorting algorithm. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the coin values in a vector.

## Solution Code

```cpp
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
 * 2. Algorithm:
 *    a. Sort the array of size N.
 *    b. Iterate from i = 0 to N-2 and calculate v[i+1] - v[i].
 *    c. Keep track of the minimum difference found.
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
```