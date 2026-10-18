# [Anti Adjacent Swaps (ANADSW)](https://www.codechef.com/problems/ANADSW)

- **Difficulty Rating**: 1306
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array $A$ of $N$ distinct integers, we are allowed to swap any two elements $A[i]$ and $A[j]$ if and only if $|i - j| > 1$. That is, we cannot swap adjacent elements. The goal is to determine if the array can be sorted in non-decreasing order using any number of these allowed swaps.

## Intuition & Mathematical Observation
The problem boils down to understanding the connectivity of the indices under the allowed swap operation:

1.  **$N = 1$**: The array is already sorted. Output: `YES`.
2.  **$N = 2$**: The only indices are 0 and 1. Since $|0 - 1| = 1$, no swaps are possible. The array is sortable only if it is already sorted.
3.  **$N = 3$**: The indices are $\{0, 1, 2\}$. We can swap index 0 and 2 ($|0 - 2| = 2 > 1$). Index 1 cannot be swapped with anything. Therefore, the element at $A[1]$ must already be in its correct sorted position (the median of the three elements). If $A[1]$ is the median, we can swap $A[0]$ and $A[2]$ if necessary to place the smaller element at index 0 and the larger at index 2.
4.  **$N \ge 4$**: With four or more elements, the graph of possible swaps becomes connected. We can move any element to any position using intermediate swaps. For example, to swap adjacent elements $i$ and $i+1$, we can use a third index $k$ (where $|i-k|>1$ and $|i+1-k|>1$) to perform a series of swaps. Thus, any permutation can be transformed into a sorted array. Output: `YES`.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ for the $N=3$ case (due to sorting to find the median), and $O(1)$ for other cases. Overall, the complexity per test case is $O(N \log N)$ or $O(N)$ depending on implementation.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - N=1: Always sorted.
 * - N=2: Can only swap if |i-j| > 1. Impossible. Only sorted if A[0] <= A[1].
 * - N=3: Can swap (0, 2). Index 1 is isolated. A[1] must be the median of the three elements.
 * - N>=4: Can swap any two elements using an intermediate index. Always sortable.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    if (N == 1) {
        cout << "YES" << "\n";
    } else if (N == 2) {
        if (A[0] <= A[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else if (N == 3) {
        vector<int> B = A;
        sort(B.begin(), B.end());
        // In N=3, index 1 cannot move. It must be the median.
        if (A[1] == B[1]) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    } else {
        // For N >= 4, the swap graph is connected.
        cout << "YES" << "\n";
    }
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