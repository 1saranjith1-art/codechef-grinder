# [Counting Characters (COUNTAB)](https://www.codechef.com/problems/COUNTAB)

- **Difficulty Rating**: 541
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ consisting of lowercase English letters, the task is to count the total number of occurrences of the character `'a'` and the character `'b'` within the string.

## Intuition & Mathematical Observation
The problem is a straightforward frequency counting task. Since we only care about two specific characters, we can iterate through the string once and maintain two separate counters:
1. `count_a`: Incremented whenever the current character is `'a'`.
2. `count_b`: Incremented whenever the current character is `'b'`.

Because the constraints are small and the logic is linear, a simple single-pass loop is the most efficient approach. Using Fast I/O (`ios_base::sync_with_stdio(false); cin.tie(NULL);`) ensures that the solution handles large inputs within the time limits.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We traverse the string exactly once to count the characters.
- **Space Complexity**: $O(N)$ to store the input string $S$. If we processed the string character by character without storing it, this could be reduced to $O(1)$, but $O(N)$ is well within the memory limits.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: COUNTAB
 * The task is to count the occurrences of 'a' and 'b' in a given string S of length N.
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long count_a = 0;
    long long count_b = 0;

    // Iterate through the string and update counters
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }

    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Fast I/O setup for performance
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