# [Distinct Palindrome (DISPAL)](https://www.codechef.com/problems/DISPAL)

- **Difficulty Rating**: 1304
- **Solved in**: 1 attempt(s)

## Problem Summary
Given two integers $N$ and $X$, we need to construct a palindrome of length $N$ that contains exactly $X$ distinct characters. If no such palindrome exists, output -1.

## Intuition & Mathematical Observation
1. **Symmetry Constraint**: A palindrome is defined by its first $\lceil N/2 \rceil$ characters. Once the first half is determined, the second half is fixed by mirroring.
2. **Distinct Character Limit**: Since the second half is just a reflection of the first, the number of distinct characters in the entire palindrome is exactly the number of distinct characters in the first $\lceil N/2 \rceil$ positions.
3. **Feasibility**: 
   - We have a maximum of $\lceil N/2 \rceil$ slots to place distinct characters. If $X > \lceil N/2 \rceil$, it is impossible to have $X$ distinct characters, so we output -1.
   - If $X \le \lceil N/2 \rceil$, we can easily construct the string. We assign the first $X-1$ characters as the first $X-1$ letters of the alphabet ('a', 'b', ...). We then fill all remaining slots in the first half with the $X$-th character (the character at index $X-1$). This ensures exactly $X$ distinct characters are used.
4. **Construction**:
   - Fill indices $0$ to $X-2$ with `char('a' + i)`.
   - Fill indices $X-1$ to $\lceil N/2 \rceil - 1$ with `char('a' + X - 1)`.
   - Mirror the first half to the second half to complete the palindrome.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the string of length $N$ once to fill it and once to mirror it.
- **Space Complexity**: $O(N)$ to store the resulting string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a palindrome of length N with exactly X distinct characters.
 * 
 * A palindrome is determined by its first ceil(N/2) characters.
 * Let K = ceil(N/2). These K characters must contain exactly X distinct characters.
 * 
 * Constraints:
 * 1. We can use at most 26 distinct characters.
 * 2. The number of distinct characters X must satisfy X <= K.
 *    If X > ceil(N/2), it is impossible because the second half is a mirror of the first.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    int half_len = (N + 1) / 2;

    // If we need more distinct characters than available slots in the half-palindrome
    if (X > half_len) {
        cout << -1 << "\n";
        return;
    }

    string s(N, ' ');
    // Fill the first half
    for (int i = 0; i < half_len; ++i) {
        if (i < X - 1) {
            s[i] = (char)('a' + i);
        } else {
            // Fill remaining slots with the X-th character
            s[i] = (char)('a' + X - 1);
        }
    }

    // Mirror to the second half
    for (int i = 0; i < N / 2; ++i) {
        s[N - 1 - i] = s[i];
    }

    cout << s << "\n";
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