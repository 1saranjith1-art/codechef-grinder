# [Cooler (COOLER7)](https://www.codechef.com/problems/COOLER7)

- **Difficulty Rating**: 555
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to calculate the total time required to cool a room from an initial temperature $N$ to a target temperature $M$. The air conditioner takes $T$ minutes to reduce the temperature from $T$ degrees to $T-1$ degrees. We need to find the sum of time intervals required for each degree drop from $N$ down to $M$.

## Intuition & Mathematical Observation
To cool the room from $N$ to $M$, the air conditioner must perform the following steps:
1. Cool from $N$ to $N-1$ (takes $N$ minutes).
2. Cool from $N-1$ to $N-2$ (takes $N-1$ minutes).
3. ...
4. Cool from $M+1$ to $M$ (takes $M+1$ minutes).

The total time is the sum of the arithmetic series:
$$\text{Total Time} = N + (N-1) + (N-2) + \dots + (M+1)$$

Using the formula for the sum of the first $k$ integers, $S_k = \frac{k(k+1)}{2}$, we can express the sum of the range $[M+1, N]$ as:
$$\text{Total Time} = \sum_{i=1}^{N} i - \sum_{i=1}^{M} i$$
$$\text{Total Time} = \frac{N(N+1)}{2} - \frac{M(M+1)}{2}$$

This approach allows us to calculate the result in $O(1)$ time per test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The air conditioner takes X minutes to drop from X degrees to X-1 degrees.
 * To go from N to M, we need to drop the temperature (N - M) times.
 * 
 * Total time = (N) + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum.
 * The sum of integers from 1 to N is N*(N+1)/2.
 * The sum of integers from 1 to M is M*(M+1)/2.
 * The required sum is (Sum from 1 to N) - (Sum from 1 to M).
 * Total time = (N * (N + 1) / 2) - (M * (M + 1) / 2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Calculate sum from M+1 to N using the derived formula
        long long total_time = (n * (n + 1) / 2) - (m * (m + 1) / 2);
        
        cout << total_time << "\n";
    }

    return 0;
}
```