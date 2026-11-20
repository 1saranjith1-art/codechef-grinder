# [Friends Meetup (FRIMEET)](https://www.codechef.com/problems/FRIMEET)

- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is at position $X_1$ and moves at a speed of $+1$ unit per second. His friend is at position $X_2$ and moves at a speed of $+2$ units per second. We need to determine if there exists a time $t \ge 0$ such that both Chef and his friend are at the same position.

## Intuition & Mathematical Observation
Let $P_1(t)$ be Chef's position at time $t$ and $P_2(t)$ be the friend's position at time $t$:
*   $P_1(t) = X_1 + 1 \cdot t$
*   $P_2(t) = X_2 + 2 \cdot t$

For them to meet, we set $P_1(t) = P_2(t)$:
$$X_1 + t = X_2 + 2t$$
$$X_1 - X_2 = 2t - t$$
$$t = X_1 - X_2$$

Since the problem requires the meeting to happen at some time $t \ge 0$, we must satisfy:
$$X_1 - X_2 \ge 0 \implies X_1 \ge X_2$$

*   **If $X_1 \ge X_2$**: They will meet at time $t = X_1 - X_2$.
*   **If $X_1 < X_2$**: The friend starts ahead of Chef and moves faster than Chef, meaning the distance between them will only increase over time. Thus, they will never meet.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a simple comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and perform the comparison.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at X1 and moves at +1 per second. After t seconds, his position is P1 = X1 + t.
 * Friend is at X2 and moves at +2 per second. After t seconds, his position is P2 = X2 + 2t.
 * 
 * They meet if P1 = P2 for some t >= 0.
 * X1 + t = X2 + 2t
 * X1 - X2 = 2t - t
 * X1 - X2 = t
 * 
 * Since t must be non-negative (t >= 0), the condition for them to meet is:
 * X1 - X2 >= 0
 * X1 >= X2
 * 
 * If X1 >= X2, they will meet at time t = X1 - X2.
 * If X1 < X2, the friend is already ahead and moving faster, so they will never meet.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x1, x2;
        cin >> x1 >> x2;

        // Based on the derivation X1 >= X2
        if (x1 >= x2) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
```