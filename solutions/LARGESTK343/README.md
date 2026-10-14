# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ zeros and $Y$ ones, we need to arrange them such that there are at least $K$ ones between any two adjacent zeros. We want to find the maximum possible value of $K$ that satisfies this condition.

## Intuition & Mathematical Observation
To maximize $K$, we must consider the constraints imposed by the $X$ zeros. 
1. When we arrange $X$ zeros, there are exactly $X - 1$ gaps between them.
2. The problem requires that each of these $X - 1$ gaps contains at least $K$ ones.
3. The total number of ones required to satisfy this condition is at least $K \times (X - 1)$.
4. Since we have a total of $Y$ ones available, the condition $K \times (X - 1) \le Y$ must hold.
5. Rearranging this inequality to solve for $K$, we get:
   $$K \le \frac{Y}{X - 1}$$
6. Since $K$ must be an integer, the largest possible value for $K$ is $\lfloor \frac{Y}{X - 1} \rfloor$.

**Edge Case Note:** If $X=1$, there are no gaps between zeros, meaning the condition is vacuously true for any $K$. However, based on the problem constraints, we typically handle $X > 1$. If $X=0$, the problem is undefined, but given the constraints, we focus on the $X-1$ divisor.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) = G.
 * Since we have Y ones in total, the remaining ones (Y - G) can be placed 
 * before the first zero or after the last zero.
 * Thus, we need sum(g_i) <= Y.
 * Since each g_i >= K, the minimum sum is (X - 1) * K.
 * So, (X - 1) * K <= Y.
 * Therefore, K <= Y / (X - 1).
 * The largest integer K is floor(Y / (X - 1)).
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    // X zeros create X-1 internal gaps.
    // We need at least K ones in each of these X-1 gaps.
    // Total ones required = K * (X - 1).
    // This must be <= Y.
    // K <= Y / (X - 1).
    
    // Note: If X=1, the division by zero is avoided by problem constraints 
    // or logic (if X=1, K can be Y).
    if (X <= 1) {
        cout << Y << "\n";
    } else {
        long long K = Y / (X - 1);
        cout << K << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```