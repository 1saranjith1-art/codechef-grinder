# [Chococut (CHOCUT)](https://www.codechef.com/problems/CHOCUT)

- **Difficulty Rating**: 1003
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice has a chocolate bar of size $N \times M$. She can choose to either keep the bar as is or make exactly one horizontal or vertical cut to split it into two smaller rectangular pieces. After the cut, she gives one piece to Bob and keeps the other. The constraint is that Bob must receive at least $K$ squares of chocolate. The goal is to maximize the number of squares Alice keeps for herself.

## Intuition & Mathematical Observation
Since the constraints on $N$ and $M$ are very small ($N, M \le 10$), we can use a brute-force approach to evaluate every possible cut:

1.  **No Cut**: If $K=0$, Alice can keep the entire $N \times M$ bar.
2.  **Horizontal Cuts**: We iterate through all possible horizontal lines $i$ (where $1 \le i < N$). This splits the bar into two pieces of size $(i \times M)$ and $((N-i) \times M)$. If a piece satisfies the condition $\ge K$, we consider the other piece as a candidate for Alice's share.
3.  **Vertical Cuts**: Similarly, we iterate through all possible vertical lines $j$ (where $1 \le j < M$). This splits the bar into two pieces of size $(N \times j)$ and $(N \times (M-j))$. Again, if a piece satisfies the condition $\ge K$, we consider the other piece as a candidate.
4.  **Giving the whole bar**: If the entire bar is given to Bob (i.e., $N \times M \ge K$), Alice is left with $0$.

By calculating the remaining area for every valid cut that satisfies Bob's requirement, we can track the maximum area Alice can keep.

## Complexity Analysis
- **Time Complexity**: $O(N + M)$ per test case. Given $N, M \le 10$, this is effectively $O(1)$ per test case, making it extremely efficient.
- **Space Complexity**: $O(1)$, as we only use a few variables to store dimensions and the maximum area.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We iterate through all possible horizontal and vertical cuts.
 * For each cut, we check if one of the resulting pieces satisfies 
 * Bob's requirement (>= K). If it does, we update the maximum 
 * area Alice can keep with the size of the other piece.
 */

void solve() {
    long long N, M, K;
    cin >> N >> M >> K;

    long long max_alice = 0;

    // Case 0: No cut
    // If Bob needs 0, Alice keeps everything.
    if (K == 0) {
        cout << N * M << "\n";
        return;
    }

    // Case 1: Horizontal cuts
    // Cut N into i and (N-i) for i from 1 to N-1
    for (int i = 1; i < N; ++i) {
        long long p1 = (long long)i * M;
        long long p2 = (long long)(N - i) * M;
        
        if (p1 >= K) max_alice = max(max_alice, p2);
        if (p2 >= K) max_alice = max(max_alice, p1);
    }

    // Case 2: Vertical cuts
    // Cut M into j and (M-j) for j from 1 to M-1
    for (int j = 1; j < M; ++j) {
        long long p1 = (long long)N * j;
        long long p2 = (long long)N * (M - j);
        
        if (p1 >= K) max_alice = max(max_alice, p2);
        if (p2 >= K) max_alice = max(max_alice, p1);
    }

    // Case 3: Giving the whole bar to Bob
    if (N * M >= K) {
        max_alice = max(max_alice, 0LL);
    }

    cout << max_alice << "\n";
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