# [Chef and Pairing Slippers (CHEFSLP)](https://www.codechef.com/problems/CHEFSLP)

- **Difficulty Rating**: 930
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has $N$ slippers in total, consisting of $L$ left slippers and $R$ right slippers (where $R = N - L$). A pair of slippers consists of one left and one right slipper. Given the cost $X$ of one pair, calculate the total revenue Chef can generate by selling as many pairs as possible.

## Intuition & Mathematical Observation
1. **Identify the number of right slippers**: Since the total number of slippers is $N$ and the number of left slippers is $L$, the number of right slippers is simply $R = N - L$.
2. **Determine the number of pairs**: A pair requires one left and one right slipper. Therefore, the number of complete pairs that can be formed is limited by the smaller quantity between the left and right slippers.
   - $\text{Pairs} = \min(L, R) = \min(L, N - L)$
3. **Calculate Revenue**: Once the number of pairs is determined, the total revenue is simply the number of pairs multiplied by the cost per pair $X$.
   - $\text{Revenue} = \text{Pairs} \times X$

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total Revenue = Pairs * X
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Number of right slippers
        long long r = n - l;

        // Number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Total revenue
        long long revenue = pairs * x;

        cout << revenue << "\n";
    }

    return 0;
}
```