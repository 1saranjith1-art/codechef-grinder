# [Xor Palindrome (XOR_PAL)](https://www.codechef.com/problems/XOR_PAL)

- **Difficulty Rating**: 1129
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $A$ of length $N$, we are allowed to perform an operation where we choose two indices $i$ and $j$ and replace $A[i]$ and $A[j]$ with $A[i] \oplus A[j]$. We need to find the minimum number of operations required to make the string a palindrome.

## Intuition & Mathematical Observation
To make a string a palindrome, every pair of characters at symmetric positions $(A[i], A[N-1-i])$ must be equal. 

1. **Identify Mismatches**: We iterate through the first half of the string ($0$ to $N/2 - 1$) and count how many pairs $(A[i], A[N-1-i])$ are not equal. Let this count be `diff`.
2. **Analyze the Operation**:
   - If $A[i] \neq A[N-1-i]$, we have a mismatch (e.g., one is '0' and the other is '1'). Applying the XOR operation on these two indices will result in both becoming '1' (since $0 \oplus 1 = 1$). This effectively fixes the mismatch in one operation.
   - If we have `diff` such mismatched pairs, we need `diff` operations to fix them.
   - However, the problem allows us to perform the operation on *any* two indices. If we have two mismatched pairs, we can potentially resolve them efficiently. 
   - Mathematically, each operation can resolve two mismatches if we pair them correctly, or one mismatch if we target a single pair. The minimum number of operations required to resolve `diff` mismatches is $\lceil \text{diff} / 2 \rceil$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string, as we perform a single pass over the first half of the string.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A string is a palindrome if A[i] == A[N-1-i] for all i.
 * We count the number of mismatched pairs (diff).
 * Each operation can fix up to 2 mismatched pairs.
 * Therefore, the minimum operations required is ceil(diff / 2).
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    // Count pairs that are not equal
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can resolve 2 mismatches.
    // Using integer division, (diff + 1) / 2 is equivalent to ceil(diff / 2.0).
    cout << (diff + 1) / 2 << "\n";
}

int main() {
    // Optimize I/O operations
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