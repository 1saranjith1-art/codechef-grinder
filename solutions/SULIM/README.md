# [Sugar Limit (SULIM)](https://www.codechef.com/problems/SULIM)

- **Difficulty Rating**: 1111
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ snacks, each with a tastiness value $A_i$ and a sugar content $B_i$. Chef chooses a sugar threshold $L \ge 0$. For a chosen $L$, Chef can consume any subset of snacks where the sugar content $B_i \le L$. The goal is to maximize the total satisfaction, defined as the sum of $A_i$ for all chosen snacks minus the threshold $L$ (i.e., $\sum A_i - L$).

## Intuition & Mathematical Observation
1. **Greedy Choice**: For a fixed threshold $L$, to maximize the satisfaction $\sum A_i - L$, Chef should greedily select every snack that satisfies $B_i \le L$ **and** has a positive tastiness $A_i > 0$. If $A_i \le 0$, including it would only decrease or keep the sum the same, so we ignore it.
2. **Search Space**: The problem states $1 \le B_i \le 100$. Since the threshold $L$ only affects which snacks are available, and the availability only changes when $L$ crosses one of the $B_i$ values, we only need to test $L$ in the range $[0, 100]$.
3. **Optimization**: By iterating through every possible integer value of $L$ from $0$ to $100$, we can calculate the potential satisfaction for each $L$ and keep track of the maximum value found. Since the constraints on $N$ and $B_i$ are small, this brute-force approach over $L$ is highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times L_{max} \times N)$, where $T$ is the number of test cases, $L_{max} = 100$ (the maximum possible sugar content), and $N$ is the number of snacks. Given the constraints, this is roughly $100 \times N$ operations per test case, which comfortably fits within the time limit.
- **Space Complexity**: $O(N)$ to store the arrays $A$ and $B$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a threshold L >= 0.
 * For a fixed L, Chef can eat any subset of snacks where B_i <= L.
 * To maximize (Sum of A_i - L), for a fixed L, Chef should pick all snacks 
 * where B_i <= L AND A_i > 0.
 * If the sum of such A_i is S_L, the satisfaction is S_L - L.
 * Since L must be a non-negative integer, and the constraints on B_i are 
 * small (1 <= B_i <= 100), we can iterate through all possible values of L.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int i = 0; i < N; ++i) cin >> B[i];

    long long max_satisfaction = 0; // Choosing L=0 and eating nothing gives 0-0 = 0

    // Possible values for L are 0 to 100 (based on constraints B_i <= 100)
    for (int L = 0; L <= 100; ++L) {
        long long current_sum = 0;
        for (int i = 0; i < N; ++i) {
            // If snack satisfies threshold and has positive tastiness, eat it
            if (B[i] <= L && A[i] > 0) {
                current_sum += A[i];
            }
        }
        max_satisfaction = max(max_satisfaction, current_sum - L);
    }

    cout << max_satisfaction << "\n";
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