# [Water Moving (Max) (WATERMOVE2)](https://www.codechef.com/problems/WATERMOVE2)

- **Difficulty Rating**: 934
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ cups, each containing a certain amount of water $A_i$. In one operation, you can choose any two cups $i$ and $j$ and move all the water from cup $i$ into cup $j$. This operation effectively merges the contents of two cups and leaves cup $i$ empty. You are required to perform exactly $K$ operations. The goal is to maximize the amount of water in the single cup that contains the most water after all $K$ operations are completed.

## Intuition & Mathematical Observation
To maximize the amount of water in a single cup, we should greedily consolidate the largest available amounts of water into the largest starting cup.

1.  **The Greedy Strategy**: Since each operation allows us to move the entire contents of one cup into another, we should always pick the largest available cup as our "target" and add the next largest available cups to it.
2.  **Case 1 ($K \ge N-1$)**: If we have enough operations to merge every single cup into one, the maximum possible value is simply the sum of all water in all cups. Since we start with $N$ cups, it takes $N-1$ operations to merge everything into one. If $K$ is greater than or equal to this, we can achieve the total sum.
3.  **Case 2 ($K < N-1$)**: If we have fewer than $N-1$ operations, we should perform $K$ merges. To maximize the result, we sort the array in descending order. We start with the largest value ($A[0]$) and add the next $K$ largest values ($A[1]$ through $A[K]$) to it. This ensures that the target cup accumulates the largest possible values available.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case, dominated by the sorting step. The subsequent summation takes $O(K)$ or $O(N)$ time, which is well within the limits.
- **Space Complexity**: $O(N)$ to store the amounts of water in the cups.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cups with amounts A_i.
 * In one operation, we move all water from cup i to cup j.
 * This effectively merges the contents of two cups.
 * We need to perform exactly K operations.
 * 
 * Strategy:
 * Sort the array A in descending order.
 * 1. If K >= N-1, we can merge all water into one cup. The result is the sum of all A_i.
 * 2. If K < N-1, we take the largest cup (A[0]) and add the next K largest 
 *    available cups to it.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort in descending order to easily pick the largest values
    sort(A.rbegin(), A.rend());

    // If K >= N-1, we can merge all cups into one.
    if (K >= N - 1) {
        long long sum = 0;
        for (long long x : A) {
            sum += x;
        }
        cout << sum << "\n";
    } else {
        // We perform K operations. Each operation adds one cup to the largest cup.
        // We start with A[0] and add A[1], A[2], ..., A[K].
        long long max_val = A[0];
        for (int i = 1; i <= K; ++i) {
            max_val += A[i];
        }
        cout << max_val << "\n";
    }
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