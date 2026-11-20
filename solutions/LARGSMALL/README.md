# [Larger Smaller (LARGSMALL)](https://www.codechef.com/problems/LARGSMALL)

- **Difficulty Rating**: 1035
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the count of integers $X$ such that there exists at least one element in $A$ smaller than $X$ and at least one element in $A$ larger than $X$.

## Intuition & Mathematical Observation
To satisfy the condition for a given $X$:
1. There must exist an element $A_i < X$. This is only possible if $X$ is strictly greater than the minimum value in the array ($X > \min(A)$).
2. There must exist an element $A_j > X$. This is only possible if $X$ is strictly less than the maximum value in the array ($X < \max(A)$).

Combining these, $X$ must satisfy the inequality:
$$\min(A) < X < \max(A)$$

The number of integers in the range $(\min(A), \max(A))$ is calculated as:
- If $\min(A) \ge \max(A)$ (which occurs if all elements are identical), there are no such integers, so the answer is $0$.
- Otherwise, the count of integers between $\min(A)$ and $\max(A)$ is given by the formula:
  $$\text{Count} = \max(A) - \min(A) - 1$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array once to find the minimum and maximum values.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the input storage), as we only need to maintain the `min_val` and `max_val` variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An integer X is "good" if there exists an element in the array smaller than X
 * and an element in the array larger than X.
 * Let min_val be the minimum value in the array A.
 * Let max_val be the maximum value in the array A.
 * 
 * For X to be good:
 * 1. There must exist A_i < X, which implies X > min_val.
 * 2. There must exist A_j > X, which implies X < max_val.
 * 
 * Therefore, X must satisfy: min_val < X < max_val.
 * The number of such integers is the count of integers in the open interval (min_val, max_val).
 * If min_val >= max_val (which happens if all elements are the same), there are no such integers.
 * Otherwise, the count is (max_val - min_val - 1).
 */

void solve() {
    int N;
    cin >> N;
    int min_val = 101; // Constraints state A_i <= 100
    int max_val = 0;   // Constraints state A_i >= 1
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val < min_val) min_val = val;
        if (val > max_val) max_val = val;
    }
    
    if (min_val >= max_val) {
        cout << 0 << "\n";
    } else {
        // The number of integers X such that min_val < X < max_val
        // is (max_val - min_val - 1)
        cout << (max_val - min_val - 1) << "\n";
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
```