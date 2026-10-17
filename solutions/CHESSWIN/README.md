# [Chess Win (CHESSWIN)](https://www.codechef.com/problems/CHESSWIN)

- **Difficulty Rating**: 236
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the current scores of two players, $A$ and $B$ (where $A < B$), determine the minimum number of additional matches $X$ one must win to ensure that the final score of the first player becomes strictly greater than the second player's score.

## Intuition & Mathematical Observation
We are given that the current score is $A : B$ and we know $A < B$. We want to find the smallest integer $X$ such that:
$$(A + X) > B$$

By rearranging the inequality to solve for $X$:
$$X > B - A$$

Since $X$ must be an integer, the smallest value that satisfies this inequality is:
$$X = (B - A) + 1$$

**Example Walkthrough:**
*   If $A = 0$ and $B = 1$: $X > 1 - 0 \implies X > 1$. The minimum integer is $2$.
*   If $A = 2$ and $B = 4$: $X > 4 - 2 \implies X > 2$. The minimum integer is $3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves a simple arithmetic calculation regardless of the input size.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Current score is A : B, where A < B.
 * We want to play X more matches such that we can end up with a score (A + X) : B
 * where (A + X) > B.
 * 
 * To minimize X, we assume we win all X remaining matches.
 * The condition is A + X > B.
 * Therefore, X > B - A.
 * Since X must be an integer, the minimum X is (B - A) + 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (cin >> A >> B) {
        // Calculate the minimum matches needed to surpass B
        int result = (B - A) + 1;
        cout << result << "\n";
    }

    return 0;
}
```