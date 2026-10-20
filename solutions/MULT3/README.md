# [Multiple of 3 (MULT3)](https://www.codechef.com/problems/MULT3)

- **Difficulty Rating**: 297
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, the task is to find the nearest multiple of 3. If there are two multiples of 3 equidistant from $N$, we choose the smaller one.

## Intuition & Mathematical Observation
To find the nearest multiple of 3, we examine the remainder of $N$ when divided by 3 ($N \pmod 3$):

1.  **If $N \pmod 3 = 0$**: $N$ is already a multiple of 3. The distance is 0, so the answer is $N$.
2.  **If $N \pmod 3 = 1$**: The two closest multiples of 3 are $(N-1)$ and $(N+2)$. The distance to $(N-1)$ is 1, while the distance to $(N+2)$ is 2. Since we want the closest (and smaller in case of ties, though not applicable here), the answer is $(N-1)$.
3.  **If $N \pmod 3 = 2$**: The two closest multiples of 3 are $(N-2)$ and $(N+1)$. The distance to $(N-2)$ is 2, while the distance to $(N+1)$ is 1. Thus, the answer is $(N+1)$.

This logic covers all positive integers $N$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the nearest multiple of 3 for a given integer N.
 * 
 * Logic:
 * If N % 3 == 0, the nearest multiple is N itself.
 * If N % 3 == 1, the multiples are (N-1) and (N+2). 
 *    Distance to (N-1) is 1, distance to (N+2) is 2. So (N-1) is closer.
 * If N % 3 == 2, the multiples are (N-2) and (N+1).
 *    Distance to (N-2) is 2, distance to (N+1) is 1. So (N+1) is closer.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;

    long long remainder = n % 3;

    if (remainder == 0) {
        cout << n << "\n";
    } else if (remainder == 1) {
        cout << (n - 1) << "\n";
    } else {
        cout << (n + 1) << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}
```