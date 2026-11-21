# [Check Odd Even Divisors (ODDEVENDIV)](https://www.codechef.com/problems/ODDEVENDIV)

- **Difficulty Rating**: 1105
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, determine if there exists a positive integer $N$ such that $N$ has exactly $A$ odd divisors and exactly $B$ even divisors.

## Intuition & Mathematical Observation
Any positive integer $N$ can be uniquely represented as $N = 2^k \cdot m$, where $m$ is an odd integer and $k \ge 0$.

1.  **Odd Divisors ($A$):** The odd divisors of $N$ are precisely the divisors of $m$. If $d(m)$ is the number of divisors of $m$, then $A = d(m)$. Since $m \ge 1$, $m$ always has at least one divisor (the number 1), so $A$ must be at least 1. If $A=0$, no such $N$ exists.
2.  **Even Divisors ($B$):** The even divisors of $N$ are of the form $2^i \cdot d$, where $1 \le i \le k$ and $d$ is any divisor of $m$. There are $k$ choices for $i$ and $d(m)$ choices for $d$. Thus, $B = k \cdot d(m) = k \cdot A$.
3.  **Conditions:**
    *   If $A = 0$: Impossible, output `No`.
    *   If $B = 0$: This implies $k=0$ (i.e., $N$ is odd). Since we can always construct an odd number with $A$ divisors (e.g., $3^{A-1}$), this is always possible. Output `Yes`.
    *   If $B > 0$: We require $k \cdot A = B$. Since $A \ge 1$, this is possible if and only if $B$ is perfectly divisible by $A$ ($B \pmod A == 0$).

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations and conditional checks.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is an odd integer.
 * The odd divisors of N are exactly the divisors of m.
 * Let d(m) be the number of divisors of m. Then A = d(m).
 * Since m is odd, m >= 1, so A must be at least 1.
 * 
 * The even divisors of N are of the form 2^i * d, where 1 <= i <= k and d is a divisor of m.
 * The number of such divisors is B = k * d(m) = k * A.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    // A must be at least 1 because every number has at least one odd divisor (1).
    if (A == 0) {
        cout << "No" << "\n";
    } else {
        // If B is 0, we need k = 0, which is always possible.
        // If B > 0, we need k = B / A to be an integer.
        if (B == 0) {
            cout << "Yes" << "\n";
        } else {
            if (B % A == 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```