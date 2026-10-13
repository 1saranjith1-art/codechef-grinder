# [Selling Insurance (AGENTCHEF)](https://www.codechef.com/problems/AGENTCHEF)

- **Difficulty Rating**: 732
- **Solved in**: 1 attempt(s)

## Problem Summary
An insurance agent earns a commission of 20% on each insurance policy sold, where each policy costs $X$ dollars. The agent wants to earn at least 100 dollars. We need to find the minimum number of insurance policies ($N$) the agent must sell to reach or exceed this target.

## Intuition & Mathematical Observation
1. **Commission Calculation**: The commission per policy is $20\%$ of $X$, which is $0.2 \times X$ or $\frac{X}{5}$.
2. **Setting up the Inequality**: To earn at least 100 dollars, the total commission from $N$ policies must satisfy:
   $$N \times \left(\frac{X}{5}\right) \geq 100$$
3. **Simplification**: Multiply both sides by 5 to clear the fraction:
   $$N \times X \geq 500$$
4. **Solving for N**:
   $$N \geq \frac{500}{X}$$
   Since $N$ must be an integer, we take the ceiling of the division:
   $$N = \lceil \frac{500}{X} \rceil$$
5. **Integer Arithmetic**: In programming, the ceiling of $\frac{A}{B}$ can be calculated using integer division as `(A + B - 1) / B`. Thus, our formula becomes `(500 + X - 1) / X`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each insurance costs X dollars.
 * Commission per insurance = 20% of X = 0.2 * X = X / 5.
 * Let N be the number of insurances sold.
 * Total earnings = N * (X / 5).
 * We need Total earnings >= 100.
 * N * (X / 5) >= 100
 * N * X >= 500
 * N >= 500 / X
 * Since N must be an integer, N = ceil(500 / X).
 * 
 * Using integer arithmetic, ceil(A / B) can be calculated as (A + B - 1) / B.
 * So, N = (500 + X - 1) / X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate minimum N such that N * (x / 5.0) >= 100
        // Which simplifies to N * x >= 500
        // N = ceil(500 / x)
        long long ans = (500 + x - 1) / x;
        
        cout << ans << "\n";
    }

    return 0;
}
```