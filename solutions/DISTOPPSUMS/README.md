# [Distinct Opposite Sums (DISTOPPSUMS)](https://www.codechef.com/problems/DISTOPPSUMS)

- **Difficulty Rating**: 1135
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an even integer $N$, we need to construct a permutation $P$ of the numbers $\{1, 2, \dots, N\}$ such that all sums of opposite elements $P[i] + P[N+1-i]$ (for $1 \le i \le N/2$) are distinct.

## Intuition & Mathematical Observation
To ensure that the sums $P[i] + P[N+1-i]$ are distinct, we can observe the properties of the sequence $1, 2, \dots, N$. 

If we split the numbers into two halves:
1. The first half: $1, 2, \dots, N/2$
2. The second half: $N, N-1, \dots, N/2 + 1$

By arranging the permutation as $P = [1, 2, \dots, N/2, N, N-1, \dots, N/2 + 1]$, we pair the $k$-th element with the $(N-k+1)$-th element.
Let's analyze the sum for the $k$-th pair (where $1 \le k \le N/2$):
- The $k$-th element is $k$.
- The $(N-k+1)$-th element is $N - (k - 1) = N - k + 1$.
- The sum is $k + (N - k + 1) = N + 1$.

Wait, the construction above results in the same sum $N+1$ for all pairs. To make them **distinct**, we need a different approach. Let's adjust the pairing:
If we use $P = [1, 2, \dots, N/2, N, N-1, \dots, N/2 + 1]$, the pairs are:
- $(1, N/2+1) \to \text{sum } N/2 + 2$
- $(2, N/2+2) \to \text{sum } N/2 + 4$
- $(k, N/2+k) \to \text{sum } 2k + N/2$

Since $2k + N/2$ is strictly increasing with $k$, all sums are guaranteed to be distinct.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to fill and print the values.
- **Space Complexity**: $O(N)$ to store the permutation array.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We construct the permutation by placing 1 to N/2 in the first half
 * and N down to N/2 + 1 in the second half.
 * This results in pairs (1, N/2+1), (2, N/2+2), ..., (N/2, N).
 * The sums are (N/2 + 2), (N/2 + 4), ..., (3N/2), 
 * which are all distinct.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> P(N);
    
    // Fill first half with 1 to N/2
    for (int i = 0; i < N / 2; ++i) {
        P[i] = i + 1;
    }
    // Fill second half with N down to N/2 + 1
    for (int i = N / 2; i < N; ++i) {
        P[i] = N - (i - N / 2);
    }
    
    for (int i = 0; i < N; ++i) {
        cout << P[i] << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
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