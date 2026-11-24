# [Two Numbers (TWONMS)](https://www.codechef.com/problems/TWONMS)

- **Difficulty Rating**: 1320
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob start with two numbers, $A$ and $B$, respectively. There are $N$ turns in total. In each turn, the current player doubles their number. Alice takes turns 1, 3, 5, ..., and Bob takes turns 2, 4, 6, .... We need to calculate the floor of the ratio of the maximum number to the minimum number after $N$ turns.

## Intuition & Mathematical Observation
Let $k_1$ be the number of turns Alice takes and $k_2$ be the number of turns Bob takes.
- If $N$ is even, $k_1 = N/2$ and $k_2 = N/2$.
- If $N$ is odd, $k_1 = (N+1)/2$ and $k_2 = (N-1)/2$.

After $N$ turns:
- Alice's number $C = A \times 2^{k_1}$
- Bob's number $D = B \times 2^{k_2}$

We want to find $\lfloor \frac{\max(C, D)}{\min(C, D)} \rfloor$.

**Case 1: $N$ is even**
$C = A \times 2^{N/2}$ and $D = B \times 2^{N/2}$.
The ratio is $\frac{\max(A, B) \times 2^{N/2}}{\min(A, B) \times 2^{N/2}} = \frac{\max(A, B)}{\min(A, B)}$.

**Case 2: $N$ is odd**
$C = A \times 2^{(N+1)/2} = (A \times 2) \times 2^{(N-1)/2}$ and $D = B \times 2^{(N-1)/2}$.
The ratio is $\frac{\max(2A, B) \times 2^{(N-1)/2}}{\min(2A, B) \times 2^{(N-1)/2}} = \frac{\max(2A, B)}{\min(2A, B)}$.

By simplifying the powers of 2, we avoid overflow issues and can compute the result using simple integer division.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and intermediate results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts with A, Bob with B.
 * Total N turns.
 * Alice takes turns 1, 3, 5, ...
 * Bob takes turns 2, 4, 6, ...
 * 
 * Number of turns Alice takes: ceil(N / 2.0)
 * Number of turns Bob takes: floor(N / 2.0)
 * 
 * Let k1 = ceil(N / 2.0)
 * Let k2 = floor(N / 2.0)
 * 
 * Alice's final number C = A * 2^k1
 * Bob's final number D = B * 2^k2
 * 
 * We need to find floor(max(C, D) / min(C, D)).
 * 
 * Case 1: N is even.
 * k1 = N/2, k2 = N/2.
 * C = A * 2^(N/2), D = B * 2^(N/2).
 * Result = max(A, B) / min(A, B).
 * 
 * Case 2: N is odd.
 * k1 = (N+1)/2, k2 = (N-1)/2.
 * C = A * 2^((N+1)/2), D = B * 2^((N-1)/2).
 * C = (A * 2) * 2^((N-1)/2), D = B * 2^((N-1)/2).
 * Result = max(2A, B) / min(2A, B).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        cin >> a >> b >> n;

        if (n % 2 == 0) {
            // N is even, both multiplied by 2^(N/2)
            // The ratio is simply max(A, B) / min(A, B)
            if (a >= b) {
                cout << a / b << "\n";
            } else {
                cout << b / a << "\n";
            }
        } else {
            // N is odd, Alice multiplied by 2^((N+1)/2), Bob by 2^((N-1)/2)
            // Effectively Alice's number is (A * 2) and Bob's is B, 
            // both scaled by 2^((N-1)/2)
            long long a_final = a * 2;
            long long b_final = b;
            
            if (a_final >= b_final) {
                cout << a_final / b_final << "\n";
            } else {
                cout << b_final / a_final << "\n";
            }
        }
    }

    return 0;
}
```