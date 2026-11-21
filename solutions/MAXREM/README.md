# [Maximum Remaining (MAXREM)](https://www.codechef.com/problems/MAXREM)

- **Difficulty Rating**: 1221
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ of $N$ integers, we need to find the maximum value of $A_i \pmod{A_j}$ for any pair $(i, j)$ such that $1 \le i, j \le N$.

## Intuition & Mathematical Observation
To maximize the result of $A_i \pmod{A_j}$, we consider the properties of the modulo operator:
1. If $A_i < A_j$, then $A_i \pmod{A_j} = A_i$.
2. If $A_i > A_j$, then $A_i \pmod{A_j} < A_j$.

To obtain the largest possible remainder, we want to pick the largest possible value for $A_i$ that is not divisible by $A_j$. 
- Let $M_1$ be the largest unique value in the array.
- Let $M_2$ be the second largest unique value in the array.

If we perform $M_2 \pmod{M_1}$, the result is $M_2$ (since $M_2 < M_1$). Any other combination $A_i \pmod{A_j}$ where $A_i$ is not the largest element will result in a value smaller than or equal to $M_2$. If we use the largest element $M_1$ as the dividend, the remainder will be $M_1 \pmod{A_j}$, which is strictly less than $A_j$. Therefore, the maximum possible remainder is simply the second largest unique element in the array. If there is only one unique element, the remainder is $0$.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ due to the use of a `std::set` to store and sort unique elements. This can be optimized to $O(N)$ by simply tracking the two largest values while iterating through the input.
- **Space Complexity**: $O(N)$ to store the unique elements in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to find max(A_i % A_j) for all i, j.
 * 
 * Case 1: If A_i < A_j, then A_i % A_j = A_i.
 * Case 2: If A_i > A_j, then A_i % A_j < A_j.
 * 
 * To maximize the remainder, we want the largest possible A_i that is not divisible 
 * by some A_j. Specifically, if we take the two largest distinct values in the array, 
 * say M1 (the largest) and M2 (the second largest), then M2 % M1 = M2.
 * 
 * If we have multiple occurrences of the largest value, they don't help us get a 
 * larger remainder than M2 % M1. Thus, we simply need to find the two largest 
 * distinct values in the array. Let these be M1 and M2 (where M1 > M2).
 * The answer is M2.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    // We use a set to store unique elements to easily find the two largest.
    // Given N up to 10^5, O(N log N) is perfectly fine.
    set<int> distinct_elements;
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        distinct_elements.insert(val);
    }

    // If there are fewer than 2 distinct elements, the max remainder is 0
    // (e.g., 5 % 5 = 0).
    if (distinct_elements.size() < 2) {
        cout << 0 << "\n";
    } else {
        // Get the largest element
        auto it = distinct_elements.end();
        --it; // Points to largest (M1)
        int m1 = *it;
        --it; // Points to second largest (M2)
        int m2 = *it;
        
        // The result is m2 % m1, which is simply m2 since m2 < m1.
        cout << m2 << "\n";
    }

    return 0;
}
```