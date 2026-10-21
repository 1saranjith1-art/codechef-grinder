# [Coloured Balloons (BALLOONS)](https://www.codechef.com/problems/BALLOONS)

- **Difficulty Rating**: 584
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ different types of balloons, indexed from $1$ to $N$. For each balloon type $i$, we are given the quantity $A_i$ available. The cost of a single balloon of type $i$ is equal to its index $i$. The goal is to calculate the total cost of all balloons, which is the sum of the products of the quantity and the cost for each type: $\sum_{i=1}^{N} (A_i \times i)$.

## Intuition & Mathematical Observation
The problem is a straightforward application of summation. Since the cost of a balloon of type $i$ is exactly $i$, we simply need to iterate through the input array $A$ where the $i$-th element (1-indexed) represents the count of balloons with cost $i$.

- **Mathematical Formula**: $\text{Total Cost} = \sum_{i=1}^{N} (A_i \times i)$
- **Data Types**: Given the constraints $N \le 100$ and $A_i \le 100$, the maximum possible cost is $100 \times \sum_{i=1}^{100} i = 100 \times 5050 = 505,000$. This fits comfortably within a standard 32-bit `int`, but `long long` is used to ensure robustness against potential overflow in similar problems.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the $N$ balloon types exactly once. With $T$ test cases, the total time complexity is $O(T \times N)$.
- **Space Complexity**: $O(1)$, as we only store the running total and the current balloon count, without needing to store the entire array in memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N colours of balloons.
 * The i-th colour balloon costs i rupees.
 * We are given A_i, the number of balloons of colour i.
 * The total cost is the sum of (A_i * i) for all i from 1 to N.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    long long total_cost = 0;
    for (int i = 1; i <= N; ++i) {
        long long A_i;
        cin >> A_i;
        // The i-th colour has cost i
        total_cost += (A_i * i);
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O setup for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```