# [Infernos (INFERNO)](https://www.codechef.com/problems/INFERNO)

- **Difficulty Rating**: 1162
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ enemies, each with a specific health value $H_i$. You have a weapon with two firing modes:
1. **Single-Target Mode**: Deals $X$ damage to one specific enemy per second.
2. **Multi-Target Mode**: Deals $1$ damage to all living enemies per second.

The goal is to eliminate all enemies in the minimum amount of time possible by choosing the optimal strategy (or a combination, though the problem implies comparing the two distinct strategies).

## Intuition & Mathematical Observation
To solve this, we calculate the time required for each mode independently:

1. **Single-Target Mode**: 
   For each enemy with health $H_i$, the time taken to defeat them is $\lceil H_i / X \rceil$. In integer arithmetic, this is calculated as `(H_i + X - 1) / X`. The total time is the sum of these values for all $N$ enemies.

2. **Multi-Target Mode**: 
   Since this mode hits every enemy simultaneously, the time taken is determined by the enemy with the highest health. If the maximum health is $H_{max}$, it will take exactly $H_{max}$ seconds to reduce all enemies to zero health.

The final answer is simply the minimum of these two calculated values:
$$\text{Result} = \min\left(\sum_{i=1}^{N} \lceil H_i / X \rceil, \max_{i=1}^{N} H_i\right)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of health values exactly once to compute the sum and the maximum.
- **Space Complexity**: $O(N)$ to store the health values (or $O(1)$ if we process the input values on the fly without storing them in a vector).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Single-Target Mode: Total time = sum(ceil(H_i / X))
 * 2. Multi-Target Mode: Total time = max(H_i)
 * We return the minimum of these two values.
 */

void solve() {
    int N, X;
    cin >> N >> X;
    vector<int> H(N);
    int max_h = 0;
    long long single_target_time = 0;

    for (int i = 0; i < N; ++i) {
        cin >> H[i];
        // Update max health for Multi-Target calculation
        if (H[i] > max_h) {
            max_h = H[i];
        }
        // Calculate time for Single-Target mode
        // ceil(H_i / X) is equivalent to (H_i + X - 1) / X using integer division
        single_target_time += (H[i] + X - 1) / X;
    }

    // The answer is the minimum of the two strategies
    long long ans = min((long long)max_h, single_target_time);
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```