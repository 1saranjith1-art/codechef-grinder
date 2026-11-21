# [No 4 Please (NO4S)](https://www.codechef.com/problems/NO4S)

- **Difficulty Rating**: 993
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array consisting only of the integers $\{1, 2, 3\}$, we want to remove the minimum number of elements such that no two elements in the remaining array sum up to $4$.

## Intuition & Mathematical Observation
To ensure no two elements sum to $4$, we must avoid the following combinations:
1. **(1, 3)**: If we keep any $1$s, we cannot keep any $3$s.
2. **(2, 2)**: If we keep any $2$s, we can keep at most one $2$ (since $2+2=4$).

Based on these constraints, we have two primary strategies to maximize the number of elements kept:
- **Strategy A**: Keep all $1$s and at most one $2$.
- **Strategy B**: Keep all $3$s and at most one $2$.

We calculate the number of elements kept for both strategies and choose the maximum. The final answer is the total number of elements $N$ minus the maximum number of elements we can keep.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the size of the array, as we iterate through the array once to count the occurrences of $1, 2,$ and $3$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store counts regardless of the input size.

## Solution Code

```cpp
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

    // We can keep at most one 2 if any 2s exist
    int keep2 = (c2 > 0 ? 1 : 0);
    
    // Option 1: Keep all 1s and at most one 2
    int opt1 = c1 + keep2;
    
    // Option 2: Keep all 3s and at most one 2
    int opt2 = c3 + keep2;
    
    // Maximize the number of elements kept
    int max_kept = max(opt1, opt2);
    
    // Result is total elements minus the maximum we can keep
    cout << N - max_kept << "\n";
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