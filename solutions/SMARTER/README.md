# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)

- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum integer number of seconds ($w$) a hare can wait before starting a race of length $L$ such that the hare still finishes strictly before the tortoise. We are given the tortoise's speed ($V_1$) and the hare's speed ($V_2$). The time taken is calculated as the ceiling of the distance divided by the speed.

## Intuition & Mathematical Observation
1.  **Time Calculation**: Since the race time is the ceiling of $L/V$, we use the integer arithmetic formula for ceiling division: $\lceil L/V \rceil = (L + V - 1) / V$.
2.  **Tortoise Time**: $T_{tortoise} = \lceil L / V_1 \rceil$.
3.  **Hare Time**: If the hare waits $w$ seconds, the total time taken is $T_{hare} = w + \lceil L / V_2 \rceil$.
4.  **Winning Condition**: The hare wins if $T_{hare} < T_{tortoise}$.
    *   $w + \lceil L / V_2 \rceil < \lceil L / V_1 \rceil$
    *   $w < \lceil L / V_1 \rceil - \lceil L / V_2 \rceil$
5.  **Maximizing $w$**: Let $diff = \lceil L / V_1 \rceil - \lceil L / V_2 \rceil$. We need the largest integer $w$ such that $w < diff$. This is simply $diff - 1$.
6.  **Edge Case**: If $diff \le 0$, it is impossible for the hare to win even with $w=0$, so we output $-1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. With $T$ test cases, the total complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Hare time (T_hare) = w + ceil(L / V2)
 * 
 * The condition to win is:
 * w + ceil(L / V2) < ceil(L / V1)
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Let diff = ceil(L / V1) - ceil(L / V2).
 * The largest integer w is diff - 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long L, V1, V2;
        cin >> L >> V1 >> V2;

        // Calculate ceil(L / V1) and ceil(L / V2)
        // Using integer arithmetic: ceil(a/b) = (a + b - 1) / b
        long long tortoise_time = (L + V1 - 1) / V1;
        long long hare_base_time = (L + V2 - 1) / V2;

        // We need w < tortoise_time - hare_base_time
        long long diff = tortoise_time - hare_base_time;

        if (diff <= 0) {
            cout << -1 << "\n";
        } else {
            // The largest integer w < diff is diff - 1
            cout << (diff - 1) << "\n";
        }
    }

    return 0;
}
```