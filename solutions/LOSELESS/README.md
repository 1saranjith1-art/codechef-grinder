# [Lose Less (LOSELESS)](https://www.codechef.com/problems/LOSELESS)

- **Difficulty Rating**: 900
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $M$ total matches played and $N$ total points earned. In each match, a win earns 3 points, a tie earns 1 point, and a loss earns 0 points. Your goal is to determine the minimum number of losses ($l$) possible given the constraints $M$ and $N$.

## Intuition & Mathematical Observation
Let $w$ be the number of wins, $t$ be the number of ties, and $l$ be the number of losses. We have the following system of equations:
1. $w + t + l = M$
2. $3w + t = N$

We want to minimize $l$. From the equations, we can express $l$ as:
$l = M - (w + t)$

Since the constraints on $M$ are very small ($M \le 20$), we do not need to derive a complex closed-form formula. Instead, we can iterate through all possible values of $w$ (from $0$ to $M$). For each $w$:
1. Calculate the required ties: $t = N - 3w$.
2. Check if $t \ge 0$.
3. Calculate the resulting losses: $l = M - w - t$.
4. Check if $l \ge 0$.
5. If both conditions are met, update the minimum $l$ found so far.

This brute-force approach is highly efficient given the small input size and guarantees correctness by checking every valid configuration.

## Complexity Analysis
- **Time Complexity**: $O(M)$ per test case. Since $M \le 20$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through all possible numbers of wins (w) from 0 to M.
 * For each w, we determine if a valid number of ties (t) and losses (l) exist.
 * We track the minimum l found across all valid scenarios.
 */

void solve() {
    int M, N;
    cin >> M >> N;

    int min_l = M; // Initialize with the maximum possible losses
    
    // Iterate through all possible number of wins w
    for (int w = 0; w <= M; ++w) {
        int t = N - 3 * w;
        // Check if the number of ties is non-negative
        if (t >= 0) {
            int l = M - w - t;
            // Check if the number of losses is non-negative
            if (l >= 0) {
                if (l < min_l) {
                    min_l = l;
                }
            }
        }
    }
    cout << min_l << "\n";
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