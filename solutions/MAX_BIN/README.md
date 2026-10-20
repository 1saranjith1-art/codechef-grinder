# [Max Binary (MAX_BIN)](https://www.codechef.com/problems/MAX_BIN)

- **Difficulty Rating**: 1143
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$ and an integer $K$, you are allowed to perform two types of operations:
1. **Type 1**: Append a '0' to the end of the string.
2. **Type 2**: Flip a '0' to a '1' at any position in the string.

You have exactly $K$ operations available. The goal is to maximize the decimal value of the resulting binary string.

## Intuition & Mathematical Observation
To maximize the value of a binary number, we must prioritize the most significant bits (leftmost positions).

1. **Prioritize the Most Significant Bit**: If the first bit (index 0) is '0', changing it to '1' using a Type 2 operation increases the value by $2^{N-1}$. This is the largest possible gain we can achieve with a single operation.
2. **Leverage Type 1 Operations**: Appending a '0' to the end of a binary string is equivalent to multiplying the current value by 2. This effectively shifts all existing bits to the left, increasing their power of 2. Since we want the largest possible number, using all remaining $K$ operations to append '0's is always optimal, as it increases the magnitude of the entire existing number.
3. **Strategy**:
   - If $S[0]$ is '0' and $K > 0$, flip it to '1' and decrement $K$.
   - Append the remaining $K$ zeros to the end of the string.

## Complexity Analysis
- **Time Complexity**: $O(N + K)$, where $N$ is the length of the string and $K$ is the number of operations. We iterate through the string once and perform a constant time string construction.
- **Space Complexity**: $O(N + K)$ to store the resulting string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the decimal value of a binary string:
 * 1. The most significant bit (the leftmost bit) has the highest impact.
 * 2. If the first character is '0', changing it to '1' (Type 2 operation) is the 
 *    most effective way to increase the value, as it adds 2^(N-1).
 * 3. Adding '0's at the end of the string (Type 1 operation) effectively multiplies 
 *    the current value by 2 for each '0' added, which is always optimal for 
 *    increasing the magnitude of the number.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // If the first bit is '0', prioritize changing it to '1'
    if (S[0] == '0' && K > 0) {
        S[0] = '1';
        K--;
    }

    // Append K zeros to the end of the string
    // Appending zeros is always optimal because it shifts the existing 
    // bits to higher powers of 2.
    string zeros(K, '0');
    cout << S << zeros << "\n";
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