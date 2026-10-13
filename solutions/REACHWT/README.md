# [Reach Weight (REACHWT)](https://www.codechef.com/problems/REACHWT)

- **Difficulty Rating**: 530
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a target weight $N$ (in kg). We have two types of weights available:
1. A 1kg weight that costs 20 units.
2. A 2kg weight that costs 30 units.

The goal is to find the minimum cost to reach exactly $N$ kg using any combination of these weights.

## Intuition & Mathematical Observation
Let $x$ be the number of 1kg weights and $y$ be the number of 2kg weights. We must satisfy the equation:
$$x + 2y = N$$
The total cost function is:
$$\text{Cost} = 20x + 30y$$

Substituting $x = N - 2y$ into the cost function:
$$\text{Cost} = 20(N - 2y) + 30y$$
$$\text{Cost} = 20N - 40y + 30y$$
$$\text{Cost} = 20N - 10y$$

To minimize the total cost, we need to maximize $y$ (the number of 2kg weights), because each 2kg weight effectively reduces the cost by 10 units compared to using two 1kg weights. Since $x \ge 0$, the maximum value $y$ can take is $\lfloor N/2 \rfloor$.

By maximizing $y$, we ensure the minimum possible cost is achieved.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to reach exactly N kg using 1kg weights (cost 20) and 2kg weights (cost 30).
 * Let x be the number of 1kg weights and y be the number of 2kg weights.
 * We want to minimize 20x + 30y subject to x + 2y = N, where x, y >= 0.
 * 
 * From x + 2y = N, we get x = N - 2y.
 * Since x >= 0, N - 2y >= 0 => 2y <= N => y <= N/2.
 * Cost = 20(N - 2y) + 30y = 20N - 40y + 30y = 20N - 10y.
 * To minimize cost, we need to maximize y.
 * The maximum possible value for y is floor(N/2).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Maximize y = n / 2 to minimize cost
        long long y = n / 2;
        long long x = n - 2 * y;
        
        long long min_cost = (x * 20) + (y * 30);
        cout << min_cost << "\n";
    }
    
    return 0;
}
```