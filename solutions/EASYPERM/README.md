# [Easy Permutation (EASYPERM)](https://www.codechef.com/problems/EASYPERM)

- **Difficulty Rating**: 1057
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct a permutation $A$ of the set $\{1, 2, \dots, N\}$ such that the Least Common Multiple (LCM) of the sequence $B_i = i + A_i$ (for $1 \le i \le N$) is minimized.

## Intuition & Mathematical Observation
Let $B_i = i + A_i$. We are looking for a permutation $A$ that minimizes $\text{LCM}(B_1, B_2, \dots, B_N)$.

Consider the sum of all elements in the sequence $B$:
$$\sum_{i=1}^{N} B_i = \sum_{i=1}^{N} (i + A_i) = \sum_{i=1}^{N} i + \sum_{i=1}^{N} A_i$$
Since $A$ is a permutation of $\{1, \dots, N\}$, $\sum A_i = \sum i = \frac{N(N+1)}{2}$.
Therefore, $\sum B_i = N(N+1)$.

The average value of $B_i$ is $\frac{N(N+1)}{N} = N+1$. If we can make every $B_i$ equal to $N+1$, the LCM of the sequence will simply be $N+1$. 

We can achieve $B_i = N+1$ by setting:
$$i + A_i = N + 1 \implies A_i = N - i + 1$$
For example, if $N=3$:
- $i=1 \implies A_1 = 3-1+1 = 3$
- $i=2 \implies A_2 = 3-2+1 = 2$
- $i=3 \implies A_3 = 3-3+1 = 1$
The sequence $B$ becomes $\{4, 4, 4\}$, and $\text{LCM}(4, 4, 4) = 4$, which is $N+1$. This construction is optimal because the LCM of a set of numbers is at least the maximum value in that set, and since the average is $N+1$, at least one $B_i$ must be $\ge N+1$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate from $1$ to $N$ once to print the permutation.
- **Space Complexity**: $O(1)$, as we do not store the permutation and print the values on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a permutation A of {1, 2, ..., N} such that 
 * LCM(1+A_1, 2+A_2, ..., N+A_N) is minimized.
 * 
 * By setting A_i = N - i + 1, we ensure that i + A_i = N + 1 for all i.
 * This results in the LCM being N + 1, which is the theoretical minimum.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        
        // Output the permutation A_i = N - i + 1
        for (int i = 0; i < n; ++i) {
            cout << (n - i) << (i == n - 1 ? "" : " ");
        }
        cout << "\n";
    }
    
    return 0;
}
```