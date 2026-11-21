# [Sorting Prefixes (SORTPREF)](https://www.codechef.com/problems/SORTPREF)

- **Difficulty Rating**: 1291
- **Solved in**: 3 attempt(s)

## Problem Summary
You are given an array $A$ of size $N$ containing a permutation of numbers from $1$ to $N$. You can perform an operation at any index $i$ (where $1 \le i \le N$) with a cost of $A[i-1]$. Performing this operation sorts the prefix $A[0 \dots i-1]$ such that it becomes $1, 2, \dots, i$. The goal is to find the minimum cost to make the entire array sorted (i.e., $A[j] = j+1$ for all $0 \le j < N$). If the array is already sorted, the cost is $0$.

## Intuition & Mathematical Observation
1. **Already Sorted Case**: If the array is already sorted, the cost is $0$.
2. **Operation Effect**: Performing an operation at index $i$ transforms the prefix $A[0 \dots i-1]$ into $1, 2, \dots, i$. For the entire array to be sorted after this operation, the remaining suffix $A[i \dots N-1]$ must already be in its correct sorted position (i.e., $A[j] = j+1$ for all $j \ge i$).
3. **Strategy**: 
   - We iterate through all possible indices $i$ from $1$ to $N$.
   - For each $i$, we check if the suffix starting from index $i$ to $N-1$ matches the sequence $i+1, i+2, \dots, N$.
   - If the suffix condition is met, performing the operation at index $i$ will result in a fully sorted array. The cost for this specific operation is $A[i-1]$.
   - We track the minimum cost among all valid operations.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ in the worst case due to the nested loop checking the suffix for every possible operation index. Given the constraints typical for this difficulty level, this approach is efficient enough.
- **Space Complexity**: $O(N)$ to store the input array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to sort the array A. An operation at index i (1-indexed) costs A[i-1] 
 * and sorts the prefix A[0...i-1].
 * After the operation, the array becomes: 1, 2, ..., i, A[i], ..., A[N-1].
 * This is sorted if and only if A[i...N-1] is equal to {i+1, i+2, ..., N}.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // Check if already sorted
    bool sorted = true;
    for (int i = 0; i < N; ++i) {
        if (A[i] != i + 1) {
            sorted = false;
            break;
        }
    }
    if (sorted) {
        cout << 0 << "\n";
        return;
    }

    int min_cost = INT_MAX;
    // Try performing an operation at index i (1-based)
    for (int i = 1; i <= N; ++i) {
        // Check if suffix A[i...N-1] is {i+1, ..., N}
        bool possible = true;
        for (int j = i; j < N; ++j) {
            if (A[j] != j + 1) {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            min_cost = min(min_cost, A[i - 1]);
        }
    }

    cout << min_cost << "\n";
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