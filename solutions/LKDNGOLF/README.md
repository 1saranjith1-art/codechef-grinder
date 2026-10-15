# [Golf (LKDNGOLF)](https://www.codechef.com/problems/LKDNGOLF)

- **Difficulty Rating**: 1256
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks whether a golf ball, starting at position $0$ and moving in steps of size $k$, will land on a specific target tile $x$ during either its forward journey or its backward journey. 
- The hallway consists of tiles indexed from $0$ to $N+1$.
- **Forward journey**: The ball starts at $0$ and lands on tiles $0, k, 2k, \dots$ as long as the position $\le N+1$.
- **Backward journey**: After reaching the end, the ball travels back from $N+1$ in steps of $k$, landing on tiles $(N+1), (N+1)-k, (N+1)-2k, \dots$ as long as the position $\ge 0$.

## Intuition & Mathematical Observation
To determine if the ball lands on tile $x$, we check two conditions:

1.  **Forward Journey**: The ball lands on $x$ if $x$ is a multiple of $k$.
    *   Condition: `x % k == 0`
2.  **Backward Journey**: The ball starts at $N+1$ and moves backwards by $k$. It lands on $x$ if the distance between $N+1$ and $x$ is a multiple of $k$.
    *   Condition: `(N + 1 - x) % k == 0`

If either of these conditions is true, the ball hits the target $x$. Since $N$ can be as large as $10^9$, we must use `long long` to prevent overflow and ensure our logic performs in constant time per test case.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time using simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The hallway has tiles 0 to N+1.
 * Forward journey: The ball lands on tiles {0, k, 2k, ..., m*k} such that m*k <= N+1.
 * This means the ball lands on tile x if x % k == 0.
 * 
 * Backward journey: The ball starts at N+1 and lands on tiles {(N+1), (N+1)-k, (N+1)-2k, ...}.
 * This means the ball lands on tile x if (N+1 - x) is a multiple of k.
 * Mathematically, (N+1 - x) % k == 0.
 * 
 * Constraints:
 * T <= 10^5, N <= 10^9.
 * We need O(1) per test case.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        // Forward journey check: x is a multiple of k
        bool forward = (x % k == 0);

        // Backward journey check: (N+1 - x) is a multiple of k
        bool backward = ((n + 1 - x) % k == 0);

        if (forward || backward) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```