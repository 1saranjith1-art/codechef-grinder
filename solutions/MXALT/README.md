# [Maximum Alternating Sum (MXALT)](https://www.codechef.com/problems/MXALT)

- **Difficulty Rating**: 1111
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we want to rearrange the elements to maximize the alternating sum defined as $A_1 - A_2 + A_3 - A_4 + \dots$. We need to determine the maximum possible value of this expression after an optimal permutation of the array elements.

## Intuition & Mathematical Observation
The alternating sum expression can be grouped into positive and negative terms:
- If $N$ is even, there are $N/2$ positive terms and $N/2$ negative terms.
- If $N$ is odd, there are $(N+1)/2$ positive terms and $(N-1)/2$ negative terms.

To maximize the total sum, we should assign the largest available values to the positive positions and the smallest available values to the negative positions. 

1. **Sort the array**: First, sort the array $A$ in non-decreasing order such that $A_0 \le A_1 \le \dots \le A_{N-1}$.
2. **Partitioning**: Let $k = \lfloor N/2 \rfloor$.
   - The first $k$ elements (the smallest ones) should be assigned to the negative positions.
   - The remaining $N - k$ elements (the largest ones) should be assigned to the positive positions.
3. **Calculation**: The maximum sum is simply the sum of the largest $(N-k)$ elements minus the sum of the smallest $k$ elements.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the sorting step. The subsequent linear scan to calculate the sum takes $O(N)$. Thus, the overall complexity is $O(N \log N)$ per test case.
- **Space Complexity**: $O(N)$ to store the array elements.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The alternating sum is A_1 - A_2 + A_3 - A_4 + ...
 * To maximize the sum, we assign the largest elements to the positive positions
 * and the smallest elements to the negative positions.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    // Sort to easily pick smallest and largest elements
    sort(A.begin(), A.end());

    long long sum = 0;
    int k = N / 2;

    // The first k elements are the smallest, so we subtract them
    for (int i = 0; i < k; ++i) {
        sum -= A[i];
    }
    // The remaining elements are the largest, so we add them
    for (int i = k; i < N; ++i) {
        sum += A[i];
    }

    cout << sum << "\n";
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