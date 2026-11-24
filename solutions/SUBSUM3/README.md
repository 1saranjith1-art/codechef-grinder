# [Subset Sum 3 (SUBSUM3)](https://www.codechef.com/problems/SUBSUM3)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, determine if there exists a non-empty subsequence whose sum is divisible by 3. In other words, we need to check if there exists a subset of the given array such that the sum of its elements $S \equiv 0 \pmod 3$.

## Intuition & Mathematical Observation
The problem asks for a subset sum divisible by 3. Since we only care about the sum modulo 3, we can observe that any integer $A_i$ can be represented as $A_i \equiv r \pmod 3$, where $r \in \{0, 1, 2\}$.

We can track the reachable remainders using Dynamic Programming:
1. Let `dp[r]` be a boolean value indicating whether a subsequence with a sum congruent to $r \pmod 3$ has been found.
2. For each element $x$ in the array:
   - It can form a new subsequence by itself: `new_rem = x % 3`.
   - It can be added to any existing subsequence sum $r$: `new_rem = (r + x) % 3`.
3. After processing all elements, if `dp[0]` is true, then a subsequence with a sum divisible by 3 exists.

**Alternative Pigeonhole Perspective:**
- If any $A_i \equiv 0 \pmod 3$, the answer is "Yes".
- If we have at least one $1$ and one $2$, their sum is $3 \equiv 0 \pmod 3$, so "Yes".
- If we have three $1$s, their sum is $3 \equiv 0 \pmod 3$, so "Yes".
- If we have three $2$s, their sum is $6 \equiv 0 \pmod 3$, so "Yes".
The DP approach naturally covers all these cases without needing explicit conditional logic.

## Complexity Analysis
- **Time Complexity**: $O(N \times K)$, where $N$ is the number of elements and $K=3$ (the modulus). Since $K$ is constant, this simplifies to **$O(N)$**.
- **Space Complexity**: **$O(1)$**, as the `dp` array size is fixed at 3 regardless of the input size $N$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists a non-empty subsequence whose sum is divisible by 3.
 * We use a boolean DP array of size 3 to track reachable remainders modulo 3.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[r] will store if a subsequence with sum % 3 == r is possible
    vector<bool> dp(3, false);

    for (int x : A) {
        int rem = x % 3;
        vector<bool> next_dp = dp;
        
        // Option 1: Start a new subsequence with this element
        next_dp[rem] = true;
        
        // Option 2: Add this element to existing subsequences
        for (int r = 0; r < 3; ++r) {
            if (dp[r]) {
                next_dp[(r + rem) % 3] = true;
            }
        }
        dp = next_dp;
    }

    if (dp[0]) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
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