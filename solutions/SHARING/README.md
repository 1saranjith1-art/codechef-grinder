# [Sharing Cookies (SHARING)](https://www.codechef.com/problems/SHARING)

- **Difficulty Rating**: 232
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has $A$ cookies and Bob has $B$ cookies, where $A > B$. Alice wants to give $x$ cookies to Bob such that they end up with an equal number of cookies. We need to determine if such an integer $x$ exists, and if so, find the value of $x$. If it is impossible to make their cookie counts equal, we should output -1.

## Intuition & Mathematical Observation
To make the number of cookies equal, the following equation must hold after the transfer:
$$A - x = B + x$$

Rearranging the terms to solve for $x$:
$$A - B = 2x$$
$$x = \frac{A - B}{2}$$

From this equation, we can derive two necessary conditions for a valid solution:
1. **Parity**: Since $x$ must be an integer, $(A - B)$ must be divisible by 2. In other words, $(A - B) \pmod 2$ must be $0$.
2. **Positivity**: Since the problem states $A > B$, the value $A - B$ will always be positive, ensuring $x > 0$.

If $(A - B)$ is odd, it is impossible to split the difference equally, so we output -1. Otherwise, we output the result of $(A - B) / 2$.

## Complexity Analysis
- **Time Complexity**: $O(1)$, as the solution involves only basic arithmetic operations performed in constant time.
- **Space Complexity**: $O(1)$, as we only use a fixed amount of memory to store the input variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    if (!(cin >> A >> B)) return 0;

    // Check if the difference is even
    if ((A - B) % 2 == 0) {
        cout << (A - B) / 2 << "\n";
    } else {
        // If odd, it's impossible to split equally
        cout << -1 << "\n";
    }

    return 0;
}
```