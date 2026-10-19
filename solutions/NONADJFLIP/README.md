# [Non Adjacent Flips (NONADJFLIP)](https://www.codechef.com/problems/NONADJFLIP)

- **Difficulty Rating**: 1128
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we want to transform it into a string of all '0's. In one operation, we can choose a set of indices such that no two chosen indices are adjacent, and flip the bits at those positions (0 becomes 1, 1 becomes 0). We need to find the minimum number of operations required to make the string all '0's.

## Intuition & Mathematical Observation
The problem asks for the minimum number of operations to clear all '1's. Let's analyze the constraints:

1.  **0 Operations**: If the string contains no '1's, the string is already cleared.
2.  **1 Operation**: If there are no adjacent '1's in the string, we can simply select all indices where $S[i] == '1'$ and flip them in a single operation. Since no two '1's are adjacent, this set of indices is valid.
3.  **2 Operations**: If there are adjacent '1's, we cannot clear them in one operation. However, we can always clear any binary string in at most 2 operations. 
    *   We can split the indices into two sets: those at even positions and those at odd positions. 
    *   Since no two even positions are adjacent and no two odd positions are adjacent, we can flip all '1's at even positions in one operation and all '1's at odd positions in the second operation.
    *   Therefore, if the string contains adjacent '1's, the answer is always 2.

**Summary of Logic:**
- If the string has no '1's: **0**
- If the string has '1's but no adjacent '1's: **1**
- If the string has at least one pair of adjacent '1's: **2**

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to check for the presence of '1's and adjacent '1's.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. If the string is all '0's, 0 operations are needed.
 * 2. If there are no adjacent '1's, we can flip all '1's in a single operation.
 * 3. If there are adjacent '1's, we need 2 operations. 
 *    We can clear all '1's at even indices in one op and odd indices in another.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool has_one = false;
    bool has_adjacent_ones = false;

    for (int i = 0; i < N; ++i) {
        if (S[i] == '1') {
            has_one = true;
            if (i > 0 && S[i - 1] == '1') {
                has_adjacent_ones = true;
            }
        }
    }

    if (!has_one) {
        cout << 0 << "\n";
    } else if (has_adjacent_ones) {
        // If there are adjacent 1s, 2 operations are always sufficient.
        cout << 2 << "\n";
    } else {
        // If there are 1s but no adjacent ones, 1 operation is sufficient.
        cout << 1 << "\n";
    }
}

int main() {
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