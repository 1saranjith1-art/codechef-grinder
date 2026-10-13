# [Chef and Contest (CHEFCONTEST)](https://www.codechef.com/problems/CHEFCONTEST)

- **Difficulty Rating**: 872
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef and Chefina are participating in a contest. Chef finishes the contest at time $X$ with $P$ wrong submissions, and Chefina finishes at time $Y$ with $Q$ wrong submissions. Each wrong submission adds a 10-minute penalty to the finishing time. We need to determine who has the lower total penalty (time + penalty). If the penalties are equal, the result is a "Draw".

## Intuition & Mathematical Observation
The total penalty for each participant is calculated as:
*   **Chef's Total Penalty** = $X + (P \times 10)$
*   **Chefina's Total Penalty** = $Y + (Q \times 10)$

Since the constraints for $X, Y, P,$ and $Q$ are small (up to 100), the maximum possible penalty is $100 + (100 \times 10) = 1100$. This fits comfortably within a standard 32-bit integer (`int`). We simply calculate both values and use conditional statements to compare them:
1. If Chef's penalty is smaller, output "Chef".
2. If Chefina's penalty is smaller, output "Chefina".
3. Otherwise, output "Draw".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves basic arithmetic operations and comparisons. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to store the input and calculated results.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef's penalty = X + (P * 10)
 * Chefina's penalty = Y + (Q * 10)
 * We compare these two values.
 * Constraints: X, Y, P, Q <= 100. Max penalty = 100 + 1000 = 1100.
 * Standard 'int' is perfectly sufficient.
 */

void solve() {
    int X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    int chef_penalty = X + (P * 10);
    int chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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