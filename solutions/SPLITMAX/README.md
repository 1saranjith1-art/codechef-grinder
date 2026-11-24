# [Split and Maximize (SPLITMAX)](https://www.codechef.com/problems/SPLITMAX)

- **Difficulty Rating**: 1313
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we are allowed to perform an operation any number of times: choose an element $C_i$ and replace it with two positive integers $X$ and $Y$ such that $X + Y = C_i$. The goal is to maximize the value of the function $f(A) = \sum_{i=1}^{M} \sum_{j=1, j \neq i}^{M} (A_i \cdot A_j)$, where $M$ is the final number of elements in the array.

## Intuition & Mathematical Observation
Let $S$ be the sum of all elements in the array. Note that the sum $S$ remains invariant regardless of how many times we split the elements.

The function $f(A)$ can be rewritten using the identity:
$$S^2 = \left(\sum_{i=1}^M A_i\right)^2 = \sum_{i=1}^M A_i^2 + \sum_{i \neq j} A_i A_j$$
Thus, $f(A) = S^2 - \sum_{i=1}^M A_i^2$.

To maximize $f(A)$ while $S$ is constant, we must **minimize** the sum of squares $\sum A_i^2$. 
When we split an element $C_i$ into $X$ and $Y$ (where $X+Y=C_i$), the sum of squares changes from $C_i^2$ to $X^2 + Y^2$. Since $(X+Y)^2 = X^2 + Y^2 + 2XY$, we have $X^2 + Y^2 = C_i^2 - 2XY$. To minimize the sum of squares, we need to maximize $2XY$. 

This implies we should split elements into the smallest possible positive integers (which is $1$) as many times as possible. If we split every initial element $C_i$ into $C_i$ ones, the final array will consist of $S$ ones.
The value of the function then becomes:
$$f(A) = S^2 - \sum_{k=1}^S (1)^2 = S^2 - S = S(S - 1)$$

Since $S$ can be very large, we perform all calculations modulo $998244353$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we only need to iterate through the array once to calculate the sum $S$.
- **Space Complexity**: $O(1)$, as we only store the running sum and a few variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * f(A) = sum_{i=1 to M} sum_{j=1, j!=i to M} (A_i * A_j)
 * Let S = sum(A_i).
 * Then S^2 = (sum A_i)^2 = sum(A_i^2) + sum_{i!=j} (A_i * A_j)
 * Therefore, f(A) = S^2 - sum(A_i^2).
 * 
 * To maximize f(A), we minimize sum(A_i^2). Splitting elements into 1s 
 * minimizes this sum. The final array consists of S ones.
 * f(A) = S^2 - S = S * (S - 1).
 */

void solve() {
    int N;
    cin >> N;
    long long S = 0;
    long long MOD = 998244353;
    
    for (int i = 0; i < N; ++i) {
        long long val;
        cin >> val;
        S = (S + val) % MOD;
    }
    
    // Result is S * (S - 1) mod MOD
    long long ans = (S * (S - 1 + MOD)) % MOD;
    cout << ans << "\n";
}

int main() {
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