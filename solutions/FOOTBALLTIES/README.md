# [Football Ties (FOOTBALLTIES)](https://www.codechef.com/problems/FOOTBALLTIES)

- **Difficulty Rating**: 788
- **Solved in**: 1 attempt(s)

## Problem Summary
In a football league, a win awards 3 points, a loss awards 0 points, and a draw awards 1 point to each team. Given the final scores $X$ and $Y$ of two teams, determine the minimum number of draws that could have occurred between them.

## Intuition & Mathematical Observation
Let $w_A$ and $w_B$ be the number of wins for team A and team B, respectively, and $d$ be the number of draws. The total points for each team are:
- $X = 3 \cdot w_A + d$
- $Y = 3 \cdot w_B + d$

We observe that any points earned from wins are multiples of 3. Therefore, the points that are *not* multiples of 3 must come from the draws. 

Taking the equation $X = 3 \cdot w_A + d$ modulo 3:
- $X \equiv d \pmod 3$

Since each draw awards exactly 1 point to each team, the number of draws $d$ must be the same for both teams. Because we want to minimize $d$ and we know $d \equiv X \pmod 3$, the smallest non-negative value for $d$ is simply $X \pmod 3$. 

*(Note: Since $X \equiv d \pmod 3$ and $Y \equiv d \pmod 3$, it follows that $X \equiv Y \pmod 3$ must hold true for any valid scoreline, which is guaranteed by the problem constraints.)*

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Scores:
 * X = 3 * wA + d
 * Y = 3 * wB + d
 * 
 * Since 3 * wA is always divisible by 3, the remainder of X divided by 3
 * must be equal to the number of draws (d).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The points from wins are always multiples of 3.
        // Any points not divisible by 3 must come from draws.
        // The minimum number of draws is simply X % 3.
        cout << (x % 3) << "\n";
    }

    return 0;
}
```