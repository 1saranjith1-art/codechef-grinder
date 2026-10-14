# [Streak Star (STKSTR)](https://www.codechef.com/problems/STKSTR)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers and a multiplier $X$, you are allowed to perform at most one operation: choose an index $i$ and replace $A[i]$ with $A[i] \times X$. The goal is to maximize the length of the longest non-decreasing subarray after performing this operation (or performing no operation at all).

## Intuition & Mathematical Observation
The constraints state that the sum of $N$ over all test cases is at most 1000. This small constraint suggests that an $O(N^2)$ approach is perfectly acceptable.

1.  **Brute Force Strategy**: Since we can modify at most one element, we can simulate every possible scenario:
    *   **Scenario 0**: Do nothing and calculate the longest non-decreasing subarray.
    *   **Scenario $i$ (for $0 \le i < N$)**: Multiply $A[i]$ by $X$, calculate the longest non-decreasing subarray, and then revert the change (backtrack).
2.  **Streak Calculation**: A helper function `get_streak` iterates through the array once in $O(N)$ time, maintaining a `current_streak` counter that resets whenever $A[i] < A[i-1]$.
3.  **Optimization**: By iterating through all $N$ possible indices to modify and calculating the streak for each, we cover all possibilities. The maximum value found across all these simulations is our answer.

## Complexity Analysis
- **Time Complexity**: $O(N^2)$ per test case. Since we iterate through $N$ indices and perform an $O(N)$ scan for each, the total complexity is $O(N^2)$. Given $\sum N \le 1000$, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the array $A$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of length N. We can modify at most one element A[i] to A[i] * X.
 * We want to maximize the length of the longest non-decreasing subarray.
 * 
 * Since N is small (sum of N <= 1000), we can iterate through every possible index i
 * that we might modify (from 0 to N-1). For each modification, we calculate the 
 * streak value of the resulting array in O(N) time.
 * Total complexity: O(N^2), which is well within the limits for N=1000.
 */

int get_streak(const vector<long long>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    int max_streak = 1;
    int current_streak = 1;
    for (int i = 1; i < n; ++i) {
        if (arr[i] >= arr[i - 1]) {
            current_streak++;
        } else {
            max_streak = max(max_streak, current_streak);
            current_streak = 1;
        }
    }
    return max(max_streak, current_streak);
}

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Case 1: No operation
    int max_val = get_streak(A);

    // Case 2: Try modifying each index i
    for (int i = 0; i < N; ++i) {
        long long original = A[i];
        A[i] *= X;
        max_val = max(max_val, get_streak(A));
        A[i] = original; // Backtrack
    }

    cout << max_val << "\n";
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