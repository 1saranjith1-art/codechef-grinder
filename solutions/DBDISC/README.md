# [Double Discount (DBDISC)](https://www.codechef.com/problems/DBDISC)

- **Difficulty Rating**: 994
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ items, each with a cost $A_i$ and a tastiness value $B_i$. We need to select exactly two distinct items $(i, j)$ such that their combined cost after applying a specific discount rule is at most $K$. The discount rule states that for the two selected items, the more expensive item $M = \max(A_i, A_j)$ receives a discount of $\min(\lfloor M/2 \rfloor, 100)$. The goal is to maximize the sum of the tastiness values $B_i + B_j$ for all valid pairs. If no such pair exists, the answer is 0.

## Intuition & Mathematical Observation
1. **Brute Force Feasibility**: Given the constraints $N \le 100$, an $O(N^2)$ approach is highly efficient. With $N=100$, the number of pairs is $\frac{N(N-1)}{2} \approx 5,000$, which easily fits within the time limit for multiple test cases.
2. **Discount Logic**: For any pair $(i, j)$, we identify the maximum cost $M$ and the minimum cost $m$. The final cost is calculated as:
   $$\text{Final Cost} = m + (M - \min(\lfloor M/2 \rfloor, 100))$$
3. **Maximization**: We iterate through every possible pair $(i, j)$ where $i < j$. For each pair, we calculate the final cost. If the cost is $\le K$, we update our global maximum tastiness variable with $B_i + B_j$.

## Complexity Analysis
- **Time Complexity**: $O(T \times N^2)$, where $T$ is the number of test cases and $N$ is the number of items. Given $N \le 100$, this results in approximately $10^6$ operations per test suite, which is well within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to select exactly two items (i, j) where i != j.
 * Let the costs be A[i] and A[j].
 * Let the more expensive item be M = max(A[i], A[j]) and the other be m = min(A[i], A[j]).
 * The discount on M is min(M/2, 100).
 * The final cost is m + (M - min(M/2, 100)).
 * We need to maximize B[i] + B[j] such that final cost <= K.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_tastiness = 0;
    bool possible = false;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long cost1 = A[i];
            long long cost2 = A[j];
            
            long long M = max(cost1, cost2);
            long long m = min(cost1, cost2);
            
            // Discount is min(50% of M, 100)
            long long discount = min(M / 2, 100LL);
            long long final_cost = m + (M - discount);
            
            if (final_cost <= K) {
                possible = true;
                max_tastiness = max(max_tastiness, B[i] + B[j]);
            }
        }
    }

    if (!possible) {
        cout << 0 << "\n";
    } else {
        cout << max_tastiness << "\n";
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