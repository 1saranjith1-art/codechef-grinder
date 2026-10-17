# [Convert to permutation (PERMUTATION)](https://www.codechef.com/problems/PERMUTATION)

- **Difficulty Rating**: 1197
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to transform it into a permutation of $\{1, 2, \dots, N\}$ using only increment operations. Each increment operation increases an element by 1. We need to find the minimum number of operations required to achieve this, or determine if it is impossible.

## Intuition & Mathematical Observation
1. **Sorting is Key**: To minimize the total number of operations, we should sort the array $A$ in non-decreasing order. By matching the smallest available elements in $A$ to the smallest values in the target set $\{1, 2, \dots, N\}$, we ensure that we don't "waste" larger numbers on smaller targets, which would be impossible to satisfy given the constraint that we can only increment.
2. **Feasibility Check**: After sorting, the $i$-th element (0-indexed) $A[i]$ must be transformed into the value $(i+1)$. Since we can only increase values, if $A[i] > (i+1)$, it is impossible to reach the target value. In this case, we output $-1$.
3. **Calculating Cost**: If $A[i] \le (i+1)$ for all $i$, the cost to transform $A[i]$ to $(i+1)$ is exactly $(i+1) - A[i]$. The total cost is the sum of these differences for all $i$ from $0$ to $N-1$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$, making the overall complexity dominated by the sort.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N and we want to transform it into a permutation
 * of {1, 2, ..., N} using only increment operations.
 * 
 * 1. Since we can only increase elements, if an element A[i] is already greater 
 *    than N, it is impossible to transform it into any value in {1, ..., N}.
 *    Thus, if any A[i] > N, output -1.
 * 
 * 2. To minimize the total number of operations, we should sort the array A.
 *    Let the sorted array be A'. We want to map each A'[i] to a unique value 
 *    in {1, 2, ..., N}.
 * 
 * 3. After sorting, the optimal strategy is to match the smallest elements 
 *    of A' to the smallest available values in the target permutation {1, 2, ..., N}.
 *    Specifically, if A'[i] > (i + 1), it is impossible to reach (i + 1) 
 *    because we can only increase values.
 * 
 * 4. If A'[i] <= (i + 1), the cost to transform A'[i] to (i + 1) is (i + 1) - A'[i].
 *    Summing these costs gives the minimum operations.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    long long total_ops = 0;
    for (int i = 0; i < N; ++i) {
        // Target value for the i-th smallest element is (i + 1)
        long long target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it, so it's impossible.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Otherwise, we increase A[i] to target
        total_ops += (target - A[i]);
    }

    cout << total_ops << "\n";
}

int main() {
    // Fast I/O
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