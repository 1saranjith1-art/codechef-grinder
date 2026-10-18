# [Odd Repeat (REPEAT)](https://www.codechef.com/problems/REPEAT)

- **Difficulty Rating**: 1218
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given an array of length $N + K - 1$. The array contains all the first $N$ positive odd numbers exactly once, except for one specific odd number $X$, which appears $K$ times in total. Given the total sum $S$ of all elements in the array, we need to find the value of $X$.

## Intuition & Mathematical Observation
1.  **Sum of first $N$ odd numbers**: The sequence of the first $N$ odd numbers is $1, 3, 5, \dots, (2N-1)$. The sum of this arithmetic progression is given by the formula:
    $$\sum_{i=1}^{N} (2i - 1) = N^2$$
2.  **Formulating the total sum**: The array consists of the first $N$ odd numbers plus $(K-1)$ extra occurrences of the number $X$. Therefore, the total sum $S$ can be expressed as:
    $$S = (\text{Sum of first } N \text{ odd numbers}) + (K - 1) \times X$$
    $$S = N^2 + (K - 1) \times X$$
3.  **Solving for $X$**: By rearranging the equation above, we can isolate $X$:
    $$(K - 1) \times X = S - N^2$$
    $$X = \frac{S - N^2}{K - 1}$$

Since all inputs are guaranteed to result in an integer $X$, this formula allows us to find the answer in constant time per test case.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves only basic arithmetic operations. For $T$ test cases, the complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N odd numbers is N^2.
 * 
 * Let the number that appears K times be X.
 * The array consists of all numbers from 1 to (2N-1) once, 
 * plus (K-1) additional copies of X.
 * 
 * Total Sum S = (Sum of first N odd numbers) + (K-1) * X
 * S = N^2 + (K-1) * X
 * 
 * Rearranging to solve for X:
 * (K-1) * X = S - N^2
 * X = (S - N^2) / (K - 1)
 */

void solve() {
    long long N, K, S;
    if (!(cin >> N >> K >> S)) return;

    // Calculate the sum of the first N odd numbers
    long long sum_n = N * N;
    
    // Calculate the difference
    long long diff = S - sum_n;
    
    // Calculate X
    long long X = diff / (K - 1);
    
    cout << X << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```