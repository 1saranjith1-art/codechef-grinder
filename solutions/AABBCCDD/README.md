# [AabBcCDd (AABBCCDD)](https://www.codechef.com/problems/AABBCCDD)
- **Difficulty Rating**: 972
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length $N$ consisting of uppercase and lowercase English letters, we are allowed to perform two types of operations:
1. Convert any uppercase letter to its lowercase equivalent.
2. Choose one lowercase letter and convert **all** its occurrences to any other lowercase letter.

The goal is to maximize the frequency of a single character after performing these operations.

## Intuition & Mathematical Observation
1. **Normalization**: Since we can convert all uppercase letters to lowercase, we can treat the string as if it only contains lowercase letters. We start by calculating the frequency of each character ('a' through 'z') in the string.
2. **Merging**: Operation 2 allows us to merge the counts of two different characters. If we have a character $X$ with frequency $f_1$ and a character $Y$ with frequency $f_2$, merging them results in a single character with frequency $f_1 + f_2$.
3. **Maximization**: To maximize the frequency of a single character, we should identify the two most frequent characters in the string and merge them. The result will be the sum of the two largest frequencies found in the frequency array. If the string contains only one type of character, the second largest frequency will be 0, which correctly leaves the original count unchanged.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string once to count frequencies and then perform a constant-time operation ($O(26)$) to find the two largest values.
- **Space Complexity**: $O(1)$, as we only use a fixed-size array of length 26 to store the character frequencies.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Operation 1: Convert any uppercase letter to its lowercase equivalent.
 *    This means we can effectively treat every uppercase letter 'X' as its lowercase 'x'.
 * 2. Operation 2: Choose one lowercase letter and convert ALL its occurrences to another lowercase letter.
 *    This means we can merge the counts of two different lowercase letters into one.
 * 
 * Strategy:
 * 1. Count the frequency of each character in the string, treating uppercase as lowercase.
 * 2. Find the two largest frequencies in the frequency array.
 * 3. The maximum possible frequency after one merge is the sum of these two largest values.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    vector<int> freq(26, 0);
    for (char c : S) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else {
            freq[c - 'a']++;
        }
    }

    // Find the two largest frequencies
    int max1 = 0, max2 = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[i] > max1) {
            max2 = max1;
            max1 = freq[i];
        } else if (freq[i] > max2) {
            max2 = freq[i];
        }
    }

    // The result is the sum of the two largest frequencies.
    cout << max1 + max2 << "\n";
}

int main() {
    // Optimize I/O operations
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