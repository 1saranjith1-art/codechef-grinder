# [Ada School (ADASCOOL)](https://www.codechef.com/problems/ADASCOOL)

- **Difficulty Rating**: 1004
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times M$ grid of students. Each student must move to an adjacent cell (up, down, left, or right). We need to determine if it is possible for every student to move to a unique adjacent cell such that every cell is occupied by exactly one student after the move. This is equivalent to determining if the grid graph admits a **perfect matching**.

## Intuition & Mathematical Observation
A grid graph can be viewed as a bipartite graph (like a checkerboard). 
1. **The Parity Constraint**: In any graph, a perfect matching can only exist if the total number of vertices is even. If $N \times M$ is odd, there will be an odd number of cells, making it impossible to pair every student with a unique partner.
2. **Constructive Proof**: If $N \times M$ is even, at least one of $N$ or $M$ must be even.
   - If $N$ is even, we can divide the grid into $N/2$ pairs of rows. Within each row, we can pair adjacent cells $(i, j)$ and $(i, j+1)$ horizontally.
   - If $M$ is even, we can divide the grid into $M/2$ pairs of columns. Within each column, we can pair adjacent cells $(i, j)$ and $(i+1, j)$ vertically.
   
Thus, a perfect matching exists if and only if $N \times M$ is even, which simplifies to checking if `(N % 2 == 0 || M % 2 == 0)`.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant time $O(1)$ arithmetic check.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A perfect matching in a grid graph exists if and only if the total number 
 * of cells (N * M) is even. This is because a grid is a bipartite graph, 
 * and an odd number of vertices makes a perfect matching impossible.
 * If at least one dimension (N or M) is even, the total area is even, 
 * allowing us to tile the grid with 1x2 dominoes.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n, m;
        cin >> n >> m;

        // If either N or M is even, the total number of cells N*M is even.
        // A perfect matching exists if and only if the total number of cells is even.
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```