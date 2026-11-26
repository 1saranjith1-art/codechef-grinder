# [Distinct Substring (DISTSUB)](https://www.codechef.com/problems/DISTSUB)

- **Difficulty Rating**: 1251
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $K$, determine if it is possible to construct a binary string of length $N$ that contains exactly $K$ "islands" of zeros, where each island has a distinct length. An island is defined as a contiguous block of zeros.

## Intuition & Mathematical Observation
To determine if such a string exists, we must find the minimum possible length $N$ required to accommodate $K$ islands of distinct lengths.

1.  **Island Lengths**: To minimize the total length, we should choose the smallest possible distinct positive integers for the lengths of the $K$ islands: $1, 2, 3, \dots, K$.
    *   The sum of these lengths is $\sum_{i=1}^{K} i = \frac{K(K+1)}{2}$.
2.  **Separators**: To ensure these $K$ blocks of zeros are distinct islands, they must be separated by at least one '1'. For $K$ islands, we need at least $K-1$ ones to act as separators between them.
3.  **Total Length Constraint**: The total length $N$ must be at least the sum of the lengths of the islands plus the number of separators:
    $$N \ge \left( \sum_{i=1}^{K} i \right) + (K - 1)$$
    $$N \ge \frac{K(K+1)}{2} + K - 1$$

If the given $N$ satisfies this inequality, we can always construct the string (e.g., by placing the islands of lengths $1, 2, \dots, K$ separated by single '1's and padding the remaining length with extra '1's). If $N$ is smaller than this value, it is impossible to satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic check.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to form a binary string of length N with exactly K islands.
 * Each island must have a distinct length.
 * The smallest possible sum of lengths for K distinct islands is 
 * 1 + 2 + 3 + ... + K = K * (K + 1) / 2.
 * 
 * To separate K islands, we need at least K-1 '1's.
 * Therefore, the minimum length N required is:
 * N >= K*(K+1)/2 + (K-1)
 */

void solve() {
    long long N, K;
    cin >> N >> K;

    // Calculate the minimum length required
    long long min_len = (K * (K + 1)) / 2 + (K - 1);
    
    if (N >= min_len) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```