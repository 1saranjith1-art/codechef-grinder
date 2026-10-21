# [Bakery Problem (BAKERY7)](https://www.codechef.com/problems/BAKERY7)

- **Difficulty Rating**: 284
- **Solved in**: 3 attempt(s)

## Problem Summary
The problem asks us to determine the minimum cost to purchase $N$ items from a bakery. We are given two pricing options:
1. **Standard Price**: Each item costs 100 units. Total cost = $N \times 100$.
2. **Bribe Price**: We pay a fixed bribe of $K$ units, and each item then costs 60 units. Total cost = $K + (N \times 60)$.

We need to output the minimum of these two calculated costs.

## Intuition & Mathematical Observation
The problem is a straightforward comparison between two linear functions of $N$:
* Let $f(N) = 100N$
* Let $g(N) = 60N + K$

Since we want to minimize the expenditure, we simply calculate both values and use the `min()` function to select the smaller one. Given the constraints ($N \le 10, K \le 1000$), the result will easily fit within a standard 32-bit integer, though `long long` is used here for good practice.

## Complexity Analysis
- **Time Complexity**: $O(1)$. The solution performs a constant number of arithmetic operations regardless of the input size.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and the calculated costs, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Option 1 (No Bribe): Cost = N * 100
 * Option 2 (Bribe): Cost = K + (N * 60)
 * We need to find the minimum of these two values.
 * Constraints: N <= 10, K <= 1000. 
 * The values fit well within standard integer types, but long long is safe.
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    if (cin >> N >> K) {
        long long cost_no_bribe = N * 100;
        long long cost_with_bribe = K + (N * 60);

        cout << min(cost_no_bribe, cost_with_bribe) << endl;
    }

    return 0;
}
```