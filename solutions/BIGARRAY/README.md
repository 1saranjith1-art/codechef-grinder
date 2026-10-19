# [Obtain the Sum (BIGARRAY)](https://www.codechef.com/problems/BIGARRAY)

- **Difficulty Rating**: 1368
- **Solved in**: 1 attempt(s)

## Problem Summary
Given an array $A$ containing all integers from $1$ to $N$ (i.e., $A = [1, 2, 3, \dots, N]$), we are asked to find an element $x$ such that the sum of all elements in the array excluding $x$ equals a given value $S$. If no such $x$ exists within the range $[1, N]$, we must output $-1$.

## Intuition & Mathematical Observation
The sum of all integers from $1$ to $N$ is given by the arithmetic series formula:
$$\text{TotalSum} = \frac{N \times (N + 1)}{2}$$

Let $x$ be the element removed from the array. The problem states that the sum of the remaining elements is $S$. This can be expressed as:
$$\text{TotalSum} - x = S$$

Rearranging the equation to solve for $x$:
$$x = \text{TotalSum} - S$$

Since $x$ must be an element of the original array, it must satisfy the condition $1 \le x \le N$. If the calculated $x$ falls outside this range, it implies that no such element exists, and we output $-1$.

**Note on Data Types:** Given $N \le 10^9$, the `TotalSum` can reach approximately $5 \times 10^{17}$. This exceeds the capacity of a 32-bit integer, so we must use `long long` in C++ to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves simple arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * We are looking for an index x such that:
 * (Sum of all elements except A[x]) = S
 * (TotalSum - x) = S
 * Therefore, x = TotalSum - S.
 * 
 * Constraints:
 * 1 <= x <= N
 * 1 <= N <= 10^9
 * 1 <= S <= 10^18
 * 
 * Since N can be 10^9, TotalSum can be approximately (10^9 * 10^9) / 2 = 5 * 10^17.
 * This fits within a 64-bit signed integer (long long in C++).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate total sum of 1 to N
        // Use long long to prevent overflow
        long long total_sum = n * (n + 1) / 2;

        // The equation is: total_sum - x = s
        // So, x = total_sum - s
        long long x = total_sum - s;

        // Check if x is a valid index (1 <= x <= N)
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
```