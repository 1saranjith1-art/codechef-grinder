# [Maximum Ones (MXON)](https://www.codechef.com/problems/MXON)

- **Difficulty Rating**: 943
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, we are allowed to perform the operation $S[i] = \max(S[i], S[i+1])$ at most $K$ times. Each operation effectively allows a '1' to propagate one position to the left. The goal is to maximize the total number of '1's in the string after performing at most $K$ operations.

## Intuition & Mathematical Observation
The operation $S[i] = \max(S[i], S[i+1])$ implies that if $S[i+1]$ is '1', we can change $S[i]$ to '1' in a single operation. 

1. **Propagation**: A '1' at index $j$ can turn any '0' at index $i$ (where $i < j$) into a '1', provided we have enough operations. Specifically, to turn $S[i]$ into '1' using a '1' at $S[i+1]$, we use 1 operation.
2. **Greedy Strategy**: Since we want to maximize the count of '1's, we should prioritize turning '0's into '1's that are immediately adjacent to an existing '1'. By repeatedly scanning the string from left to right and performing the operation whenever $S[i] == '0'$ and $S[i+1] == '1'$, we ensure that we expand the range of '1's as efficiently as possible.
3. **Constraints**: Given $N \le 10$, a simple simulation approach is highly efficient and well within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(K \cdot N)$. In each of the $K$ operations, we iterate through the string of length $N$. Given $N, K \le 10$, this is effectively $O(1)$ per test case.
- **Space Complexity**: $O(N)$ to store the string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation S[i] = max(S[i], S[i+1]) effectively propagates a '1' from right to left.
 * Since N is very small (N <= 10), we can simulate the process greedily.
 * We look for the first '0' that has a '1' to its right and flip it.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // Perform the operation at most K times
    for (int k = 0; k < K; ++k) {
        bool changed = false;
        // Look for the first '0' that can be turned into '1' by its right neighbor
        for (int i = 0; i < N - 1; ++i) {
            if (S[i] == '0' && S[i + 1] == '1') {
                S[i] = '1';
                changed = true;
                break; // Move to the next operation
            }
        }
        // If no more '0's can be flipped, stop early
        if (!changed) break;
    }

    // Count the total number of '1's
    int count = 0;
    for (char c : S) {
        if (c == '1') count++;
    }
    cout << count << "\n";
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