# [Balanced Reversals (BALREV)](https://www.codechef.com/problems/BALREV)

- **Difficulty Rating**: 1165
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we are allowed to perform an operation where we choose any substring that contains an equal number of '0's and '1's and reverse it. The goal is to find the lexicographically smallest string possible after performing any number of these operations.

## Intuition & Mathematical Observation
The key observation is that the allowed operation (reversing a balanced substring) is highly flexible. In a binary string, a substring is "balanced" if it has an equal number of 0s and 1s. 

By repeatedly applying this operation, we can effectively swap adjacent '0's and '1's. Specifically, if we have a '1' followed by a '0' (i.e., "10"), this substring is balanced. Reversing it gives "01". Since we can perform this operation on any balanced substring, we can move all '0's to the front of the string and all '1's to the back.

The lexicographically smallest string for any binary string is the one where all '0's appear before all '1's. Since the operation allows us to reach this configuration, the problem reduces to simply counting the total number of '0's and '1's in the input string and constructing a new string consisting of all '0's followed by all '1's.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string once to count the characters and once more to construct the result.
- **Space Complexity**: $O(N)$ to store the input string and the resulting output string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The operation allows us to reverse any substring that has an equal number of 0s and 1s.
 * This operation is powerful enough to allow us to rearrange the 0s and 1s in the string
 * such that all 0s come before all 1s.
 * 
 * Specifically, if we have a string with 'c0' zeros and 'c1' ones, we can always 
 * reach the state where all 'c0' zeros are at the beginning and all 'c1' ones are 
 * at the end.
 * 
 * The lexicographically smallest string for a binary string is simply the one 
 * where all 0s appear before all 1s.
 */

void solve() {
    int n;
    cin >> n;
    string a;
    cin >> a;

    int count0 = 0;
    int count1 = 0;

    // Count the occurrences of '0' and '1'
    for (char c : a) {
        if (c == '0') {
            count0++;
        } else {
            count1++;
        }
    }

    // The lexicographically smallest string is all 0s followed by all 1s.
    string result = "";
    for (int i = 0; i < count0; ++i) {
        result += '0';
    }
    for (int i = 0; i < count1; ++i) {
        result += '1';
    }

    cout << result << "\n";
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