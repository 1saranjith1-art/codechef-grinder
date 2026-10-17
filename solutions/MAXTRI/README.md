# [Max Triangle (MAXTRI)](https://www.codechef.com/problems/MAXTRI)

- **Difficulty Rating**: 664
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a set of sticks with lengths $1, 2, 3, \dots, N$, the goal is to select three sticks that form a non-degenerate triangle such that their perimeter ($A + B + C$) is maximized. If no such triangle can be formed, output -1.

## Intuition & Mathematical Observation
To form a non-degenerate triangle with sides $A, B, C$ (where $A \le B \le C$), the triangle inequality theorem states that the sum of the two smaller sides must be strictly greater than the largest side:
$$A + B > C$$

To maximize the perimeter $A + B + C$, we should greedily pick the largest available sticks. Let the largest stick be $C = N$. To maximize the sum, we pick the next two largest sticks: $B = N-1$ and $A = N-2$.

Checking the triangle inequality for these values:
$$(N-2) + (N-1) > N$$
$$2N - 3 > N$$
$$N > 3$$

- **Case $N < 4$**: 
    - If $N=3$, the sticks are $\{1, 2, 3\}$. $1+2 = 3$, which is not $> 3$. No triangle is possible.
    - If $N < 3$, it is impossible to pick three distinct sticks.
    - Thus, for $N < 4$, the answer is **-1**.
- **Case $N \ge 4$**: 
    - We can always form a triangle using $N, N-1,$ and $N-2$.
    - The maximum perimeter is $N + (N-1) + (N-2) = 3N - 3$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple arithmetic calculation. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have sticks of lengths 1, 2, ..., N.
 * To maximize the perimeter (A + B + C), we pick the largest possible values:
 * C = N, B = N-1, A = N-2.
 * The condition A + B > C becomes (N-2) + (N-1) > N, which simplifies to N > 3.
 * For N >= 4, the perimeter is 3N - 3.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;

        if (n < 4) {
            cout << -1 << "\n";
        } else {
            // The maximum perimeter is formed by the three largest sticks: N, N-1, N-2
            long long result = n + (n - 1) + (n - 2);
            cout << result << "\n";
        }
    }

    return 0;
}
```