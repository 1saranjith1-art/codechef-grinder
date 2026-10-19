# [Placing 01 And 10 (PLACE0110)](https://www.codechef.com/problems/PLACE0110)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $X$ strings of "01" and $Y$ strings of "10". We need to arrange all these $X+Y$ strings in some order to form a single string $S$ such that the number of transitions (indices $i$ where $S[i] \neq S[i+1]$) is minimized. We must output this minimum number of transitions.

## Intuition & Mathematical Observation
Let $A$ represent the string "01" and $B$ represent the string "10".
1. **Internal Transitions**: Each $A$ contains one transition ($0 \to 1$), and each $B$ contains one transition ($1 \to 0$). Thus, regardless of the arrangement, we start with a base of $X + Y$ transitions.
2. **Boundary Transitions**: When concatenating two strings, a new transition is created if the boundary characters are different:
   - $A+A$ ("01"+"01"): Boundary is '1' to '0' $\to$ **+1 transition**.
   - $B+B$ ("10"+"10"): Boundary is '0' to '1' $\to$ **+1 transition**.
   - $A+B$ ("01"+"10"): Boundary is '1' to '1' $\to$ **0 transitions**.
   - $B+A$ ("10"+"01"): Boundary is '0' to '0' $\to$ **0 transitions**.

To minimize the total transitions, we should maximize the number of $A+B$ or $B+A$ adjacencies. This is equivalent to alternating the strings as much as possible (e.g., $ABAB...$ or $BABA...$).

- **Case 1: $|X - Y| \le 1$**: We can alternate the strings perfectly (e.g., $ABAB...$ or $BABA...$). No extra boundary transitions are forced.
  - Total = $X + Y$.
- **Case 2: $X > Y + 1$**: We are forced to place some $A$ strings next to each other. To minimize this, we place all $Y$ strings of $B$ to "break up" the $X$ strings of $A$. We will have $X-Y-1$ forced $A+A$ adjacencies.
  - Total = $(X + Y) + (X - Y - 1) = 2X - 1$.
- **Case 3: $Y > X + 1$**: Similarly, we are forced to have $Y-X-1$ forced $B+B$ adjacencies.
  - Total = $(X + Y) + (Y - X - 1) = 2Y - 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X strings of "01" and Y strings of "10".
 * Each "01" and "10" contributes 1 internal transition.
 * Concatenating "01"+"01" or "10"+"10" adds an extra transition at the boundary.
 * Concatenating "01"+"10" or "10"+"01" adds no extra transition.
 * 
 * By alternating A and B, we minimize boundary transitions.
 * If |X - Y| <= 1, we can alternate perfectly: Total = X + Y.
 * If X > Y + 1, we have (X - Y - 1) extra A+A boundaries: Total = 2X - 1.
 * If Y > X + 1, we have (Y - X - 1) extra B+B boundaries: Total = 2Y - 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (abs(X - Y) <= 1) {
        cout << X + Y << "\n";
    } else if (X > Y) {
        cout << 2 * X - 1 << "\n";
    } else {
        cout << 2 * Y - 1 << "\n";
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