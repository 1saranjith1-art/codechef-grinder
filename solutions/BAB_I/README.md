# [Chef And Babla (BAB_I)](https://www.codechef.com/problems/BAB_I)

- **Difficulty Rating**: 1346
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the maximum non-negative integer $X$ such that for every element $A_i$ in the array, $A_i$ does not lie in the closed interval $[-X, X]$. If no such non-negative integer $X$ exists, output $-1$.

## Intuition & Mathematical Observation
The condition that $A_i$ is not in $[-X, X]$ is equivalent to saying that $|A_i| > X$ for all $i$. 

1. **Constraint Analysis**: We need $X < |A_i|$ for all $i$. This implies that $X$ must be strictly less than the minimum absolute value present in the array:
   $$X < \min(|A_1|, |A_2|, \dots, |A_N|)$$
2. **Maximizing $X$**: Since $X$ must be an integer, the largest possible value for $X$ is $\min(|A_i|) - 1$.
3. **Edge Cases**:
   - If the array contains $0$, then $\min(|A_i|) = 0$. The condition becomes $X < 0$. Since $X$ must be a non-negative integer ($X \ge 0$), no such $X$ exists. In this case, we output $-1$.
   - If $\min(|A_i|) - 1 < 0$ (which happens if the minimum absolute value is $0$), we output $-1$.
   - The logic holds that if the smallest absolute value is $1$, then $X = 1 - 1 = 0$, which is a valid non-negative integer.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array exactly once to find the minimum absolute value.
- **Space Complexity**: $O(1)$, as we only store a few variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the maximum X such that for all A_i, A_i is not in [-X, X].
 * This is equivalent to saying: |A_i| > X for all i.
 * Therefore, X < min(|A_i|).
 * The maximum integer X is min(|A_i|) - 1.
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
```