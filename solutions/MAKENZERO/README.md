# [Make N Zero (MAKENZERO)](https://www.codechef.com/problems/MAKENZERO)

- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine if a given integer $N$ can be represented as a linear combination of 3 and 4, specifically in the form $3x + 4y = N$, where $x$ and $y$ are non-negative integers ($x, y \ge 0$).

## Intuition & Mathematical Observation
This problem is a classic application of the **Frobenius Coin Problem** (also known as the Chicken McNugget Theorem). For two coprime integers $a$ and $b$, the largest integer that cannot be expressed in the form $ax + by$ is given by the formula $ab - a - b$.

1.  **Identify the constants**: Here, $a = 3$ and $b = 4$.
2.  **Calculate the Frobenius number**: The largest number that cannot be formed is $(3 \times 4) - 3 - 4 = 12 - 7 = 5$.
3.  **Check small values**:
    *   $N=1$: Cannot be formed.
    *   $N=2$: Cannot be formed.
    *   $N=3$: $3(1) + 4(0) = 3$ (YES)
    *   $N=4$: $3(0) + 4(1) = 4$ (YES)
    *   $N=5$: Cannot be formed.
    *   $N=6$: $3(2) + 4(0) = 6$ (YES)
    *   $N=7$: $3(1) + 4(1) = 7$ (YES)
    *   $N=8$: $3(0) + 4(2) = 8$ (YES)

Since all integers greater than 5 can be formed by adding combinations of 3 and 4, the only non-negative integers that cannot be represented are **1, 2, and 5**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3*x + 4*y = N, where x, y >= 0.
 * This is a variation of the Frobenius Coin Problem.
 * For a=3 and b=4, the largest number that cannot be formed is (3*4 - 3 - 4) = 5.
 * The numbers that cannot be formed are 1, 2, and 5.
 */

void solve() {
    int n;
    cin >> n;
    
    // Based on the analysis, N cannot be formed if N is 1, 2, or 5.
    if (n == 1 || n == 2 || n == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
    }
}

int main() {
    // Fast I/O setup
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