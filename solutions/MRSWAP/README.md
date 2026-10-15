# [Mirror Swap (MRSWAP)](https://www.codechef.com/problems/MRSWAP)

- **Difficulty Rating**: 667
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array $A$ of size $2N$. You are allowed to swap elements at index $i$ and index $2N - i + 1$ (using 1-based indexing). The goal is to maximize the sum of the elements in the first half of the array (indices $1$ to $N$) after performing any number of these swaps.

## Intuition & Mathematical Observation
The problem defines a set of independent pairs: $(A[1], A[2N]), (A[2], A[2N-1]), \dots, (A[N], A[N+1])$. 

For each pair $(A[i], A[2N - i + 1])$, we have two choices:
1. Keep the elements as they are.
2. Swap them.

Since we want to maximize the sum of the first $N$ elements, for every pair, we should simply choose the larger of the two values to occupy the position in the first half. Mathematically, the maximum sum is obtained by:
$$\text{Total Sum} = \sum_{i=0}^{N-1} \max(A[i], A[2N - 1 - i])$$
(using 0-based indexing where the pairs are $i$ and $2N - 1 - i$).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the first half of the array exactly once to compare and sum the pairs.
- **Space Complexity**: $O(N)$ to store the input array of size $2N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (using 1-based indexing).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which one 
 * goes into the first half (indices 1 to N) and which one goes into the second half.
 * To maximize the sum of the first half, for each pair (A[i], A[2N + 1 - i]),
 * we should pick the maximum of the two values to be in the first half.
 * 
 * The pairs are:
 * (A[1], A[2N]), (A[2], A[2N-1]), ..., (A[N], A[N+1])
 * 
 * Total sum = sum_{i=1 to N} max(A[i], A[2N + 1 - i])
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    for (int i = 0; i < N; ++i) {
        // Pair index i with index (2N - 1 - i)
        // A[i] is the element at index i (0-indexed)
        // A[2N - 1 - i] is its mirror element
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
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