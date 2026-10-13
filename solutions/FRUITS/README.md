# [Chef and Fruits (FRUITS)](https://www.codechef.com/problems/FRUITS)

- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ apples and $M$ oranges. He can perform at most $K$ operations. In each operation, he can increase the count of the fruit that currently has a smaller quantity by 1. The goal is to minimize the absolute difference between the number of apples and oranges ($|N - M|$) after performing at most $K$ operations.

## Intuition & Mathematical Observation
1. **Identify the Gap**: The initial difference between the two quantities is $|N - M|$. To minimize this difference, we should always add the fruit to the smaller pile.
2. **Greedy Approach**: 
   - Let $min\_val = \min(N, M)$ and $max\_val = \max(N, M)$.
   - The difference we need to bridge is $diff = max\_val - min\_val$.
   - If we have enough operations ($K \ge diff$), we can increase the smaller pile until it equals the larger pile, resulting in a difference of $0$.
   - If we do not have enough operations ($K < diff$), we use all $K$ operations to increase the smaller pile. The new difference will be $diff - K$.
3. **Simplification**: By ensuring $N \le M$ at the start (using `swap` if necessary), the logic simplifies to checking if $K \ge (M - N)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations and comparisons. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N apples and M oranges. We can perform at most K operations.
 * Each operation allows us to increase the count of the fruit that has a smaller quantity by 1.
 * Our goal is to minimize |N - M|.
 * 
 * Strategy:
 * 1. Identify which fruit is smaller.
 * 2. Use the K coins to increase the smaller count until it equals the larger count or we run out of coins.
 * 3. If we run out of coins before they are equal, the difference is (larger - (smaller + K)).
 * 4. If we reach equality, the difference is 0.
 */

void solve() {
    long long n, m, k;
    if (!(cin >> n >> m >> k)) return;

    // Ensure n is the smaller value to simplify logic
    if (n > m) {
        swap(n, m);
    }

    // Now n <= m. We want to increase n using k coins.
    // The difference is m - n.
    // We can increase n by at most k.
    
    long long diff = m - n;
    
    if (k >= diff) {
        // We can make them equal or even surpass, but since we want minimum difference,
        // we stop at equality (diff 0).
        cout << 0 << "\n";
    } else {
        // We use all k coins to reduce the difference.
        cout << (diff - k) << "\n";
    }
}

int main() {
    // Fast I/O
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