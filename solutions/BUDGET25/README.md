# [Budget Allotment (BUDGET25)](https://www.codechef.com/problems/BUDGET25)

- **Difficulty Rating**: 1258
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ sectors with initial budgets $A_i$, we want to maximize the number of sectors that have a budget of at least $X$. We can redistribute the budget from any sector to any other sector. Essentially, we can take the surplus from sectors that have more than $X$ and give it to sectors that have less than $X$ to help them reach the threshold.

## Intuition & Mathematical Observation
1. **Identify Surplus**: Any sector with $A_i > X$ has a surplus of $(A_i - X)$. This total surplus can be pooled together to help sectors that fall short of $X$.
2. **Greedy Strategy**: 
   - First, count all sectors that already satisfy $A_i \ge X$.
   - Collect the total surplus from these sectors.
   - For the remaining sectors that have $A_i < X$, we need to fill their deficits $(X - A_i)$.
   - To maximize the number of sectors we can "save," we should prioritize filling the deficits of the sectors that require the least amount of budget first (i.e., those closest to $X$).
3. **Implementation**:
   - Sort the array $A$ in ascending order.
   - Separate the sectors into two groups: those $\ge X$ and those $< X$.
   - Calculate the total surplus from the first group.
   - Iterate through the second group (starting from the largest values, which are closest to $X$) and subtract the required amount from the surplus until the surplus is exhausted.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting of the array $A$. The subsequent linear scan takes $O(N)$.
- **Space Complexity**: $O(N)$ to store the budget values in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N sectors with initial budgets A_i. We want to maximize the number of sectors
 * that have at least X.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort to easily identify sectors >= X and those < X
    sort(A.begin(), A.end());

    int count = 0;
    int right = N - 1;

    // Count sectors that already meet the requirement
    while (right >= 0 && A[right] >= X) {
        count++;
        right--;
    }

    // Calculate total surplus from sectors that have > X
    long long surplus = 0;
    for (int i = right + 1; i < N; ++i) {
        surplus += (A[i] - X);
    }

    // Use surplus to fill deficits of sectors < X
    // We iterate from the largest of the remaining sectors to minimize cost
    int filled = 0;
    for (int i = right; i >= 0; --i) {
        if (surplus >= (X - A[i])) {
            surplus -= (X - A[i]);
            filled++;
        } else {
            // Cannot fill any more sectors
            break;
        }
    }

    cout << count + filled << "\n";
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