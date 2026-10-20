# [Expensive Buying (BUYING7)](https://www.codechef.com/problems/BUYING7)

- **Difficulty Rating**: 635
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ items with their respective prices $C_i$, we need to select exactly $K$ items such that the total cost is maximized. In other words, we need to find the sum of the $K$ most expensive items available in the list.

## Intuition & Mathematical Observation
To maximize the sum of $K$ items, we should always pick the items with the highest prices. 
1. **Sorting**: By sorting the array of prices in descending order, the largest elements will be positioned at the beginning of the array (indices $0$ to $K-1$).
2. **Summation**: Once sorted, we simply iterate through the first $K$ elements and accumulate their sum.
3. **Data Types**: Given the constraints ($N \le 100$, $C_i \le 100$), the maximum possible sum is $10,000$. While a standard `int` is sufficient, using `long long` is a safe practice to avoid potential overflow in similar problems with larger constraints.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of items. The sorting step dominates the complexity for each test case.
- **Space Complexity**: $O(N)$ to store the prices of the items in a vector.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N items with prices C_i. We need to find the sum of the K most expensive items.
 * To do this, we can sort the array of prices in descending order and sum the first K elements.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort in descending order to easily pick the K most expensive items
    sort(C.begin(), C.end(), greater<int>());
    
    long long total_cost = 0;
    for (int i = 0; i < K; ++i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}
```