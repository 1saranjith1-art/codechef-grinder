# [Not Divisible (NOTDIVISIBLE)](https://www.codechef.com/problems/NOTDIVISIBLE)

- **Difficulty Rating**: 1363
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an integer $N$, we need to construct an array $A$ of length $N$ such that for every subarray $A[i \dots j]$ (where $1 \le i \le j \le N$), the sum of the elements in the subarray is **not** divisible by the length of the subarray ($j - i + 1$). The elements of the array must be between $1$ and $300$.

## Intuition & Mathematical Observation
The condition states that for any subarray of length $L$, the sum $S$ must satisfy $S \not\equiv 0 \pmod L$.

A simple approach is to use values that are large enough to avoid trivial divisibility but small enough to stay within the constraint ($A_i \le 300$). 

Consider the sequence alternating between $200$ and $201$:
- If we set $A_i = 200$ for even indices and $A_i = 201$ for odd indices (or vice versa), we create a sequence where the average value is $200.5$.
- For any subarray of length $L$, the sum will be approximately $L \times 200.5$. 
- Specifically, if $L$ is even, the sum will be $L/2 \times (200 + 201) = L/2 \times 401$. For this to be divisible by $L$, $401$ would need to be divisible by $2$, which is impossible.
- If $L$ is odd, the sum will be $(L-1)/2 \times 401 + (\text{either } 200 \text{ or } 201)$. This construction effectively prevents the sum from being a multiple of $L$ because the alternating values break the divisibility property for all possible subarray lengths.

Since $200$ and $201$ are well within the limit of $300$, this construction is valid for all $N \le 500$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array once to print the values.
- **Space Complexity**: $O(1)$, as we do not store the array and print values on the fly.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct an array A of length N such that for all 1 <= i < j <= N,
 * the sum of the subarray A[i...j] is not divisible by its length (j - i + 1).
 * 
 * By alternating between 200 and 201, we ensure that the sum of any subarray
 * is not a multiple of its length. This works because 200 and 201 are 
 * sufficiently large and their alternating pattern prevents the sum from 
 * aligning with the length L.
 */

void solve() {
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        // Alternate between 200 and 201
        if (i % 2 == 0) {
            cout << 200 << (i == N - 1 ? "" : " ");
        } else {
            cout << 201 << (i == N - 1 ? "" : " ");
        }
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