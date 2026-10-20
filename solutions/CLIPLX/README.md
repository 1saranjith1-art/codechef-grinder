# [IPL and RCB (CLIPLX)](https://www.codechef.com/problems/CLIPLX)

- **Difficulty Rating**: 1167
- **Solved in**: 1 attempt(s)

## Problem Summary
RCB needs to secure at least $X$ points from $Y$ matches. A win grants 2 points, a tie grants 1 point, and a loss grants 0 points. The goal is to find the **minimum number of wins** required to achieve at least $X$ points.

## Intuition & Mathematical Observation
Let $w$ be the number of wins, $t$ be the number of ties, and $l$ be the number of losses. We are given:
1. $w + t + l = Y$
2. $2w + t = X$ (since losses contribute 0 points)

We want to minimize $w$. From the second equation, we have $t = X - 2w$. 
Since the number of ties $t$ cannot be negative, $2w \le X$. Furthermore, since the total number of matches used for wins and ties cannot exceed $Y$ ($w + t \le Y$), we substitute $t$:
$$w + (X - 2w) \le Y$$
$$X - w \le Y$$
$$w \ge X - Y$$

Since $w$ must also be at least 0, the minimum number of wins required is $\max(0, X - Y)$.

**Logic:**
- If $X \le Y$, we can simply tie all necessary matches to reach $X$ points, requiring **0 wins**.
- If $X > Y$, we have a deficit of $X - Y$ points. Since a win provides 1 more point than a tie, we must convert $X - Y$ ties into wins to bridge the gap.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic comparison. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB needs X points from Y matches.
 * Win = 2 points, Tie = 1 point, Loss = 0 points.
 * We want to minimize wins (w).
 * If X <= Y, we can achieve X points using only ties (0 wins).
 * If X > Y, we need (X - Y) wins to make up the point deficit.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // If X <= Y, 0 wins are sufficient.
        // Otherwise, we need (X - Y) wins.
        if (X <= Y) {
            cout << 0 << "\n";
        } else {
            cout << (X - Y) << "\n";
        }
    }

    return 0;
}
```