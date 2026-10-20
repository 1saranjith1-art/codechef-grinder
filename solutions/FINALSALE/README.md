# [Sale (FINALSALE)](https://www.codechef.com/problems/FINALSALE)

- **Difficulty Rating**: 1180
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has projected sales for $N$ days, represented by an array $A = [A_1, A_2, \dots, A_N]$. If Chef decides to close the shop on day $k$ (where $1 \le k \le N$), the total sales are calculated as the sum of all sales from day 1 to $k-1$, plus double the sales of day $k$. The goal is to choose an index $k$ that maximizes this total value.

## Intuition & Mathematical Observation
The formula for the total sales if the shop closes on day $k$ is:
$$\text{Total} = \left( \sum_{i=1}^{k-1} A_i \right) + 2 \cdot A_k$$

We can rewrite this expression to make it easier to compute iteratively:
$$\text{Total} = \left( \sum_{i=1}^{k} A_i \right) + A_k$$

By maintaining a running prefix sum of the array, we can calculate the potential total for every possible closing day $k$ in a single pass. Since $N$ can be up to $3 \times 10^5$ and $A_i$ up to $10^9$, the total sum will exceed the capacity of a 32-bit integer. Therefore, we must use `long long` to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to compute the prefix sum and the maximum value.
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(1)$ by processing elements on the fly, but $O(N)$ is well within limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize (A_1 + ... + A_{k-1}) + 2 * A_k, we use the equivalent form:
 * (PrefixSum[k]) + A_k.
 * We iterate through the array, maintaining the running prefix sum,
 * and track the maximum value encountered.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_prefix_sum = 0;
    long long max_sales = -2e18; // Initialize with a very small value
    
    for (int i = 0; i < N; ++i) {
        current_prefix_sum += A[i];
        // Total sales if we close on day i+1 (0-indexed i)
        // is (Sum of A[0...i]) + A[i]
        long long current_total = current_prefix_sum + A[i];
        
        if (i == 0) {
            max_sales = current_total;
        } else {
            max_sales = max(max_sales, current_total);
        }
    }
    
    cout << max_sales << "\n";
}

int main() {
    // Fast I/O for performance
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