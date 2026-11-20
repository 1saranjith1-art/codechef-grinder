# [Plus 2 or Minus 1 (PLUS2MINUS1)](https://www.codechef.com/problems/PLUS2MINUS1)

- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a starting value of $X = 0$, we are allowed to perform at most $Y$ operations. Each operation consists of either adding 2 ($+2$) or subtracting 1 ($-1$). We need to determine the total number of distinct values that $X$ can take after performing any number of operations $k$, where $0 \le k \le Y$.

## Intuition & Mathematical Observation
Let $a$ be the number of $+2$ operations and $b$ be the number of $-1$ operations. If we perform exactly $k$ operations, then $a + b = k$. The final value $X$ is given by:
$X = 2a - b$
Substituting $b = k - a$:
$X = 2a - (k - a) = 3a - k$

Since $0 \le a \le k$, the possible values for a fixed $k$ are:
$\{-k, -k+3, -k+6, \dots, 2k\}$

By calculating the set of reachable values for small $Y$:
- **$Y=0$**: $\{0\}$ (Size: 1)
- **$Y=1$**: $\{0\} \cup \{-1, 2\} = \{-1, 0, 2\}$ (Size: 3)
- **$Y=2$**: $\{-1, 0, 2\} \cup \{-2, 1, 4\} = \{-2, -1, 0, 1, 2, 4\}$ (Size: 6)
- **$Y=3$**: $\{-2, -1, 0, 1, 2, 4\} \cup \{-3, 0, 3, 6\} = \{-3, -2, -1, 0, 1, 2, 3, 4, 6\}$ (Size: 9)

The pattern shows that for $Y > 0$, the number of distinct reachable values is exactly $3Y$. For $Y=0$, the only reachable value is $0$, resulting in a size of $1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses a simple conditional check and multiplication.
- **Space Complexity**: $O(1)$, as no additional data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a fixed number of moves k (0 <= k <= Y), the reachable values are 
 * of the form 3a - k. The union of these sets for all k from 0 to Y 
 * results in a total of 3*Y distinct values for Y > 0, and 1 for Y = 0.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long y;
        cin >> y;
        if (y == 0) {
            cout << 1 << "\n";
        } else {
            cout << 3 * y << "\n";
        }
    }
    return 0;
}
```