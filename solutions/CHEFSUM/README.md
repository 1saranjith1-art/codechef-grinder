# [Little Chef and Sums (CHEFSUM)](https://www.codechef.com/problems/CHEFSUM)

- **Difficulty Rating**: 1252
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we define:
- `prefixSum(i)` = $\sum_{j=1}^{i} A[j]$
- `suffixSum(i)` = $\sum_{j=i}^{N} A[j]$
- `f(i)` = `prefixSum(i)` + `suffixSum(i)`

The goal is to find the index $i$ (1-based) that minimizes $f(i)$. If there are multiple such indices, return the smallest one.

## Intuition & Mathematical Observation
By expanding the definition of $f(i)$:
$$f(i) = (A[1] + A[2] + \dots + A[i]) + (A[i] + A[i+1] + \dots + A[N])$$

We can rewrite this as:
$$f(i) = (A[1] + A[2] + \dots + A[N]) + A[i]$$

Since the sum of all elements in the array $(A[1] + \dots + A[N])$ is a constant value regardless of $i$, minimizing $f(i)$ is mathematically equivalent to minimizing $A[i]$. 

Therefore, the problem reduces to finding the index of the smallest element in the array. If the minimum value appears multiple times, the problem asks for the smallest index, which is naturally handled by iterating through the array and updating the minimum index only when a strictly smaller value is found.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to traverse the array once to find the minimum element.
- **Space Complexity**: $O(1)$, as we only store the current minimum value and its index, processing the input on the fly without needing to store the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(i) = prefixSum(i) + suffixSum(i)
 * f(i) = (A[1] + ... + A[N]) + A[i]
 * 
 * Minimizing f(i) is equivalent to minimizing A[i].
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // Initialize min_val with a value larger than any possible A[i] (max 10^5)
    int min_val = 200000; 
    int min_idx = -1;
    
    for (int i = 1; i <= N; ++i) {
        int val;
        cin >> val;
        // Update only if we find a strictly smaller value to keep the smallest index
        if (val < min_val) {
            min_val = val;
            min_idx = i;
        }
    }
    
    cout << min_idx << "\n";
}

int main() {
    // Fast I/O for performance
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