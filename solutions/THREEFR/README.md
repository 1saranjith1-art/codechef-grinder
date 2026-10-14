# [Three Friends (THREEFR)](https://www.codechef.com/problems/THREEFR)

- **Difficulty Rating**: 1074
- **Solved in**: 1 attempt(s)

## Problem Summary
Three friends have amounts of money $A, B,$ and $C$. We are given the absolute differences between their amounts: $X = |A - B|$, $Y = |B - C|$, and $Z = |C - A|$. We need to determine if it is possible for these three friends to have amounts $A, B,$ and $C$ that satisfy the given absolute differences.

## Intuition & Mathematical Observation
Let the differences be $x = A - B$, $y = B - C$, and $z = C - A$.
By summing these equations, we get:
$$(A - B) + (B - C) + (C - A) = 0 \implies x + y + z = 0$$

We are given the absolute values $X = |x|$, $Y = |y|$, and $Z = |z|$. The condition $x + y + z = 0$ implies that we can assign signs to $X, Y,$ and $Z$ such that their sum is zero. Specifically, one of the values must be the sum of the other two.

For example:
- If $x + y = z$, then $|x + y| = |z| = Z$. This can be satisfied if $X + Y = Z$ or $|X - Y| = Z$.
- By rearranging the equation $x + y + z = 0$, we can see that the condition is satisfied if:
    1. $X + Y = Z$
    2. $X + Z = Y$
    3. $Y + Z = X$

If any of these three conditions hold, it is possible to find values for $A, B,$ and $C$ that satisfy the given differences.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of arithmetic operations and comparisons. With $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the inputs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given |A - B| = X, |B - C| = Y, |C - A| = Z.
 * Let x = A - B, y = B - C, z = C - A.
 * Then x + y + z = 0.
 * This implies that one of the values must be the sum of the other two 
 * (e.g., X + Y = Z, X + Z = Y, or Y + Z = X).
 */

void solve() {
    int X, Y, Z;
    cin >> X >> Y >> Z;

    // Check if any one value is the sum of the other two
    if ((X + Y == Z) || (X + Z == Y) || (Y + Z == X)) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
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