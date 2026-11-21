# [Sign Moves (SIGNMOVE)](https://www.codechef.com/problems/SIGNMOVE)

- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary
We start at position $0$. For each step $i$ from $1$ to $N$:
- If the current position is $\ge 0$, we subtract $i$ from the current position.
- If the current position is $< 0$, we add $i$ to the current position.
Given $N$, we need to find the final position after $N$ steps.

## Intuition & Mathematical Observation
By simulating the first few steps, we can identify a clear pattern:

| Step ($i$) | Position ($P_i$) |
| :--- | :--- |
| 0 | 0 |
| 1 | $0 - 1 = -1$ |
| 2 | $-1 + 2 = 1$ |
| 3 | $1 - 3 = -2$ |
| 4 | $-2 + 4 = 2$ |
| 5 | $2 - 5 = -3$ |
| 6 | $-3 + 6 = 3$ |

**Pattern Analysis:**
- When $N$ is **even**, the position is $N / 2$.
- When $N$ is **odd**, the position is $-(N + 1) / 2$.

Since $N$ can be as large as $10^9$, a simple loop simulation would result in a Time Limit Exceeded (TLE). Using this mathematical observation allows us to calculate the result in constant time.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$ for $T$ test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and output.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let P(i) be the position after i steps.
 * P(0) = 0
 * i=1: P(0) >= 0, so P(1) = 0 - 1 = -1
 * i=2: P(1) < 0, so P(2) = -1 + 2 = 1
 * i=3: P(2) >= 0, so P(3) = 1 - 3 = -2
 * i=4: P(3) < 0, so P(4) = -2 + 4 = 2
 * i=5: P(4) >= 0, so P(5) = 2 - 5 = -3
 * i=6: P(5) < 0, so P(6) = -3 + 6 = 3
 * 
 * Pattern observed:
 * If N is even, P(N) = N / 2
 * If N is odd, P(N) = -(N + 1) / 2
 * 
 * Constraints: N up to 10^9, so O(1) per test case is required.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        if (n % 2 == 0) {
            cout << (n / 2) << "\n";
        } else {
            cout << -((n + 1) / 2) << "\n";
        }
    }
    return 0;
}
```