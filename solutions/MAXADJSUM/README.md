# [Maximise Adjacent Sum (MAXADJSUM)](https://www.codechef.com/problems/MAXADJSUM)

- **Difficulty Rating**: 1118
- **Solved in**: 3 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to rearrange the elements of the array to maximize the sum of all adjacent pairs. Specifically, we want to maximize:
$$f(A) = \sum_{i=1}^{N-1} (A_i + A_{i+1})$$

## Intuition & Mathematical Observation
Let's expand the summation formula:
$$f(A) = (A_1 + A_2) + (A_2 + A_3) + (A_3 + A_4) + \dots + (A_{N-1} + A_N)$$

By grouping the terms, we observe:
$$f(A) = A_1 + 2A_2 + 2A_3 + \dots + 2A_{N-1} + A_N$$

We can rewrite this in terms of the total sum of the array $S = \sum_{i=1}^{N} A_i$:
$$f(A) = 2 \left( \sum_{i=1}^{N} A_i \right) - (A_1 + A_N)$$
$$f(A) = 2S - (A_1 + A_N)$$

Since $2S$ is constant regardless of the arrangement, maximizing $f(A)$ is equivalent to **minimizing the sum of the two elements placed at the ends of the array** ($A_1$ and $A_N$). To achieve this, we sort the array in non-decreasing order and choose the two smallest elements ($A[0]$ and $A[1]$) to be the endpoints.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The summation and calculation take $O(N)$, making the sorting the dominant factor.
- **Space Complexity**: $O(N)$ to store the input array.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * Problem Analysis:
 * f(A) = (A_1 + A_2) + (A_2 + A_3) + ... + (A_{N-1} + A_N)
 * f(A) = A_1 + 2*A_2 + 2*A_3 + ... + 2*A_{N-1} + A_N
 * f(A) = 2 * sum(A) - (A_1 + A_N)
 * To maximize f(A), we must minimize (A_1 + A_N).
 * We sort the array and pick the two smallest elements as the ends.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    long long total_sum = 0;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        total_sum += A[i];
    }
    
    // Sort to easily identify the two smallest elements
    sort(A.begin(), A.end());
    
    // The two smallest elements are A[0] and A[1]
    long long min_ends = A[0] + A[1];
    long long result = 2 * total_sum - min_ends;
    
    cout << result << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```