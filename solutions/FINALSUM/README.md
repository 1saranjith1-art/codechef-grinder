# [Final Sum (FINALSUM)](https://www.codechef.com/problems/FINALSUM)

- **Difficulty Rating**: 1145
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we perform $Q$ operations. In each operation, we are given a range $[L, R]$ (1-indexed). For this range, we perform the following updates:
- Add 1 to $A[L]$
- Subtract 1 from $A[L+1]$
- Add 1 to $A[L+2]$
- Subtract 1 from $A[L+3]$
- ... and so on, until index $R$.

We need to find the total sum of the array after all $Q$ operations are completed.

## Intuition & Mathematical Observation
Instead of updating the array elements individually (which would be $O(N \cdot Q)$ and lead to a Time Limit Exceeded), we can analyze the net effect of an operation on the total sum of the array.

Let the length of the range be $len = R - L + 1$. The operations performed are a sequence of $+1, -1, +1, -1, \dots$ applied to the elements from index $L$ to $R$.

1. **If $len$ is even**: There are exactly $len/2$ additions of 1 and $len/2$ subtractions of 1. The net change to the total sum is $(len/2) - (len/2) = 0$.
2. **If $len$ is odd**: There is one more addition than subtraction. Specifically, there are $(len+1)/2$ additions and $(len-1)/2$ subtractions. The net change to the total sum is $+1$.

Thus, for every query, we simply check if the length of the range $(R - L + 1)$ is odd. If it is, we increment the total sum by 1. Otherwise, the sum remains unchanged.

## Complexity Analysis
- **Time Complexity**: $O(N + Q)$ per test case. We iterate through the array once to calculate the initial sum and then process each of the $Q$ queries in $O(1)$ time.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the input storage, which can be processed on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * In one operation on [L, R], we add 1 to A[L], subtract 1 from A[L+1], 
 * add 1 to A[L+2], subtract 1 from A[L+3], and so on.
 * 
 * Let's look at the change in the total sum of the array:
 * The sequence of changes is +1, -1, +1, -1, ...
 * - If the length of the subarray (R - L + 1) is even, there are an equal 
 *   number of +1s and -1s. The net change to the sum is 0.
 * - If the length of the subarray (R - L + 1) is odd, there is one more +1 
 *   than -1. The net change to the sum is +1.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;
    
    long long current_sum = 0;
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        current_sum += val;
    }
    
    for (int i = 0; i < Q; ++i) {
        int L, R;
        cin >> L >> R;
        // If length (R - L + 1) is odd, sum increases by 1
        if ((R - L + 1) % 2 != 0) {
            current_sum += 1;
        }
    }
    
    cout << current_sum << "\n";
}

int main() {
    // Fast I/O
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