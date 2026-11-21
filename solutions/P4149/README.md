# [Maximise Sum (P4149)](https://www.codechef.com/problems/P4149)

- **Difficulty Rating**: 1372
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $N$ integers, you are allowed to perform an operation any number of times: choose any two elements and flip their signs (i.e., $a_i \to -a_i$ and $a_j \to -a_j$). The goal is to maximize the sum of the array elements after performing any number of these operations.

## Intuition & Mathematical Observation
The key observation is that the operation allows us to change the signs of two elements simultaneously. This implies that the **parity of the count of negative numbers** remains invariant.

1. **Even number of negative signs**: We can pair up all negative numbers and flip them to positive. Thus, we can make all elements in the array non-negative. The maximum sum is simply the sum of the absolute values of all elements.
2. **Odd number of negative signs**: We can flip pairs of negative numbers until only one negative number remains. To maximize the total sum, we should ensure that the element with the **smallest absolute value** is the one that remains negative. 
   - If the sum of absolute values is $S$ and the smallest absolute value is $M$, the final sum will be $(S - M) - M = S - 2M$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of elements in the array. We iterate through the array once to calculate the sum, count negatives, and find the minimum absolute value.
- **Space Complexity**: $O(1)$ auxiliary space (excluding the input storage), as we only need a few variables to track the sum, count, and minimum value.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to flip the signs of any two elements simultaneously.
 * This means the parity of the number of negative signs in the array remains invariant.
 * 
 * If the number of negative elements is even, we can flip all of them to positive.
 * If the number of negative elements is odd, we will always be left with at least
 * one negative element. To maximize the sum, we ensure the element with the 
 * smallest absolute value is the one that remains negative.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    int negative_count = 0;
    long long min_abs = 200000; // Based on problem constraints
    long long sum_abs = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] < 0) {
            negative_count++;
        }
        long long abs_val = abs(a[i]);
        sum_abs += abs_val;
        if (abs_val < min_abs) {
            min_abs = abs_val;
        }
    }

    // If negative_count is even, we can make all numbers positive.
    // If odd, one number must remain negative; we pick the smallest absolute value.
    if (negative_count % 2 == 0) {
        cout << sum_abs << "\n";
    } else {
        cout << sum_abs - 2 * min_abs << "\n";
    }
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