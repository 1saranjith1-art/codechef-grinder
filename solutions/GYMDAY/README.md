# [International Gym Day (GYMDAY)](https://www.codechef.com/problems/GYMDAY)

- **Difficulty Rating**: 1201
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy a gym membership priced at $X$ coins. He has a total budget of $Y$ coins. For every trial session he attends (up to a certain point), he spends 1 coin, but he also receives a discount of $D\%$ on the membership price for each session attended. We need to find the minimum number of trial sessions $n$ Chef must attend such that his remaining budget is sufficient to cover the discounted membership price. If it is impossible, output -1.

## Intuition & Mathematical Observation
1. **Budget Constraint**: If Chef attends $n$ sessions, he spends $n$ coins. His remaining budget is $Y - n$.
2. **Discount Calculation**: The membership price $X$ is reduced by $D\%$ for each session. The discounted price is $X \times (1 - \frac{n \times D}{100})$.
3. **Condition**: Chef can afford the membership if:
   $$(Y - n) \geq X \times \left(1 - \frac{n \times D}{100}\right)$$
4. **Implementation Detail**: To avoid floating-point precision errors, we multiply the entire inequality by 100:
   $$100 \times (Y - n) \geq 100 \times X - (X \times n \times D)$$
5. **Search Space**: Since $X \leq 50$ and $Y \leq 50$, the number of sessions $n$ will not exceed $Y$. We can simply iterate through all possible values of $n$ from $0$ to $Y$ and return the first $n$ that satisfies the inequality.

## Complexity Analysis
- **Time Complexity**: $O(Y)$ per test case. Given the constraints $Y \leq 50$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n be the number of trial sessions.
 * Cost of n sessions = n coins.
 * Remaining budget = Y - n.
 * Discount percentage = n * D %.
 * Discounted membership price = X * (1 - (n * D) / 100).
 * Chef can purchase if: (Y - n) >= X * (1 - (n * D) / 100).
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // Check n from 0 up to Y
    for (int n = 0; n <= Y; ++n) {
        // Remaining budget after n sessions
        int remaining_budget = Y - n;
        
        // To avoid floating point issues, we use the integer-multiplied form:
        // 100 * (Y - n) >= 100 * X - (X * n * D)
        if (100 * remaining_budget >= 100 * X - X * n * D) {
            cout << n << "\n";
            return;
        }
    }

    // If no such n is found within the budget
    cout << -1 << "\n";
}

int main() {
    // Fast I/O
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