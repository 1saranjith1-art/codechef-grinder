# [Minimum XOR (MINMXOR)](https://www.codechef.com/problems/MINMXOR)

- **Difficulty Rating**: 1154
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we are allowed to remove at most one element from the array. The goal is to minimize the XOR sum of the remaining elements. Specifically, we need to find the minimum value among the XOR sum of the entire array and the XOR sums obtained by removing exactly one element $A_i$ for each $i \in [1, N]$.

## Intuition & Mathematical Observation
Let $S$ be the XOR sum of all elements in the array: $S = A_1 \oplus A_2 \oplus \dots \oplus A_N$.

1. **Case 1: No element is removed.** The XOR sum is simply $S$.
2. **Case 2: One element $A_i$ is removed.** The new XOR sum is $S \oplus A_i$. This is because the XOR operation is its own inverse ($x \oplus x = 0$). Removing $A_i$ from the total XOR sum is equivalent to XORing the total sum with $A_i$.

To find the minimum possible XOR sum, we calculate $S$ first, then iterate through the array to compute $S \oplus A_i$ for every $i$, keeping track of the minimum value encountered.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. We perform one pass to calculate the total XOR sum and a second pass to evaluate the result of removing each element. Given that the sum of $N$ over all test cases is $3 \times 10^5$, this approach is highly efficient.
- **Space Complexity**: $O(N)$ to store the input array. (Note: This could be optimized to $O(1)$ if we store the XOR sum and the array elements, but $O(N)$ is well within memory limits).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be the XOR sum of all elements A_1, A_2, ..., A_N.
 * If we remove no element, the XOR sum is S.
 * If we remove an element A_i, the new XOR sum is S ^ A_i.
 * We want to find min(S, min_{i=1 to N} (S ^ A_i)).
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    int total_xor = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_xor ^= A[i];
    }

    // Option 1: Don't remove any element
    int min_xor = total_xor;

    // Option 2: Remove exactly one element A[i]
    // The new XOR sum will be total_xor ^ A[i]
    for (int i = 0; i < N; ++i) {
        int current_xor = total_xor ^ A[i];
        if (current_xor < min_xor) {
            min_xor = current_xor;
        }
    }

    cout << min_xor << "\n";
}

int main() {
    // Fast I/O for performance
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