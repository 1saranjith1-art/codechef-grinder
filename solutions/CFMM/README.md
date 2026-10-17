# [Making a Meal (CFMM)](https://www.codechef.com/problems/CFMM)

- **Difficulty Rating**: 1214
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $N$ strings, we need to determine the maximum number of times the word **"codechef"** can be formed using the characters available across all the provided strings. Each character from the input strings can be used only once.

## Intuition & Mathematical Observation
To form one instance of the word "codechef", we require the following character frequencies:
- **c**: 2
- **o**: 1
- **d**: 1
- **e**: 2
- **h**: 1
- **f**: 1

The strategy is to aggregate the total count of every character present in all $N$ input strings. Once we have the total counts, we calculate how many times each required character can satisfy the "codechef" requirement:
- For 'c' and 'e', we divide their total counts by 2 (since we need two of each per word).
- For 'o', 'd', 'h', and 'f', we use their total counts as is.

The final answer is the **minimum** value among these calculated ratios, as the character with the lowest relative availability acts as the "limiting reagent" for forming the word.

## Complexity Analysis
- **Time Complexity**: $O(S)$, where $S$ is the total number of characters across all $N$ strings. We iterate through each character exactly once to populate the frequency map.
- **Space Complexity**: $O(1)$, because the frequency map stores at most 26 lowercase English characters, which is a constant space requirement regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To form the string "codechef", we need the following counts of characters:
 * 'c': 2, 'o': 1, 'd': 1, 'e': 2, 'h': 1, 'f': 1
 * 
 * We count the total occurrences of each character in all input strings.
 * The maximum number of "codechef" meals is determined by the limiting character.
 */

void solve() {
    int n;
    cin >> n;
    
    map<char, int> counts;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            counts[c]++;
        }
    }
    
    // Calculate how many full sets of each character we have for "codechef"
    int c = counts['c'] / 2;
    int o = counts['o'];
    int d = counts['d'];
    int e = counts['e'] / 2;
    int h = counts['h'];
    int f = counts['f'];
    
    // The limiting factor determines the total number of meals
    int ans = min({c, o, d, e, h, f});
    cout << ans << "\n";
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