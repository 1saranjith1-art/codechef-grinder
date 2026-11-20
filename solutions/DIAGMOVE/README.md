# [Diagonal movement (DIAGMOVE)](https://www.codechef.com/problems/DIAGMOVE)

- **Difficulty Rating**: 1157
- **Solved in**: 1 attempt(s)

## Problem Summary
We start at the origin $(0, 0)$ on a 2D plane. In one move, we can move to any of the four diagonally adjacent cells: $(x+1, y+1)$, $(x+1, y-1)$, $(x-1, y+1)$, or $(x-1, y-1)$. Given a target coordinate $(x, y)$, we need to determine if it is possible to reach this point starting from $(0, 0)$ using any number of moves.

## Intuition & Mathematical Observation
To solve this, we analyze the parity of the coordinates after each move:
1. Every move changes both the $x$ and $y$ coordinates by exactly $1$ or $-1$.
2. Let the current position be $(x, y)$. After one move, the new position $(x', y')$ will have:
   - $x' = x \pm 1$
   - $y' = y \pm 1$
3. Consider the sum of the coordinates $S = x + y$. After one move, the new sum $S'$ is:
   - $S' = (x \pm 1) + (y \pm 1) = (x + y) \pm 1 \pm 1$
   - The possible values for $\pm 1 \pm 1$ are $\{2, 0, -2\}$.
4. Since we are adding an even number ($2, 0, \text{ or } -2$) to the sum $S$, the **parity** of the sum $(x + y)$ remains invariant.
5. Starting at $(0, 0)$, the initial sum is $0 + 0 = 0$ (which is even). Therefore, any reachable point $(x, y)$ must satisfy the condition that $(x + y)$ is even.

If $(x + y)$ is odd, it is impossible to reach the target, and if it is even, it is always possible.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a simple addition and a modulo operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The allowed moves are (i+1, j+1), (i+1, j-1), (i-1, j+1), (i-1, j-1).
 * Notice that in every move, both the x-coordinate and the y-coordinate change by 1 or -1.
 * This means the parity of the sum of coordinates (x + y) remains invariant.
 * 
 * Since we start at (0, 0), the sum is 0 (even). Every move adds an even number 
 * (either 2, 0, or -2) to the sum. Thus, the sum of coordinates must always be even.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // The sum of coordinates must be even for the point to be reachable.
        // (x + y) % 2 == 0 checks if the sum is even.
        if ((x + y) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
```