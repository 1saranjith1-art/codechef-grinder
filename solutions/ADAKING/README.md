# [Ada King (ADAKING)](https://www.codechef.com/problems/ADAKING)

- **Difficulty Rating**: 1378
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $K$, we need to construct an $8 \times 8$ chessboard configuration such that:
1. There is exactly one King on the board.
2. The King is placed at some position $(r, c)$.
3. There are some obstacles ('X') and empty cells ('.') on the board.
4. The King must be able to reach exactly $K$ cells (including its own position) by moving to any adjacent cell (horizontally, vertically, or diagonally).

## Intuition & Mathematical Observation
The key observation is that a King can move to any adjacent cell. If we place the King at $(0, 0)$ and fill the board with empty cells, the King can reach all of them. To restrict the number of reachable cells to exactly $K$, we simply need to fill the remaining $64 - K$ cells with obstacles ('X').

Since the King is at $(0, 0)$, we start by marking $(0, 0)$ as 'O'. Then, we iterate through the board row by row. For every cell we visit, if we have not yet reached $K$ cells, we mark the current cell as '.' and increment our count. Once the count reaches $K$, we mark all remaining cells as 'X'. This greedy approach ensures that all '.' cells are connected to the King at $(0, 0)$, satisfying the reachability condition.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the board size is fixed at $8 \times 8 = 64$ cells, the operations per test case are constant.
- **Space Complexity**: $O(1)$. We use a fixed $8 \times 8$ character array to store the board state.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to place a king at some position (0, 0) and place obstacles such that
 * the king can reach exactly K cells.
 * 
 * Strategy:
 * 1. Place the king at (0, 0).
 * 2. Fill the board row by row.
 * 3. Mark the first K cells as reachable ('.' or 'O') and the rest as 'X'.
 */

void solve() {
    int K;
    cin >> K;

    char board[8][8];
    int count = 0;

    // Fill the board with '.' and place the king at (0, 0)
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            if (i == 0 && j == 0) {
                board[i][j] = 'O';
                count++;
            } else {
                if (count < K) {
                    board[i][j] = '.';
                    count++;
                } else {
                    board[i][j] = 'X';
                }
            }
        }
    }

    // Print the board
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }
}

int main() {
    // Optimize I/O operations
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