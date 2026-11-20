# [Marbles (MARBLES)](https://www.codechef.com/problems/MARBLES)

- **Difficulty Rating**: 1150
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $n$ marbles and $k$ different colors, we need to find the number of ways to distribute the marbles such that each color is represented by at least one marble. In other words, we need to find the number of integer solutions to $x_1 + x_2 + \dots + x_k = n$ where $x_i \ge 1$ for all $i \in \{1, \dots, k\}$.

## Intuition & Mathematical Observation
This is a classic combinatorial problem solvable using the **Stars and Bars** theorem.

1.  **Transformation**: We are given the equation $x_1 + x_2 + \dots + x_k = n$ with $x_i \ge 1$.
2.  **Substitution**: Let $y_i = x_i - 1$, where $y_i \ge 0$. Substituting this into the equation:
    $(y_1 + 1) + (y_2 + 1) + \dots + (y_k + 1) = n$
    $y_1 + y_2 + \dots + y_k = n - k$
3.  **Formula**: The number of non-negative integer solutions to $y_1 + \dots + y_k = S$ is given by $\binom{S + k - 1}{k - 1}$.
    Substituting $S = n - k$:
    $\binom{(n - k) + k - 1}{k - 1} = \binom{n - 1}{k - 1}$
4.  **Implementation**: To compute $\binom{n-1}{k-1}$ efficiently:
    *   Use the property $\binom{N}{K} = \binom{N}{N-K}$ to minimize the number of iterations.
    *   Compute the result iteratively using `res = res * (N - i + 1) / i` to prevent overflow and maintain precision within a 64-bit integer (`long long`).

## Complexity Analysis
- **Time Complexity**: $O(k)$, where $k$ is the number of colors. Since we iterate up to $k-1$ (or $n-k$), the loop runs at most $O(n)$ times. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the result and intermediate calculations.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select n marbles of k different colors such that we have at least one of each color.
 * This is a classic stars and bars problem.
 * The number of ways is given by C(n - 1, k - 1).
 */

long long solve() {
    long long n, k;
    cin >> n >> k;
    
    // We need to calculate C(n-1, k-1)
    long long N = n - 1;
    long long K = k - 1;
    
    // Optimization: C(N, K) = C(N, N-K)
    if (K > N / 2) {
        K = N - K;
    }
    
    long long res = 1;
    for (long long i = 1; i <= K; ++i) {
        res = res * (N - i + 1) / i;
    }
    
    return res;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}
```