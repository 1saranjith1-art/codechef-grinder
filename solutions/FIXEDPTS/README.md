# [Fixed Points (FIXEDPTS)](https://www.codechef.com/problems/FIXEDPTS)

- **Difficulty Rating**: 884
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a permutation of length $N$, we need to determine if it is possible to construct a permutation such that exactly $K$ elements are "fixed points." A fixed point is defined as an index $i$ such that $P_i = i$ (using 1-based indexing).

## Intuition & Mathematical Observation
To solve this, we consider the remaining $M = N - K$ elements that are **not** fixed points. These $M$ elements must form a **derangement** (a permutation where no element appears in its original position).

1. **Case $M = 0$ ($K = N$):** All elements are fixed points. This is possible (the identity permutation).
2. **Case $M = 1$ ($K = N - 1$):** We have $N-1$ fixed points and exactly one element left. By definition, if $N-1$ elements are in their correct positions, the final remaining element must also be in its correct position. Thus, it is impossible to have exactly $N-1$ fixed points.
3. **Case $M \ge 2$:** We can always rearrange the remaining $M$ elements such that none of them are in their original positions (e.g., by performing a cyclic shift). Therefore, any $K$ such that $K \le N - 2$ is possible.

**Conclusion:** The only impossible case is when $K = N - 1$. For all other values of $K$ ($0 \le K \le N$), a valid permutation exists.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a single comparison. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points, we are left with (N - K) indices
 *    that must NOT be fixed points.
 * 2. Let M = N - K. We need to check if there exists a derangement of M elements.
 * 3. A derangement of M elements exists if and only if M != 1.
 *    - If M = 0, we have 0 elements left, which is a valid derangement (0 fixed points).
 *    - If M = 1, we have 1 element left, which must be a fixed point (P_i = i),
 *      so it is impossible to have 0 fixed points among these remaining elements.
 *    - If M >= 2, we can always form a derangement (e.g., swapping elements).
 * 
 * Therefore, the condition is:
 * - If K == N - 1, it is impossible (because if N-1 elements are fixed, the last one must be fixed too).
 * - Otherwise, it is always possible.
 */

void solve() {
    int N, K;
    cin >> N >> K;

    // The only impossible case is when exactly one element is left to be non-fixed.
    if (K == N - 1) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
    }
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