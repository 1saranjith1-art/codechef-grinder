# [Difference Matrix (MATDIF)](https://www.codechef.com/problems/MATDIF)

- **Difficulty Rating**: 1377
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, construct an $N \times N$ matrix containing all integers from $1$ to $N^2$ exactly once such that no two adjacent cells (horizontally, vertically, or diagonally) have an absolute difference of exactly $1$.

## Intuition & Mathematical Observation
The core constraint is to ensure that $|A_{i,j} - A_{x,y}| \neq 1$ for any adjacent cells. 

A highly effective strategy is to separate the numbers into two groups: **all odd numbers** and **all even numbers**.
1. **Odd Numbers**: Any two odd numbers have a difference of at least $2$. Therefore, placing odd numbers next to each other will never violate the condition.
2. **Even Numbers**: Similarly, any two even numbers have a difference of at least $2$.
3. **The Transition**: By placing all odd numbers first in the matrix followed by all even numbers, we only need to worry about the boundary where the last odd number meets the first even number. Since the smallest even number is $2$ and the largest odd number is at least $N^2$ (or $N^2-1$), the difference between them is significantly greater than $1$ for all $N \ge 2$.

By filling the matrix row-by-row with the sequence $[1, 3, 5, \dots, 2, 4, 6, \dots]$, we guarantee that no two adjacent cells have a difference of $1$.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$, as we iterate through the matrix cells once to fill them and once to print them.
- **Space Complexity**: $O(N^2)$ to store the matrix before printing.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * Fill the N x N matrix by placing all odd numbers from 1 to N^2 first,
 * followed by all even numbers from 2 to N^2. This ensures that adjacent
 * cells are either both odd or both even, making their difference at least 2.
 */

void solve() {
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N));
    
    vector<int> sequence;
    // Add all odd numbers
    for (int i = 1; i <= N * N; i += 2) {
        sequence.push_back(i);
    }
    // Add all even numbers
    for (int i = 2; i <= N * N; i += 2) {
        sequence.push_back(i);
    }
    
    // Fill the matrix row by row
    int idx = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            matrix[i][j] = sequence[idx++];
        }
    }
    
    // Print the matrix
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << matrix[i][j] << (j == N - 1 ? "" : " ");
        }
        cout << "\n";
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