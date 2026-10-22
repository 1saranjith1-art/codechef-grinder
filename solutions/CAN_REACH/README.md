# [Can_Reach (CAN_REACH)](https://www.codechef.com/problems/CAN_REACH)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
You start at the origin $(0, 0)$ on a 2D plane. In one move, you can jump exactly $K$ units in any of the four cardinal directions (up, down, left, or right). Given a target coordinate $(x, y)$, determine if it is possible to reach this point starting from $(0, 0)$ using any number of moves.

## Intuition & Mathematical Observation
Each move changes either the $x$-coordinate or the $y$-coordinate by exactly $K$ units. 
- If you move horizontally, the $x$-coordinate changes by $+K$ or $-K$, while the $y$-coordinate remains constant.
- If you move vertically, the $y$-coordinate changes by $+K$ or $-K$, while the $x$-coordinate remains constant.

After any number of moves, the final $x$-coordinate will be of the form $n_1 \cdot K$ and the final $y$-coordinate will be of the form $n_2 \cdot K$, where $n_1$ and $n_2$ are integers representing the net number of steps taken in the $x$ and $y$ directions, respectively.

Therefore, a point $(x, y)$ is reachable if and only if:
1. $x$ is a multiple of $K$ (i.e., $x \pmod K == 0$)
2. $y$ is a multiple of $K$ (i.e., $y \pmod K == 0$)

Since the problem guarantees $K \ge 1$, we do not need to worry about division by zero.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the check.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The student starts at (0, 0) and moves by exactly K in either the x or y direction.
 * This means after n moves, the x-coordinate will be a multiple of K (x = a * K)
 * and the y-coordinate will be a multiple of K (y = b * K), where a and b are 
 * integers representing the net number of steps taken in the x and y directions.
 * 
 * Therefore, for the student to reach (x, y), both x and y must be divisible by K.
 * Since the moves can be positive or negative, we check if x % K == 0 and y % K == 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x, y, k;
        cin >> x >> y >> k;

        // Check if both coordinates are divisible by K.
        // The problem states K >= 1, so division by zero is not an issue.
        if (x % k == 0 && y % k == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```