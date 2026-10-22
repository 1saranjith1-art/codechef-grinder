# [Magic Pairs (ALEXNUMB)](https://www.codechef.com/problems/ALEXNUMB)

- **Difficulty Rating**: 1245
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array of $n$ distinct integers, we need to find the number of pairs $(i, j)$ such that $1 \le i, j \le n$, $i \neq j$, and $a_i < a_j$.

## Intuition & Mathematical Observation
The problem states that all $n$ integers in the array are **distinct**. 

1. Consider any two distinct indices $i$ and $j$ from the array. Since all elements are distinct, there are only two possibilities for the values at these indices: either $a_i < a_j$ or $a_j < a_i$.
2. The total number of pairs $(i, j)$ where $i \neq j$ is $n \times (n - 1)$.
3. Because for every pair of distinct indices, exactly one of the two conditions ($a_i < a_j$ or $a_j < a_i$) must be true, exactly half of the total pairs will satisfy the condition $a_i < a_j$.
4. Therefore, the number of pairs is simply the number of ways to choose 2 distinct indices from $n$, which is given by the combination formula:
   $$\binom{n}{2} = \frac{n(n - 1)}{2}$$
5. **Note on Constraints**: Since $n$ can be up to $10^5$, the result can be as large as $\approx 5 \times 10^9$. This exceeds the capacity of a standard 32-bit `int`, so we must use a 64-bit integer type (`long long` in C++).

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, as we must iterate through the input to consume the $n$ integers.
- **Space Complexity**: $O(1)$, as we do not need to store the array; we can simply read and discard the values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given n distinct integers a_1, a_2, ..., a_n.
 * We need to find the number of pairs (i, j) such that 1 <= i, j <= n, i != j, and a_i < a_j.
 * 
 * Since all integers are distinct, for any two distinct indices i and j, 
 * either a_i < a_j or a_j < a_i.
 * 
 * The total number of pairs (i, j) with i != j is n * (n - 1).
 * Because exactly one of (a_i < a_j) or (a_j < a_i) must be true for any pair of distinct indices,
 * exactly half of the total pairs (i, j) where i != j will satisfy a_i < a_j.
 * 
 * Number of pairs = (n * (n - 1)) / 2.
 * 
 * Constraints:
 * n <= 100,000.
 * n * (n - 1) / 2 can be up to ~5 * 10^9, which exceeds the range of a 32-bit integer.
 * We must use long long to store the result.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // Read the n integers. 
        // Note: The values of a_i do not actually affect the count because 
        // they are all distinct, so the condition a_i < a_j will always 
        // be satisfied by exactly half of the pairs of distinct indices.
        long long temp;
        for (int i = 0; i < n; ++i) {
            cin >> temp;
        }

        // Calculate nC2 = n * (n - 1) / 2
        long long result = (n * (n - 1)) / 2;
        cout << result << "\n";
    }

    return 0;
}
```