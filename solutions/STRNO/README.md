# [Strange Number (STRNO)](https://www.codechef.com/problems/STRNO)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $X$ and $K$, determine if there exists an integer $A$ such that:
1. The total number of divisors of $A$ is exactly $X$.
2. The total number of prime factors of $A$ (counting multiplicity) is exactly $K$.

## Intuition & Mathematical Observation
Let the prime factorization of $A$ be $p_1^{a_1} \cdot p_2^{a_2} \cdot \dots \cdot p_m^{a_m}$.
- The number of divisors $X$ is given by: $(a_1 + 1)(a_2 + 1) \dots (a_m + 1)$.
- The total number of prime factors $K$ is given by: $a_1 + a_2 + \dots + a_m$.

We are looking for a set of exponents $\{a_1, a_2, \dots, a_m\}$ such that their sum is $K$ and the product of $(a_i + 1)$ is $X$. 

**Key Observations:**
1. Since each $a_i \ge 1$, the smallest possible value for each term $(a_i + 1)$ is 2. Therefore, if we have $K$ prime factors, the minimum number of divisors is $2^K$. If $X < 2^K$, it is impossible to satisfy the condition.
2. Conversely, we can represent $X$ as a product of prime factors. Let the prime factorization of $X$ be $q_1 \cdot q_2 \cdot \dots \cdot q_n$. Each $q_i$ corresponds to a term $(a_j + 1)$. Since $a_j = q_i - 1$, the number of prime factors contributed by this term is $q_i - 1$.
3. The maximum number of prime factors we can obtain for a given $X$ is by breaking $X$ down into its smallest prime factors. The total number of prime factors $K$ must be less than or equal to the total number of prime factors of $X$ (counting multiplicity).
4. For $K > 30$, $2^K > 10^9$ (the typical constraint for $X$), so we can immediately return 0 for large $K$.

## Complexity Analysis
- **Time Complexity**: $O(\sqrt{X})$ per test case, as we perform prime factorization of $X$ to count its prime factors.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * The problem asks if we can find an integer A with X divisors and K prime factors.
 * We use the property that if A = p1^a1 * p2^a2 * ... * pm^am,
 * then X = (a1+1)*(a2+1)*...*(am+1) and K = a1+a2+...+am.
 * 
 * We check if the number of prime factors of X (counting multiplicity) 
 * is at least K.
 */

int countPrimeFactors(int n) {
    int count = 0;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            count++;
            n /= i;
        }
    }
    if (n > 1) count++;
    return count;
}

void solve() {
    long long X, K;
    cin >> X >> K;

    // If K is very large, 2^K will exceed the maximum possible X.
    // 2^30 is > 10^9, which covers the typical constraints.
    if (K > 30) {
        cout << 0 << "\n";
        return;
    }

    // The number of prime factors (counting multiplicity) of A must be at least K.
    // We check if the prime factorization of X allows for at least K factors.
    if (countPrimeFactors(X) >= K) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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