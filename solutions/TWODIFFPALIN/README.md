# [Two Different Palindromes (TWODIFFPALIN)](https://www.codechef.com/problems/TWODIFFPALIN)

- **Difficulty Rating**: 1216
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $A$ and $B$, determine if it is possible to construct two **different** binary strings that are both palindromes, such that each string contains exactly $A$ zeros and $B$ ones.

## Intuition & Mathematical Observation
To form a palindrome using $A$ zeros and $B$ ones:
1. **Parity Constraint**: In any palindrome, at most one character can have an odd count. If both $A$ and $B$ are odd, the total length $A+B$ is even, and every character must appear an even number of times. Thus, if $A$ and $B$ are both odd, it is impossible to form even a single palindrome.
2. **Uniqueness Constraint**: We need to form *two different* palindromes. 
   - If $A=1$ or $B=1$, the structure of the palindrome is extremely restricted. For example, if $A=1$ and $B=4$, the only possible palindrome is "11011". Because the single '0' must be in the center, there is no way to rearrange the characters to form a different palindrome.
   - If both $A$ and $B$ are even, or if one is even and the other is odd (and neither is 1), we have enough flexibility to arrange the characters in at least two distinct ways.

**Conclusion**:
- If $(A \pmod 2 \neq 0 \text{ and } B \pmod 2 \neq 0)$, it is impossible (0 palindromes).
- If $A=1$ or $B=1$, it is impossible to form 2 distinct palindromes (only 1 exists).
- Otherwise, it is possible to construct at least two distinct palindromes.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic checks.
- **Space Complexity**: $O(1)$, as no extra data structures are used.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct two different binary strings that are palindromes, 
 * each containing exactly A zeros and B ones.
 * 
 * Logic:
 * 1. If both A and B are odd, we cannot form any palindrome (total length is even, 
 *    but we need at most one odd count).
 * 2. If A=1 or B=1, we can only form one unique palindrome (the single character 
 *    must be placed in the center, fixing the structure).
 * 3. Otherwise, we can always construct at least two distinct palindromes.
 */

void solve() {
    int A, B;
    cin >> A >> B;

    // Check if both are odd OR if either is 1
    if ((A % 2 != 0 && B % 2 != 0) || (A == 1 || B == 1)) {
        cout << "No" << "\n";
    } else {
        cout << "Yes" << "\n";
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