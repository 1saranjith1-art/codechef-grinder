# [Even Matrix (EVENM)](https://www.codechef.com/problems/EVENM)

- **Difficulty Rating**: 1376
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct an $N \times N$ matrix containing all integers from $1$ to $N^2$ exactly once. The matrix must satisfy the condition that for any square submatrix, the sum of its two main diagonals is even.

## Intuition & Mathematical Observation
The condition that the sum of the two main diagonals of any square submatrix is even is satisfied if the parity of the elements follows a specific pattern. Specifically, if we ensure that the parity of an element at $(i, j)$ is determined by $(i + j) \pmod 2$, the condition holds.

To achieve this using numbers $1$ to $N^2$:
1. We fill the matrix row by row.
2. For **odd-indexed rows** (0, 2, 4...), we fill the numbers in increasing order from **left to right**.
3. For **even-indexed rows** (1, 3, 5...), we fill the numbers in increasing order from **right to left**.

By reversing the filling direction for every other row, we ensure that the parity of the numbers alternates correctly across both rows and columns. This creates a "snake-like" filling pattern that naturally satisfies the parity requirements for any square submatrix.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, as we iterate through each cell of the $N \times N$ matrix exactly once to assign values and print them.
- **Space Complexity**: $O(N^2)$ to store the matrix before printing. This can be optimized to $O(1)$ auxiliary space if we print the values directly without storing them in a 2D vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To ensure the parity condition, we fill the matrix such that the parity of 
 * M[i][j] follows a checkerboard pattern. By filling odd rows left-to-right 
 * and even rows right-to-left, we guarantee that adjacent cells have 
 * alternating parities, satisfying the diagonal sum condition.
 */

void solve() {
    int N;
    cin >> N;
    
    int current = 1;
    vector<vector<int>> matrix(N, vector<int>(N));
    
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            // Fill left to right for even-indexed rows (0, 2, ...)
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = current++;
            }
        } else {
            // Fill right to left for odd-indexed rows (1, 3, ...)
            for (int j = N - 1; j >= 0; --j) {
                matrix[i][j] = current++;
            }
        }
    }
    
    // Output the resulting matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```