# [Download file (DWNLD)](https://www.codechef.com/problems/DWNLD)

- **Difficulty Rating**: 1147
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ intervals of time, where each interval $i$ has a duration $T_i$ and a data rate $D_i$ (cost per minute). You are provided with $K$ minutes of free data usage. The goal is to calculate the total cost incurred for the data downloaded after the first $K$ minutes are exhausted.

## Intuition & Mathematical Observation
The problem can be solved by processing the intervals sequentially. Since the first $K$ minutes are free, we need to "consume" these $K$ minutes across the given intervals:

1. **If $K \ge T_i$**: The entire duration of the current interval is covered by the free minutes. We subtract $T_i$ from $K$ and move to the next interval without adding any cost.
2. **If $K < T_i$**: The first $K$ minutes of this interval are free, and the remaining $(T_i - K)$ minutes must be paid for at the rate of $D_i$. After this calculation, $K$ becomes $0$, and all subsequent intervals will be fully charged at their respective rates.

By maintaining a running total of the cost and updating $K$ as we iterate, we can determine the final cost efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of intervals. We iterate through the list of intervals exactly once.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current interval data and the running total cost.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N intervals, each with duration Ti and data rate Di.
 * The first K minutes are free.
 * We need to calculate the total cost for the remaining minutes.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int T, D;
        cin >> T >> D;
        
        if (K >= T) {
            // Entire interval is free
            K -= T;
        } else {
            // Part of the interval is free, part is charged
            // The charged duration is (T - K)
            int charged_minutes = T - K;
            total_cost += (long long)charged_minutes * D;
            // After this, all remaining minutes are charged
            K = 0;
        }
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}
```