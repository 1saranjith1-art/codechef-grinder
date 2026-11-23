# [Skip one (SKIPONE)](https://www.codechef.com/problems/SKIPONE)

- **Difficulty Rating**: 1182
- **Solved in**: 3 attempt(s)

## Problem Summary
We are given an array $A$ of $N$ items, each with a specific cost. We want to purchase the first $m$ items (from index $0$ to $m-1$). The rule for purchasing is that we can skip exactly one item from this set of $m$ items. The total cost incurred is the sum of the costs of the $m-1$ items we actually buy. To minimize the cost, we should always skip the most expensive item among the first $m$. Thus, the cost is defined as:
$$\text{Cost} = \left( \sum_{i=0}^{m-1} A[i] \right) - \max(A[0], \dots, A[m-1])$$
Given a budget $K$, we need to find the maximum number of items $m$ we can purchase such that the cost is $\le K$.

## Intuition & Mathematical Observation
1. **Monotonicity**: As we increase the number of items $m$, the total sum increases and the maximum value either stays the same or increases. Consequently, the cost function $(\sum - \max)$ is monotonically non-decreasing. This property allows us to use **Binary Search** on the answer $m$.
2. **Preprocessing**: To check if a specific $m$ is valid in $O(1)$ time, we precompute:
   - `prefix_sum`: To calculate the sum of the first $m$ elements instantly.
   - `prefix_max`: To find the maximum of the first $m$ elements instantly.
3. **Binary Search Range**: The number of items $m$ can range from $0$ to $N$. We search for the largest $m$ in the range $[0, N]$ that satisfies the condition `(sum - max) <= K`.

## Complexity Analysis
- **Time Complexity**: $O(N)$ for preprocessing the prefix arrays and $O(\log N)$ for the binary search. Total time complexity is **$O(N)$** per test case.
- **Space Complexity**: **$O(N)$** to store the input array and the prefix sum/max arrays.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * We need to buy items 1 to m.
 * Cost = (Sum of A[0...m-1]) - (Max of A[0...m-1]).
 * We need Cost <= K.
 * Since the cost function is monotonically non-decreasing with m,
 * we can binary search for the maximum m.
 */

bool can_buy(int m, long long K, const vector<long long>& prefix_sum, const vector<int>& prefix_max) {
    if (m == 0) return true;
    long long total_sum = prefix_sum[m];
    long long max_val = prefix_max[m];
    return (total_sum - max_val) <= K;
}

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N);
    vector<long long> prefix_sum(N + 1, 0);
    vector<int> prefix_max(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        prefix_sum[i + 1] = prefix_sum[i] + A[i];
        prefix_max[i + 1] = max((long long)prefix_max[i], A[i]);
    }

    int low = 0, high = N, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (can_buy(mid, K, prefix_sum, prefix_max)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << ans << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```