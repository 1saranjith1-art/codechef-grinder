# [The product mystery (PRODUCT)](https://www.codechef.com/problems/PRODUCT)

- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two positive integers $B$ and $C$, we need to find the smallest positive integer $A$ such that the product $(A \times B)$ is perfectly divisible by $C$. In other words, we want to find the minimum $A > 0$ such that $(A \times B) \equiv 0 \pmod C$.

## Intuition & Mathematical Observation
The condition $(A \times B) \pmod C = 0$ implies that $(A \times B)$ must be a multiple of $C$. Let $g = \gcd(B, C)$. We can express $B$ and $C$ in terms of their greatest common divisor:
- $B = g \times b'$
- $C = g \times c'$

Where $\gcd(b', c') = 1$. Substituting these into the original equation:
$$(A \times g \times b') \pmod{g \times c'} = 0$$

Dividing both sides by $g$:
$$(A \times b') \pmod{c'} = 0$$

Since we know that $\gcd(b', c') = 1$, the term $b'$ shares no common factors with $c'$. Therefore, for $(A \times b')$ to be divisible by $c'$, $A$ itself must be a multiple of $c'$. To minimize $A$, we choose the smallest positive integer, which is $A = c'$.

Substituting back $c' = \frac{C}{g}$:
$$A = \frac{C}{\gcd(B, C)}$$

## Complexity Analysis
- **Time Complexity**: $O(\log(\min(B, C)))$ per test case, which is the time required to compute the Greatest Common Divisor using the Euclidean algorithm.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given B and C. We need to find the minimum positive integer A such that:
 * (A * B) % C == 0
 * 
 * This is equivalent to:
 * A * B = k * C for some integer k.
 * A = (k * C) / B
 * 
 * To minimize A, we need to find the smallest k such that (k * C) is divisible by B.
 * Let g = gcd(B, C).
 * Then B = g * b' and C = g * c', where gcd(b', c') = 1.
 * The condition (A * g * b') % (g * c') == 0 simplifies to:
 * (A * b') % c' == 0
 * 
 * Since gcd(b', c') = 1, for (A * b') to be divisible by c', A must be divisible by c'.
 * The smallest positive integer A is therefore c'.
 * 
 * c' = C / gcd(B, C).
 */

long long gcd(long long a, long long b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long b, c;
        cin >> b >> c;
        
        // Calculate gcd of B and C
        long long common = gcd(b, c);
        
        // The result is C / gcd(B, C)
        long long result = c / common;
        
        cout << result << "\n";
    }
    
    return 0;
}
```