# [Gotta Catch Em All (GCEA)](https://www.codechef.com/problems/GCEA)

- **Difficulty Rating**: 898
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ Pekómon, each with a specific difficulty level $A_i$. To catch a Pekómon, you have two options:
1. **Normal Pekóballs**: Each ball costs $X$, and you need $A_i$ balls to catch the $i$-th Pekómon. Total cost: $A_i \times X$.
2. **Master Pekóball**: A single Master Pekóball costs $Y$ and catches any Pekómon regardless of its difficulty. Total cost: $Y$.

The goal is to calculate the minimum total cost required to catch all $N$ Pekómon.

## Intuition & Mathematical Observation
For each individual Pekómon $i$, the decision is independent of the others. To minimize the total cost, we must minimize the cost for each Pekómon separately.

For any given Pekómon $i$:
- The cost using Normal Pekóballs is $A_i \times X$.
- The cost using a Master Pekóball is $Y$.

Therefore, the minimum cost to catch the $i$-th Pekómon is simply $\min(A_i \times X, Y)$. By summing these minimum values for all $i$ from $1$ to $N$, we obtain the global minimum cost.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of Pekómon. We iterate through the list of difficulties exactly once.
- **Space Complexity**: $O(1)$ (excluding the input storage), as we only need to maintain a running sum of the costs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For each Pekómon with difficulty A_i, we have two choices:
 * 1. Use Normal Pekóballs: Cost = A_i * X
 * 2. Use a Master Pekóball: Cost = Y
 * 
 * To minimize the total cost, for each Pekómon, we should choose the minimum of these two options:
 * min_cost_for_i = min(A_i * X, Y)
 * 
 * The total minimum cost is the sum of min_cost_for_i for all i from 1 to N.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int A_i;
        cin >> A_i;
        
        // Calculate cost for current Pekómon and add to total
        long long normal_cost = (long long)A_i * X;
        total_cost += min(normal_cost, Y);
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup
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