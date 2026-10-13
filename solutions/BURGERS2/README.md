# [Hungry Chef (BURGERS2)](https://www.codechef.com/problems/BURGERS2)

- **Difficulty Rating**: 1187
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy exactly $N$ burgers. There are two types of burgers:
1. **Normal Burger**: Costs $X$ rupees.
2. **Premium Burger**: Costs $Y$ rupees.

Given a total budget of $R$ rupees, determine the number of normal and premium burgers Chef can buy such that the total count is exactly $N$ and the total cost does not exceed $R$. If it is impossible to satisfy these conditions, output -1.

## Intuition & Mathematical Observation
Let $n_{normal}$ be the number of normal burgers and $n_{premium}$ be the number of premium burgers. We have the following system:
1. $n_{normal} + n_{premium} = N$
2. $X \cdot n_{normal} + Y \cdot n_{premium} \le R$

Substituting $n_{normal} = N - n_{premium}$ into the second inequality:
$X(N - n_{premium}) + Y \cdot n_{premium} \le R$
$X \cdot N - X \cdot n_{premium} + Y \cdot n_{premium} \le R$
$n_{premium}(Y - X) \le R - X \cdot N$

**Key Observations:**
* If $X \cdot N > R$, even buying the cheapest burgers (normal) exceeds the budget. Thus, it is impossible (output -1).
* If $X \cdot N \le R$, we want to maximize $n_{premium}$ to satisfy the constraints. From the derived inequality, $n_{premium} \le \frac{R - X \cdot N}{Y - X}$.
* Since we cannot buy more than $N$ burgers total, the number of premium burgers is $\min(N, \lfloor \frac{R - X \cdot N}{Y - X} \rfloor)$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let n_normal be the number of normal burgers and n_premium be the number of premium burgers.
 * We have two equations:
 * 1) n_normal + n_premium = N
 * 2) X * n_normal + Y * n_premium <= R
 * 
 * Substituting n_normal = N - n_premium into (2):
 * X * (N - n_premium) + Y * n_premium <= R
 * X * N - X * n_premium + Y * n_premium <= R
 * n_premium * (Y - X) <= R - X * N
 * 
 * Since Y > X, (Y - X) is positive.
 * n_premium <= (R - X * N) / (Y - X)
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // If even buying N normal burgers costs more than R, it's impossible.
    if (N * X > R) {
        cout << -1 << "\n";
        return;
    }

    // Calculate max premium burgers possible
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - X * N) / (Y - X);
    
    // We cannot buy more than N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
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