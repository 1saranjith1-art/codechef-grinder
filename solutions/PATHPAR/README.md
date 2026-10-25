# [Path Parity (PATHPAR)](https://www.codechef.com/problems/PATHPAR)

- **Difficulty Rating**: 1098
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an $N \times N$ grid where the cell at row $i$ and column $j$ contains the value $A_{i,j} = i + N(j-1)$. We need to determine if there exists a path from $(1, 1)$ to $(N, N)$ using only right and down moves such that the sum of the values of the cells in the path has a parity equal to $K$ (where $K=0$ for even and $K=1$ for odd).

## Intuition & Mathematical Observation
Any path from $(1, 1)$ to $(N, N)$ consists of exactly $2N-1$ cells. Let the path be a sequence of cells $(r_0, c_0), (r_1, c_1), \dots, (r_{2N-2}, c_{2N-2})$. The sum of the values is:
$$S = \sum_{k=0}^{2N-2} (r_k + N(c_k - 1))$$

**Case 1: $N$ is even**
If $N$ is even, $N \equiv 0 \pmod 2$. The expression simplifies to:
$$S \equiv \sum r_k \pmod 2$$
Since we can choose different paths that change the sum of row indices, both even and odd sums are achievable. Thus, for any $K \in \{0, 1\}$, the answer is always **YES**.

**Case 2: $N$ is odd**
If $N$ is odd, $N \equiv 1 \pmod 2$. The expression simplifies to:
$$S \equiv \sum r_k + \sum (c_k - 1) \pmod 2$$
Since $c_k - 1$ is the number of steps taken right, and $r_k - 1$ is the number of steps taken down, the total sum of indices is invariant across all paths. Specifically, for odd $N$, the parity of the path sum is always odd ($1$). Therefore, if $K=1$, the answer is **YES**; if $K=0$, the answer is **NO**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a parity check on $N$.
- **Space Complexity**: $O(1)$, as we use a constant amount of extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is defined as A_{i, j} = i + N*(j-1).
 * Any path from (1, 1) to (N, N) consists of exactly (N-1) steps down and (N-1) steps right.
 * 
 * If N is even:
 *   The parity of the path sum can be either 0 or 1.
 *   Therefore, both K=0 and K=1 are possible.
 * 
 * If N is odd:
 *   The parity of the path sum is fixed to 1 (odd).
 *   Therefore, only K=1 is possible.
 */

void solve() {
    long long N;
    int K;
    cin >> N >> K;

    if (N % 2 != 0) {
        // If N is odd, the parity of the path sum is always odd (1).
        if (K == 1) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    } else {
        // If N is even, both parities are possible.
        cout << "YES" << "\n";
    }
}

int main() {
    // Optimize I/O operations
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