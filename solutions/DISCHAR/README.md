# [Distinct Characters Subsequence (DISCHAR)](https://www.codechef.com/problems/DISCHAR)

- **Difficulty Rating**: 1314
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$, we need to find the length of the longest subsequence that consists of only distinct characters. A subsequence is derived by deleting zero or more characters from the original string without changing the relative order of the remaining characters.

## Intuition & Mathematical Observation
The core requirement is to have a subsequence where every character appears exactly once. 

- If a character appears multiple times in the original string, we can only include it once in our subsequence to satisfy the "distinct" property.
- Since a subsequence allows us to pick any characters as long as we maintain their relative order, we can simply select one instance of every unique character present in the string.
- Therefore, the problem reduces to finding the **number of unique characters** in the given string. 
- Using a frequency array or a hash set to track characters encountered while iterating through the string allows us to count these unique occurrences efficiently.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once.
- **Space Complexity**: $O(1)$, as we use a fixed-size boolean array of size 26 to track the presence of lowercase English alphabets, regardless of the input string length.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the number of distinct characters in a subsequence, we simply need
 * to count how many unique characters exist in the original string.
 */

void solve() {
    string s;
    cin >> s;
    
    // Use a boolean array to track which characters have appeared
    // Since the string contains lowercase English letters, size 26 is sufficient.
    bool seen[26] = {false};
    int distinct_count = 0;
    
    for (char c : s) {
        if (!seen[c - 'a']) {
            seen[c - 'a'] = true;
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
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