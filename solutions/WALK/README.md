# [Walk (WALK)](https://www.codechef.com/problems/WALK)

- **Difficulty Rating**: 1247
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $W$ of length $N$, where $W[i]$ represents the minimum velocity required to pass through the $i$-th segment. As you move from one segment to the next, your velocity decreases by 1. You need to find the minimum initial velocity $V$ at the first segment such that you can successfully pass through all segments without your velocity dropping below the required threshold $W[i]$ at any point $i$.

## Intuition & Mathematical Observation
Let $V$ be the initial velocity.
- At index $i$ (using 0-based indexing), the velocity will have decreased by $i$ units.
- Therefore, the velocity at index $i$ is $V - i$.
- The condition to pass the $i$-th segment is: $V - i \geq W[i]$.
- Rearranging this inequality, we get: $V \geq W[i] + i$.

To satisfy this condition for every segment $i$ from $0$ to $N-1$, $V$ must be greater than or equal to the maximum value of $(W[i] + i)$ across all segments. Thus, the minimum initial velocity required is:
$$V_{min} = \max_{0 \leq i < N} (W[i] + i)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to find the maximum value.
- **Space Complexity**: $O(1)$, as we only store the current maximum and the input value, without needing to store the entire array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let V be the initial velocity at the first segment.
 * At segment i (0-indexed), the velocity will be V - i.
 * The condition is: V - i >= W[i] for all i from 0 to N-1.
 * Rearranging this: V >= W[i] + i.
 * To satisfy this for all i, V must be at least the maximum value of (W[i] + i).
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long max_v = 0;
    for (int i = 0; i < n; ++i) {
        long long w;
        cin >> w;
        // Calculate the required velocity for the current segment
        long long required_v = w + i;
        // Update the global maximum required velocity
        if (required_v > max_v) {
            max_v = required_v;
        }
    }
    cout << max_v << "\n";
}

int main() {
    // Fast I/O for performance
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