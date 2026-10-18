# [Average of Three (AVGOF3)](https://www.codechef.com/problems/AVGOF3)

- **Difficulty Rating**: 1141
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $X$, we are required to find three **distinct** positive integers $A_1, A_2, A_3$ such that their average is exactly $X$. That is:
$$\frac{A_1 + A_2 + A_3}{3} = X$$
The constraints specify that $2 \le X \le 100$ and the resulting integers must be within the range $[1, 1000]$.

## Intuition & Mathematical Observation
The equation $\frac{A_1 + A_2 + A_3}{3} = X$ can be rewritten as:
$$A_1 + A_2 + A_3 = 3X$$

To satisfy this equation with three distinct integers, we can choose a symmetric distribution around $X$. By picking $A_1 = X - 1$, $A_2 = X$, and $A_3 = X + 1$, we observe:
1. **Sum**: $(X - 1) + X + (X + 1) = 3X$. Dividing by 3 gives $X$.
2. **Distinctness**: Since $X-1 < X < X+1$, the three numbers are always distinct.
3. **Constraints**: Given $2 \le X \le 100$:
   - The smallest value is $A_1 = 2 - 1 = 1$, which is $\ge 1$.
   - The largest value is $A_3 = 100 + 1 = 101$, which is $\le 1000$.

This construction is valid for all possible inputs provided in the problem.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we perform a constant number of arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * We can choose A1 = X - 1, A2 = X, and A3 = X + 1.
 * Let's check the conditions:
 * 1. Mean: ((X - 1) + X + (X + 1)) / 3 = 3X / 3 = X. (Correct)
 * 2. Distinct: X-1, X, X+1 are always distinct. (Correct)
 * 3. Range: 1 <= A_i <= 1000.
 *    Given 2 <= X <= 100:
 *    - Minimum A1 = 2 - 1 = 1. (Valid)
 *    - Maximum A3 = 100 + 1 = 101. (Valid, since 101 <= 1000)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Output the constructed triplet
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}
```