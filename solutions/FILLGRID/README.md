# [The Grid Fill Problem (FILLGRID)](https://www.codechef.com/problems/FILLGRID)

- **Difficulty Rating**: 1393
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, construct an $N \times N$ grid consisting only of $1$s and $-1$s such that for every row and every column, the product of the sum of its elements and the product of its elements is strictly less than $0$.

## Intuition & Mathematical Observation
Let $S$ be the sum of elements in a row/column and $P$ be the product of elements in that row/column. We require $S \times P < 0$.

### Case 1: $N$ is even
If we fill the entire grid with $-1$:
- The sum of each row/column is $S = N \times (-1) = -N$.
- The product of each row/column is $P = (-1)^N = 1$ (since $N$ is even).
- $S \times P = -N \times 1 = -N$. Since $N \ge 2$, $-N < 0$.
This satisfies the condition for all rows and columns.

### Case 2: $N$ is odd
If we fill the grid with $-1$, $P = (-1)^N = -1$, making $S \times P = (-N) \times (-1) = N > 0$, which fails.
To fix this, we need to change the product to $1$ or the sum to a positive value. By placing $1$s along the main diagonal:
- Each row/column now contains $(N-1)$ elements of $-1$ and one element of $1$.
- The sum is $S = (N-1)(-1) + 1 = -N + 2$.
- The product is $P = (-1)^{N-1} \times 1 = 1$ (since $N-1$ is even).
- $S \times P = (-N + 2) \times 1 = -N + 2$.
- For $N \ge 3$, $-N + 2$ is always negative (e.g., for $N=3$, $S \times P = -1$).
This satisfies the condition for all rows and columns.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case, as we iterate through every cell of the $N \times N$ grid once to print the values.
- **Space Complexity**: $O(1)$, as we print the grid directly without storing it in an auxiliary data structure.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need (Sum * Product) < 0 for every row and every column.
 * 
 * Case 1: N is even.
 * Fill the entire grid with -1.
 * Sum = -N, Product = 1. Sum * Product = -N < 0.
 * 
 * Case 2: N is odd.
 * Fill the main diagonal with 1 and others with -1.
 * Sum = -N + 2, Product = 1. Sum * Product = -N + 2 < 0 (for N >= 3).
 */

void solve() {
    int N;
    cin >> N;
    if (N % 2 == 0) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << -1 << (j == N - 1 ? "" : " ");
            }
            cout << "\n";
        }
    } else {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (i == j) {
                    cout << 1 << (j == N - 1 ? "" : " ");
                } else {
                    cout << -1 << (j == N - 1 ? "" : " ");
                }
            }
            cout << "\n";
        }
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