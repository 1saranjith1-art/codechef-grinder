# [False Number (FALSNUM)](https://www.codechef.com/problems/FALSNUM)

- **Difficulty Rating**: 1286
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a number $A$ represented as a string of length $N$, we need to construct the smallest possible number $W$ of length $N+1$ such that removing exactly one digit from $W$ results in the original number $A$.

## Intuition & Mathematical Observation
To make $W$ as small as possible, we must focus on the most significant digits. We want the resulting number $W$ to be as small as possible while ensuring that removing one digit recovers $A$.

1.  **Case 1: The first digit of $A$ is '1'.**
    If we prepend '1' to $A$, we get $11...$, which is larger than inserting '0' after the first digit. By inserting '0' immediately after the first digit (e.g., $123 \to 1023$), we keep the leading digit as '1' and minimize the second digit. Removing the '0' recovers the original $A$.
    
2.  **Case 2: The first digit of $A$ is greater than '1'.**
    If we insert any digit other than '1' at the start, the number will be larger than if we simply prepend '1'. By prepending '1' (e.g., $987 \to 1987$), we create the smallest possible number of length $N+1$ that starts with '1'. Removing this leading '1' recovers the original $A$.

This greedy approach ensures that we always produce the smallest possible $W$ by manipulating the most significant positions.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of digits in $A$. We perform string concatenation and output, which takes linear time relative to the length of the string.
- **Space Complexity**: $O(N)$ to store the input string $A$ and the resulting string $W$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To make W as small as possible:
 * 1. If the first digit of A is '1', we insert '0' after the first digit.
 *    Example: 123 -> 1023. Removing '0' gives 123.
 * 2. If the first digit of A is > '1', we insert '1' at the very beginning.
 *    Example: 987 -> 1987. Removing '1' gives 987.
 */

void solve() {
    string A;
    cin >> A;

    if (A[0] == '1') {
        // Insert '0' after the first digit
        string W = A.substr(0, 1) + '0' + A.substr(1);
        cout << W << "\n";
    } else {
        // Insert '1' at the beginning
        string W = '1' + A;
        cout << W << "\n";
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