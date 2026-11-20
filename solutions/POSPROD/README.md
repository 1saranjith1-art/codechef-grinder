# [Positive Products (POSPROD)](https://www.codechef.com/problems/POSPROD)

- **Difficulty Rating**: 1178
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the number of pairs $(i, j)$ such that $1 \le i < j \le N$ and the product $A[i] \times A[j] > 0$.

## Intuition & Mathematical Observation
For the product of two numbers to be strictly greater than zero, both numbers must have the same sign:
1. **Both are positive**: If there are $P$ positive numbers in the array, the number of ways to choose two of them is given by the combination formula $\binom{P}{2} = \frac{P \times (P - 1)}{2}$.
2. **Both are negative**: If there are $M$ negative numbers in the array, the number of ways to choose two of them is $\binom{M}{2} = \frac{M \times (M - 1)}{2}$.
3. **Zeroes**: Any product involving zero results in zero, which is not greater than zero. Therefore, zeroes can be ignored entirely.

The total number of valid pairs is the sum of these two combinations:
$$\text{Total Pairs} = \frac{P(P-1)}{2} + \frac{M(M-1)}{2}$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the array exactly once to count the positive and negative integers.
- **Space Complexity**: $O(1)$ auxiliary space, as we only store the counts of positive and negative numbers regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the number of pairs (i, j) such that 1 <= i < j <= N and A[i] * A[j] > 0.
 * A[i] * A[j] > 0 if and only if:
 * 1. Both A[i] and A[j] are positive.
 * 2. Both A[i] and A[j] are negative.
 * 
 * If we have 'pos' count of positive numbers and 'neg' count of negative numbers:
 * - The number of ways to choose two positive numbers is pos * (pos - 1) / 2.
 * - The number of ways to choose two negative numbers is neg * (neg - 1) / 2.
 * - Zeroes do not contribute to any positive product.
 */

void solve() {
    int N;
    cin >> N;
    
    long long pos_count = 0;
    long long neg_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        if (val > 0) {
            pos_count++;
        } else if (val < 0) {
            neg_count++;
        }
    }
    
    // Calculate combinations nC2 = n * (n - 1) / 2
    long long ans = (pos_count * (pos_count - 1)) / 2 + (neg_count * (neg_count - 1)) / 2;
    
    cout << ans << "\n";
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