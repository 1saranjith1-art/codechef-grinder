# [Chef and Stocks (STOCKMARKET)](https://www.codechef.com/problems/STOCKMARKET)

- **Difficulty Rating**: 948
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given an array of $N$ integers representing the profit or loss on each day. You are required to skip exactly one day's profit/loss. The goal is to choose the day to skip such that the sum of the remaining $N-1$ days is maximized.

## Intuition & Mathematical Observation
Let $S$ be the sum of all $N$ elements in the array. If we choose to skip the element at index $i$ (denoted as $A[i]$), the resulting sum will be:
$$\text{Result} = S - A[i]$$

To maximize this result, we need to subtract the smallest possible value from $S$. Therefore, the problem reduces to finding the minimum element in the array and subtracting it from the total sum of all elements.

**Mathematical Logic:**
1. Calculate the total sum of the array: $\sum_{i=0}^{N-1} A[i]$.
2. Identify the minimum element: $\min(A_0, A_1, \dots, A_{N-1})$.
3. The answer is $\left( \sum A[i] \right) - \min(A)$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to calculate the sum and find the minimum element.
- **Space Complexity**: $O(1)$ auxiliary space (if we process elements on the fly) or $O(N)$ if we store the array. The provided solution uses $O(N)$ to store the input, but this can easily be optimized to $O(1)$ by reading values one by one.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N days of profit/loss. We need to skip exactly one day such that
 * the sum of the remaining N-1 days is maximized.
 * 
 * Let S be the sum of all N days.
 * If we skip day i, the total profit is S - A[i].
 * To maximize (S - A[i]), we need to minimize A[i].
 * Therefore, the optimal strategy is to find the minimum value in the array
 * and subtract it from the total sum of the array.
 */

void solve() {
    int N;
    cin >> N;
    
    vector<long long> A(N);
    long long total_sum = 0;
    // Initialize min_val with a value larger than any possible A[i]
    long long min_val = 200; 
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
        if (A[i] < min_val) {
            min_val = A[i];
        }
    }
    
    // The result is the total sum minus the smallest element
    cout << (total_sum - min_val) << "\n";
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