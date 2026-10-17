# [Survival Time (FIZZBUZZ23_2)](https://www.codechef.com/problems/FIZZBUZZ23_2)

- **Difficulty Rating**: 716
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ buns, and a family of 5 members. Each member consumes $X$ buns per day. Additionally, the family has a supply of food that lasts for $D$ days without needing any buns. We need to calculate the total number of days the family can survive, considering both the buns available and the extra $D$ days of food.

## Intuition & Mathematical Observation
1. **Daily Consumption**: Since there are 5 family members and each consumes $X$ buns, the total number of buns consumed per day is $5 \times X$.
2. **Buns Duration**: The number of days the $N$ buns will last is determined by integer division: $\lfloor N / (5 \times X) \rfloor$.
3. **Total Survival**: The family survives for the duration provided by the buns plus the additional $D$ days they already have food for.
4. **Formula**: $\text{Total Days} = \lfloor \frac{N}{5 \times X} \rfloor + D$.

Given the constraints ($N < 500, X \le 10, D < 20$), standard integer arithmetic is perfectly safe and efficient.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily bun requirement = 5 * X.
 * Number of days the buns last = floor(N / (5 * X)).
 * Total survival days = (days buns last) + D.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns required per day for the family of 5
        long long daily_requirement = 5 * x;

        // Calculate how many full days the buns can feed the family
        long long days_with_food = n / daily_requirement;

        // Total survival time is the days with food plus the extra D days
        long long total_survival_days = days_with_food + d;

        cout << total_survival_days << "\n";
    }

    return 0;
}
```