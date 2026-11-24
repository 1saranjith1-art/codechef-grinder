# [Journey of the Knight (KNIGHT2)](https://www.codechef.com/problems/KNIGHT2)

- **Difficulty Rating**: 1144
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks whether a knight starting at position $(X_1, Y_1)$ on an $8 \times 8$ chessboard can reach a target position $(X_2, Y_2)$ in **exactly** 100 moves.

## Intuition & Mathematical Observation
1. **Parity Constraint**: A knight's move always changes the color of the square it occupies. Therefore, after an even number of moves (like 100), the knight must land on a square of the same color as its starting square.
2. **Reachability**: On an $8 \times 8$ board, a knight can reach any square from any other square. The minimum number of moves $d$ required to reach $(X_2, Y_2)$ from $(X_1, Y_1)$ can be found using Breadth-First Search (BFS).
3. **The "Exactly 100" Condition**: 
   - If the minimum distance $d$ is greater than 100, it is impossible to reach the target in 100 moves.
   - If $d \le 100$, we can reach the target in exactly 100 moves if and only if the remaining moves $(100 - d)$ are even. This is because a knight can "waste" two moves by jumping to an adjacent square and back to the current square, effectively keeping the position the same while increasing the move count by 2.
   - Thus, the condition simplifies to: `d <= 100` AND `(100 - d) % 2 == 0`.

## Complexity Analysis
- **Time Complexity**: 
    - **Precomputation**: We perform a BFS starting from each of the 64 squares. Each BFS visits 64 squares and checks 8 neighbors, resulting in $O(64 \times 64 \times 8) \approx O(1)$, which is constant given the fixed board size.
    - **Query**: Each test case is answered in $O(1)$ time by looking up the precomputed distance.
- **Space Complexity**: $O(N^4)$ where $N=8$, to store the distance matrix `dist[8][8][8][8]`. This is $8^4 = 4096$ integers, which is well within memory limits.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The knight's move changes the color of the square it is on.
 * After 100 moves (an even number), the knight must be on a square of the 
 * same color as the starting square.
 * 
 * On an 8x8 board, the knight can reach any square. The only constraint 
 * is the parity of the number of moves. Since 100 is even, the knight 
 * can reach (X2, Y2) from (X1, Y1) in exactly 100 moves if and only if 
 * the minimum number of moves 'd' required to reach (X2, Y2) is even 
 * and d <= 100.
 */

int dist[9][9][9][9];

void precompute() {
    // Initialize distances to -1
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            for (int k = 1; k <= 8; ++k) {
                for (int l = 1; l <= 8; ++l) {
                    dist[i][j][k][l] = -1;
                }
            }
        }
    }

    int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
    int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

    // Run BFS from every square to find shortest path to all other squares
    for (int x1 = 1; x1 <= 8; ++x1) {
        for (int y1 = 1; y1 <= 8; ++y1) {
            queue<pair<int, int>> q;
            q.push({x1, y1});
            dist[x1][y1][x1][y1] = 0;
            while (!q.empty()) {
                pair<int, int> curr = q.front();
                q.pop();
                for (int i = 0; i < 8; ++i) {
                    int nx = curr.first + dx[i];
                    int ny = curr.second + dy[i];
                    if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && dist[x1][y1][nx][ny] == -1) {
                        dist[x1][y1][nx][ny] = dist[x1][y1][curr.first][curr.second] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int t;
    cin >> t;
    while (t--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int d = dist[x1][y1][x2][y2];
        
        // Check if target is reachable within 100 moves and parity matches
        if (d <= 100 && (100 - d) % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}
```