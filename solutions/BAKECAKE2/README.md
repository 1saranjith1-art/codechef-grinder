# [Chef Bakes Cake 2 (BAKECAKE2)](https://www.codechef.com/problems/BAKECAKE2)

- **Difficulty Rating**: 612
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef wants to bake a cake that requires $N$ different ingredients. For each ingredient $i$, the recipe requires $A_i$ amount, but Chef currently has $B_i$ amount in his pantry. If the amount Chef has is less than what is required, he must purchase the difference. The goal is to calculate the total amount of ingredients Chef needs to buy.

## Intuition & Mathematical Observation
For each ingredient $i$, we compare the required amount $A_i$ with the available amount $B_i$:
1. If $A_i > B_i$, Chef is short by $(A_i - B_i)$ units, which he must purchase.
2. If $A_i \le B_i$, Chef already has enough (or more than enough) of the ingredient, so he needs to purchase $0$ units.

Mathematically, the amount to buy for each ingredient is $\max(0, A_i - B_i)$. The total amount to purchase is the summation of these values across all $N$ ingredients:
$$\text{Total Cost} = \sum_{i=1}^{N} \max(0, A_i - B_i)$$

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of ingredients. Given the constraints ($T, N \le 100$), the total operations are approximately $10^4$, which easily fits within the time limit.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$. This can be optimized to $O(1)$ by processing the input on the fly, but $O(N)$ is well within memory limits.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * For each ingredient i, we need A_i amount and we have B_i amount.
 * If A_i > B_i, we need to buy (A_i - B_i) amount.
 * If A_i <= B_i, we have enough, so we buy 0.
 * Total cost = sum of max(0, A_i - B_i) for all i from 1 to N.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            total_cost += (long long)(a[i] - b[i]);
        }
    }
    cout << total_cost << "\n";
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