# [Money Double (MONEYDOUBLE)](https://www.codechef.com/problems/MONEYDOUBLE)

- **Difficulty Rating**: 784
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef starts with an initial amount of $X$ rupees and has $Y$ years to grow his money. Each year, he can choose one of two operations:
1. Add 1000 rupees to his current amount ($X = X + 1000$).
2. Double his current amount ($X = X \times 2$).

The goal is to maximize the total amount of money Chef has after $Y$ years.

## Intuition & Mathematical Observation
To maximize the final amount, we need to make the optimal choice at every step. Let's compare the two operations:
- If $X < 1000$: Adding 1000 results in $X + 1000$, while doubling results in $2X$. Since $X < 1000$, $X + 1000 > 2X$. Thus, adding is better.
- If $X > 1000$: Adding 1000 results in $X + 1000$, while doubling results in $2X$. Since $X > 1000$, $2X > X + 1000$. Thus, doubling is better.
- If $X = 1000$: Both operations result in 2000.

Because the optimal choice at any given year depends only on the current value of $X$, we can use a **Greedy Approach**. By simply comparing $X + 1000$ and $X \times 2$ at each of the $Y$ steps and picking the larger value, we ensure the maximum possible growth.

## Complexity Analysis
- **Time Complexity**: $O(T \times Y)$, where $T$ is the number of test cases and $Y$ is the number of years. Given $Y \le 10$, this is effectively $O(T)$, which easily passes within the time limit.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current amount and loop counters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Since Y is very small (up to 10), we can simulate the process year by year.
 * At each step, we greedily choose the operation that yields the higher value.
 */

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;

        for (int i = 0; i < y; ++i) {
            // Greedy choice: at each step, take the maximum of the two options
            long long add_option = x + 1000;
            long long double_option = x * 2;
            
            if (add_option > double_option) {
                x = add_option;
            } else {
                x = double_option;
            }
        }

        cout << x << "\n";
    }

    return 0;
}
```