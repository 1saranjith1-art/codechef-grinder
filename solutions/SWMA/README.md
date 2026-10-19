# [Swapping Marks Digits (SWMA)](https://www.codechef.com/problems/SWMA)

- **Difficulty Rating**: 964
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob each have a 2-digit score (given as $A$ and $B$, where neither contains the digit '0'). Alice is allowed to reverse the digits of her score, Bob's score, both, or neither. Alice wins if, after any of these four possible transformations, her score is strictly greater than Bob's score. We need to determine if it is possible for Alice to win.

## Intuition & Mathematical Observation
Since the scores are always 2-digit numbers, there are only four possible states for the pair of scores $(A', B')$:
1. $(A, B)$
2. $(A_{reversed}, B)$
3. $(A, B_{reversed})$
4. $(A_{reversed}, B_{reversed})$

Because the number of scenarios is constant (exactly 4), we do not need complex logic or loops. We can simply calculate the reversed values of $A$ and $B$ using basic arithmetic:
- `reversed = (number % 10) * 10 + (number / 10)`

After calculating the reversed values, we check the condition $A' > B'$ for all four combinations. If any of these conditions evaluate to true, Alice can win, and we output "Yes". Otherwise, we output "No".

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a fixed number of arithmetic operations and comparisons regardless of the input values, the time complexity is constant.
- **Space Complexity**: $O(1)$. We only use a few integer variables to store the scores and their reversed versions, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has score A, Bob has score B. Both are 2-digit numbers without 0.
 * Alice can reverse her score (A_rev) and/or Bob's score (B_rev).
 * There are 4 possible scenarios for the final scores (A', B'):
 * 1. (A, B)
 * 2. (A_rev, B)
 * 3. (A, B_rev)
 * 4. (A_rev, B_rev)
 * Alice wins if in any of these scenarios, A' > B'.
 */

int reverse_num(int n) {
    int tens = n / 10;
    int units = n % 10;
    return units * 10 + tens;
}

void solve() {
    int A, B;
    cin >> A >> B;

    int A_rev = reverse_num(A);
    int B_rev = reverse_num(B);

    // Check all 4 combinations
    if (A > B || A_rev > B || A > B_rev || A_rev > B_rev) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
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