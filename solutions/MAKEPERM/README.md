# [Make Permutation (MAKEPERM)](https://www.codechef.com/problems/MAKEPERM)

- **Difficulty Rating**: 1200
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of size $N$, we need to determine if it is possible to create an array $B$ of non-negative integers such that $C_i = A_i + B_i$ forms a permutation of the numbers from $1$ to $N$. Since $B_i \ge 0$, the condition $C_i \ge A_i$ must hold for all $i$.

## Intuition & Mathematical Observation
To form a permutation of $1$ to $N$, we need to assign each $A_i$ to a unique value $v \in \{1, 2, \dots, N\}$ such that $A_i \le v$.

1. **Sorting**: If we sort the array $A$ in non-decreasing order ($A_0 \le A_1 \le \dots \le A_{N-1}$), we can greedily attempt to match the smallest elements of $A$ with the smallest available values in the permutation set $\{1, 2, \dots, N\}$.
2. **The Condition**: After sorting, the $i$-th element of $A$ (using 0-based indexing) must be able to map to at least the value $(i+1)$. If $A_i > i+1$, it is impossible to satisfy the condition because even if we assigned the smallest possible values to the previous elements, $A_i$ would still be forced to map to a value smaller than itself, which violates $B_i \ge 0$.
3. **Sufficiency**: If $A_i \le i+1$ for all $i$, we can simply set $C_i = i+1$ and $B_i = (i+1) - A_i$. Since $A_i \le i+1$, $B_i$ will always be $\ge 0$, satisfying the problem constraints.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan takes $O(N)$. Thus, the total time complexity per test case is $O(N \log N)$.
- **Space Complexity**: $O(N)$ to store the input array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We need to find if there exists an array B 
 * of non-negative integers such that C_i = A_i + B_i forms a permutation of 1 to N.
 * 
 * Since B_i >= 0, it implies C_i >= A_i.
 * For C to be a permutation of 1 to N, every value from 1 to N must appear exactly once.
 * 
 * Let's sort the array A in non-decreasing order.
 * If we sort A, we have A_1 <= A_2 <= ... <= A_N.
 * To satisfy the condition, we need to map these A_i values to the set {1, 2, ..., N}
 * such that for each pair (A_i, C_i), A_i <= C_i.
 * 
 * If we sort A, the best strategy is to check if the i-th smallest element of A 
 * can be mapped to the i-th smallest value of the permutation (which is i+1).
 * If this condition holds for all i, then we can always find non-negative B_i 
 * such that C_i = i + 1.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    // Sort A to check the condition A[i] <= i+1
    sort(A.begin(), A.end());
    
    bool possible = true;
    for (int i = 0; i < N; ++i) {
        // The smallest available value in the permutation is i+1.
        // Since B_i >= 0, we must have A[i] <= C_i.
        // If the smallest A[i] is greater than the smallest available C_i,
        // we cannot form a permutation.
        if (A[i] > (i + 1)) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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