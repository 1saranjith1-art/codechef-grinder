# [Balanced Lighting (RBLT)](https://www.codechef.com/problems/RBLT)

- **Difficulty Rating**: 755
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ lights, each represented by a value: $1$ (Red), $2$ (Blue), or $0$ (Undecided). We need to determine if it is possible to assign a color (Red or Blue) to all undecided lights such that the total number of Red lights equals the total number of Blue lights.

## Intuition & Mathematical Observation
To have an equal number of Red and Blue lights, the total number of lights $N$ must be even. If $N$ is odd, it is impossible to split them into two equal groups, so we immediately output "No".

Let:
- $R$ = count of existing Red lights.
- $B$ = count of existing Blue lights.
- $U$ = count of Undecided lights.
- $k$ = number of undecided lights we choose to turn Red.
- $U - k$ = number of undecided lights we choose to turn Blue.

For the final configuration to be balanced, the total number of Red lights must equal the total number of Blue lights:
$$R + k = B + (U - k)$$

Rearranging the equation to solve for $k$:
$$2k = B + U - R$$
Since $R + B + U = N$, we know $B + U = N - R$. Substituting this:
$$2k = (N - R) - R$$
$$2k = N - 2R$$
$$k = \frac{N}{2} - R$$

For a valid assignment to exist, $k$ must be a non-negative integer that does not exceed the total number of available undecided lights ($0 \le k \le U$). If these conditions are met, we can balance the lights.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array of lights exactly once to count the occurrences of $1, 2,$ and $0$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the counts regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to set all 0s to 1 or 2 such that the total count of 1s equals the total count of 2s.
 * This implies the total number of lights N must be even.
 * Let k be the number of 0s turned into 1s.
 * Then (U - k) is the number of 0s turned into 2s.
 * Requirement: R + k = B + (U - k)
 * Solving for k: k = N/2 - R
 */

void solve() {
    int N;
    cin >> N;
    int R = 0, B = 0, U = 0;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        if (c == 1) R++;
        else if (c == 2) B++;
        else U++;
    }

    // A balanced configuration requires an even total number of lights.
    if (N % 2 != 0) {
        cout << "No" << "\n";
        return;
    }

    // Calculate required number of Red lights from the undecided set
    int k = (N / 2) - R;

    // Check if k is a valid number of lights to turn Red
    if (k >= 0 && k <= U) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```