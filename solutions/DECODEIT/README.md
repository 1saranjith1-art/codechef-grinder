# [Encoded String (DECODEIT)](https://www.codechef.com/problems/DECODEIT)

- **Difficulty Rating**: -1
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to decode a string of length $N$ (where $N$ is a multiple of 4) consisting of '0's and '1's. The string is formed by concatenating 4-bit binary representations of the first 16 lowercase English letters ('a' through 'p'). Specifically, 'a' corresponds to `0000` (0), 'b' to `0001` (1), ..., and 'p' to `1111` (15). We need to process the string in 4-bit chunks and convert each chunk back into its corresponding character.

## Intuition & Mathematical Observation
The encoding scheme is a direct mapping of the index of the alphabet (0-15) to its 4-bit binary representation. 
- Each character $c$ can be retrieved by calculating the decimal value of its 4-bit binary block.
- If a 4-bit block is $b_3b_2b_1b_0$, its decimal value is $b_3 \cdot 2^3 + b_2 \cdot 2^2 + b_1 \cdot 2^1 + b_0 \cdot 2^0$.
- Once we have the decimal value $V$, the character is simply `'a' + V`.

We can efficiently compute this value using bitwise operations: iterating through the 4 bits and shifting the current value left (`val << 1`) before adding the new bit.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the input string. We iterate through the string exactly once, processing 4 bits at a time.
- **Space Complexity**: $O(N)$ to store the input string and the resulting decoded string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters ('a' through 'p').
 * Each character is represented by 4 bits.
 * The encoding is essentially a binary representation of the index of the character (0-15).
 * 
 * Since each 4-bit block corresponds to an integer from 0 to 15, we can convert 
 * each 4-bit substring into its decimal equivalent and map it to the corresponding 
 * character ('a' + decimal_value).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary string to integer
        // bit 0: 2^3, bit 1: 2^2, bit 2: 2^1, bit 3: 2^0
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) | (s[i + j] - '0');
        }
        // Map integer 0-15 to 'a'-'p'
        result += (char)('a' + val);
    }
    cout << result << "\n";
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