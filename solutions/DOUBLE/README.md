# [Double Strings (DOUBLE)](https://www.codechef.com/problems/DOUBLE)

- **Difficulty Rating**: 1134
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum length of a "double string" that can be formed given an integer $N$. A double string is defined as a string of even length where the first half is identical to the second half (e.g., "abcabc"). We are essentially looking for the largest even integer less than or equal to $N$.

## Intuition & Mathematical Observation
A double string is formed by repeating a sequence of characters twice. If we have a string of length $N$, we want to utilize as many characters as possible to construct a string of the form $S + S$.

1. **Even $N$**: If $N$ is even, we can use all $N$ characters to form a double string. For example, if $N=4$, we can form "aabb" which is a double string of length 4.
2. **Odd $N$**: If $N$ is odd, we cannot use all $N$ characters because a double string must have an even length. By removing exactly one character, we are left with $N-1$ characters, which is an even number. We can always arrange these $N-1$ characters to form a double string.

Therefore, the maximum length is simply the largest even integer $\le N$. This can be calculated as:
- If $N$ is even: $N$
- If $N$ is odd: $N - 1$

This logic simplifies to `(N / 2) * 2` in integer arithmetic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we only perform a single parity check and a subtraction, the operation is constant time. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$. We only use a few variables to store the input and output, requiring no extra data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A "double string" is a string of even length where the first half equals the second half.
 * This means a double string is formed by taking some characters and repeating them twice.
 * 
 * If N is even, we can use all N characters to form a double string.
 * If N is odd, we must remove at least one character to make the total length even.
 * Thus, the maximum length is the largest even number <= N.
 */

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n;
        cin >> n;
        
        // If N is even, the answer is N.
        // If N is odd, the answer is N - 1.
        if (n % 2 == 0) {
            cout << n << "\n";
        } else {
            cout << n - 1 << "\n";
        }
    }
    return 0;
}
```