# [Gem Bundles (GEMBUND)](https://www.codechef.com/problems/GEMBUND)

- **Difficulty Rating**: 603
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $R$ red gems, $B$ blue gems, and $G$ green gems. You can sell gems individually for 3 coins each, or sell a bundle consisting of one of each color (1 Red, 1 Blue, 1 Green) for 10 coins. The goal is to maximize the total number of coins earned by choosing the optimal number of bundles to create.

## Intuition & Mathematical Observation
Let $k$ be the number of bundles created. Since each bundle requires one of each color, $k$ can range from $0$ to $\min(R, B, G)$.

The total profit formula is:
$$\text{Total Coins} = (k \times 10) + ((R - k) + (B - k) + (G - k)) \times 3$$

Expanding this:
$$\text{Total Coins} = 10k + 3(R + B + G - 3k)$$
$$\text{Total Coins} = 10k + 3(R + B + G) - 9k$$
$$\text{Total Coins} = 3(R + B + G) + k$$

Since $3(R + B + G)$ is a constant regardless of how many bundles we make, the total profit is maximized when $k$ is as large as possible. Therefore, we should create the maximum possible number of bundles, which is $k = \min(R, B, G)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations and a minimum comparison.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sold individually = 3 coins.
 * A bundle (1R, 1B, 1G) = 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 * Total coins = 10k + 3(R + B + G - 3k)
 * Total coins = 10k + 3(R + B + G) - 9k
 * Total coins = 3(R + B + G) + k
 * 
 * To maximize this, we need to maximize k.
 * Since k is the number of bundles, the maximum k is min(R, B, G).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long R, B, G;
        cin >> R >> B >> G;

        // Maximum number of bundles possible
        long long k = min({R, B, G});

        // Calculate total coins
        // Each bundle gives 10 coins, remaining gems give 3 coins each
        long long total_coins = (k * 10) + ((R - k) + (B - k) + (G - k)) * 3;

        cout << total_coins << "\n";
    }

    return 0;
}
```