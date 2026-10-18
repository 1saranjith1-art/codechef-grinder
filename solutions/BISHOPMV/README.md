# [Bishop Moves (BISHOPMV)](https://www.codechef.com/problems/BISHOPMV)

- **Difficulty Rating**: 914
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the coordinates of two squares on an $8 \times 8$ chessboard $(x_1, y_1)$ and $(x_2, y_2)$, determine the minimum number of moves a bishop requires to travel from the first square to the second. If it is impossible, output -1.

## Intuition & Mathematical Observation
A bishop moves diagonally. We can categorize the possible outcomes based on the properties of the chessboard:

1.  **One Move**: Two squares are on the same diagonal if the absolute difference of their coordinates is equal: $|x_1 - x_2| = |y_1 - y_2|$. If this condition is met, the bishop can reach the target in exactly **1 move**.
2.  **Two Moves**: A bishop is restricted to squares of the same color. The color of a square $(x, y)$ can be determined by the parity of the sum of its coordinates $(x + y) \pmod 2$. If the starting and ending squares have the same parity but are not on the same diagonal, the bishop can always reach the target in exactly **2 moves** (by moving to the intersection of the two diagonals passing through the start and end points).
3.  **Impossible**: If the starting and ending squares have different parities $(x_1 + y_1) \pmod 2 \neq (x_2 + y_2) \pmod 2$, the bishop can never reach the target square. In this case, the answer is **-1**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the coordinates.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * 1. x1 + y1 == x2 + y2 (anti-diagonal)
 * 2. x1 - y1 == x2 - y2 (main diagonal)
 * 
 * If they are on the same diagonal, the bishop reaches in 1 move.
 * If they are not on the same diagonal, we check if they are reachable.
 * A bishop can only reach squares of the same color as the starting square.
 * The color of a square (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are the same color and not on the same diagonal, it takes exactly 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if same diagonal
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } 
    // Check if same color
    else if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << 2 << "\n";
    } 
    // Different colors, impossible for a bishop
    else {
        cout << -1 << "\n";
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