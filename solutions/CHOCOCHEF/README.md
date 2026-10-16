# [Chocolate Distribution (CHOCOCHEF)](https://www.codechef.com/problems/CHOCOCHEF)

- **Difficulty Rating**: 1104
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to distribute $N$ chocolates into three jars ($a, b, c$) such that:
1. $a + b + c = N$
2. $a, b, c \ge 1$
3. Exactly two jars contain the same number of chocolates.
4. At least one jar contains an odd number of chocolates.

## Intuition & Mathematical Observation
To satisfy the condition that exactly two jars are equal, we can set two jars to a value $x$ and the third jar to $N - 2x$. We must ensure $N - 2x \ge 1$, which implies $x \le \frac{N-1}{2}$.

*   **Case 1: $N$ is even.**
    If we set $x = 1$, the jars become $(1, 1, N-2)$. 
    - Since $N \ge 4$ (implied by the constraints for three jars), $N-2 \ge 2$.
    - The jars are $(1, 1, N-2)$. Two jars are equal ($1=1$).
    - If $N-2$ is odd, we have three odd numbers. If $N-2$ is even, we have two odd numbers ($1, 1$). In both scenarios, the condition "at least one jar is odd" is satisfied.
    
*   **Case 2: $N$ is odd.**
    If we set $x = \frac{N-1}{2}$, the jars become $(\frac{N-1}{2}, \frac{N-1}{2}, 1)$.
    - Two jars are equal.
    - If $\frac{N-1}{2}$ is odd, all three are odd. If $\frac{N-1}{2}$ is even, the third jar ($1$) is odd. The condition is satisfied.

This construction covers all valid $N \ge 4$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform simple arithmetic operations to determine the distribution.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to distribute N chocolates into three jars (a, b, c) such that:
 * 1. a + b + c = N
 * 2. At least one jar has an odd number of chocolates.
 * 3. Exactly two jars have the same number of chocolates.
 * 4. a, b, c >= 1
 */

void solve() {
    long long N;
    cin >> N;

    if (N % 2 == 0) {
        // N is even, use 1, 1, N-2
        // Two jars are 1, which are equal.
        cout << 1 << " " << 1 << " " << (N - 2) << "\n";
    } else {
        // N is odd, use (N-1)/2, (N-1)/2, 1
        // Two jars are (N-1)/2, which are equal.
        long long x = (N - 1) / 2;
        cout << x << " " << x << " " << 1 << "\n";
    }
}

int main() {
    // Fast I/O
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