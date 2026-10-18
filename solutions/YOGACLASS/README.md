# [Yoga Class (YOGACLASS)](https://www.codechef.com/problems/YOGACLASS)

- **Difficulty Rating**: 879
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ hours available for yoga. He can choose between two types of sessions:
1. **Type 1**: 1 hour long, earning $X$ coins.
2. **Type 2**: 2 hours long, earning $Y$ coins.

The goal is to maximize the total earnings by choosing any combination of these sessions such that the total time spent does not exceed $N$ hours.

## Intuition & Mathematical Observation
To maximize earnings, we need to compare the efficiency of the two session types:
*   **Type 1** earns $X$ per hour.
*   **Type 2** earns $Y/2$ per hour.

We have two main strategies to consider:
1.  **Prioritize Type 2 sessions**: Take as many 2-hour sessions as possible ($\lfloor N/2 \rfloor$) and fill the remaining 1 hour (if any) with a Type 1 session. This is optimal if $Y > 2X$.
2.  **Use only Type 1 sessions**: If $2X > Y$, it is more profitable to treat every hour as a Type 1 session, earning $N \times X$ in total.

By calculating both the earnings from maximizing Type 2 sessions and the earnings from using only Type 1 sessions, we can simply take the `max()` of the two values to guarantee the optimal result.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we are performing a constant number of arithmetic operations. Given $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * 
 * Strategy:
 * We compare taking as many 2-hour sessions as possible versus taking 
 * only 1-hour sessions.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Number of 2-hour sessions we can fit
        long long num_type2 = n / 2;
        long long remaining_hours = n % 2;

        // Option 1: Maximize Type 2 sessions
        long long earnings_max_type2 = (num_type2 * y) + (remaining_hours * x);

        // Option 2: All Type 1 sessions
        long long earnings_all_type1 = n * x;

        // The answer is the maximum of these two strategies
        cout << max(earnings_max_type2, earnings_all_type1) << "\n";
    }

    return 0;
}
```