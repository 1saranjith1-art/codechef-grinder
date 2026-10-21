# [Chef and String (RECNDSTR)](https://www.codechef.com/problems/RECNDSTR)

- **Difficulty Rating**: 1206
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we need to determine if there exists a string $V$ such that $S$ is both the left-shift of $V$ and the right-shift of $V$. 
- A **left-shift** of $V$ moves the first character to the end.
- A **right-shift** of $V$ moves the last character to the beginning.

Essentially, we must check if the left-shift of $S$ is equal to the right-shift of $S$.

## Intuition & Mathematical Observation
Let $S$ be the given string of length $n$.
1. If we perform a left-shift on $S$ to get $L_S$, and a right-shift on $S$ to get $R_S$, the condition "there exists $V$ such that $L(V) = S$ and $R(V) = S$" simplifies to checking if $L_S = R_S$.
2. **Edge Case**: If the length of the string is 1 or 2, shifting the characters will always result in the same string or a symmetric configuration that satisfies the condition. For example, if $n=2$, "ab" shifted left is "ba" and shifted right is "ba". If $n=1$, "a" shifted is "a". Thus, for $n \le 2$, the answer is always "YES".
3. For $n > 2$, we construct the strings $L_S$ and $R_S$ explicitly using string concatenation and compare them.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. String slicing and concatenation take linear time relative to the length of the string.
- **Space Complexity**: $O(N)$ to store the shifted versions of the string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let S be a string of length n.
 * L(V) = S means V[1...n-1] + V[0] = S[0...n-1].
 * R(V) = S means V[n-1] + V[0...n-2] = S[0...n-1].
 * 
 * We need to check if the left shift of S is equal to the right shift of S.
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    
    // For strings of length 1 or 2, the condition is always satisfied.
    if (n <= 2) {
        cout << "YES" << "\n";
        return;
    }
    
    // Left shift: move first char to end
    string l_s = s.substr(1) + s[0];
    
    // Right shift: move last char to beginning
    string r_s = s[n - 1] + s.substr(0, n - 1);
    
    if (l_s == r_s) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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