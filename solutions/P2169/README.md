# [Opposite Attract (P2169)](https://www.codechef.com/problems/P2169)

- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we need to construct a new string $T$ of the same length such that for every index $i$, $T[i] \neq S[i]$. In the context of a binary string (consisting only of '0's and '1's), this means we must flip every bit of the input string.

## Intuition & Mathematical Observation
Since the string is binary, the only possible characters are '0' and '1'. The condition $T[i] \neq S[i]$ implies:
- If $S[i] = '0'$, then $T[i]$ must be '1'.
- If $S[i] = '1'$, then $T[i]$ must be '0'.

This is a direct mapping where each character is transformed into its logical opposite. We can iterate through the string $S$ and append the flipped character to a new string $T$ (or modify the string in place).

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once. Given the constraints, the total time complexity is $O(\sum N)$, which comfortably fits within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the input string $S$ and the resulting string $T$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We need to construct a string T such that T[i] != S[i] for all i.
 * Since the string is binary, the only possible characters are '0' and '1'.
 * If S[i] == '0', then T[i] must be '1'.
 * If S[i] == '1', then T[i] must be '0'.
 * This is equivalent to flipping each bit of the string S.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string T = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            T += '1';
        } else {
            T += '0';
        }
    }
    cout << T << "\n";
}

int main() {
    // Fast I/O setup
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