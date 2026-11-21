# [Recover Palindrome (P2235)](https://www.codechef.com/problems/P2235)

- **Difficulty Rating**: 825
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ containing lowercase English letters and question marks ('?'), determine if there is **exactly one** way to replace all '?' characters such that the resulting string is a palindrome.

## Intuition & Mathematical Observation
A string is a palindrome if $S[i] = S[N-1-i]$ for all $0 \le i < N$. To ensure a unique palindrome, every position in the string must be constrained to a specific character.

1.  **Pairs $(i, N-1-i)$**:
    *   If both $S[i]$ and $S[N-1-i]$ are '?', we have 26 possible choices for this pair (e.g., 'aa', 'bb', ..., 'zz'). Since we need exactly one solution, this case immediately makes the result non-unique.
    *   If one is '?' and the other is a character, the '?' is forced to match that character.
    *   If both are characters, they must already match (the problem implies the input is valid for at least one palindrome).
2.  **Middle Element (for odd $N$)**:
    *   If $N$ is odd, the middle character at index $N/2$ is its own mirror. If this character is '?', it can be any of the 26 letters, meaning there are 26 possible palindromes. Thus, if the middle character is '?', the solution is not unique.

**Conclusion**: The palindrome is unique if and only if there are no pairs of '?' that are mirrors of each other, and the middle character (if it exists) is already defined.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to check the constraints.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A string P of length N is a palindrome if P[i] == P[N-1-i] for all 0 <= i < N.
 * Given S, we need to determine if there is exactly one way to fill the '?'
 * such that the resulting string is a palindrome.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool unique = true;
    
    // Check pairs (i, N-1-i)
    for (int i = 0; i < N / 2; ++i) {
        if (S[i] == '?' && S[N - 1 - i] == '?') {
            unique = false;
            break;
        }
    }

    // Check middle element if N is odd
    if (N % 2 != 0) {
        if (S[N / 2] == '?') {
            unique = false;
        }
    }

    if (unique) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```