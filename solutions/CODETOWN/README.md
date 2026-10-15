# [Reach Codetown (CODETOWN)](https://www.codechef.com/problems/CODETOWN)

- **Difficulty Rating**: 1022
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a string $S$ of length 8, determine if it is possible to transform $S$ into the target string `"CODETOWN"`. The transformation rule allows replacing a character at any position with another character, provided that the "vowel-ness" (whether the character is a vowel or a consonant) remains the same. Specifically, a vowel can only be replaced by a vowel, and a consonant can only be replaced by a consonant.

## Intuition & Mathematical Observation
The problem states that we can only replace a character if its type (vowel or consonant) is preserved. This implies that for the transformation to be possible, the input string $S$ must have the exact same vowel/consonant pattern as the target string `"CODETOWN"`.

1. **Identify the pattern of "CODETOWN":**
   - C (Consonant)
   - O (Vowel)
   - D (Consonant)
   - E (Vowel)
   - T (Consonant)
   - O (Vowel)
   - W (Consonant)
   - N (Consonant)
   
   The required pattern is: **C V C V C V C C**

2. **Algorithm:**
   - Define a helper function `isVowel(char c)` that returns `true` if the character is one of {'A', 'E', 'I', 'O', 'U'} and `false` otherwise.
   - Iterate through the input string $S$ from index 0 to 7.
   - For each index $i$, compare `isVowel(S[i])` with `isVowel(target[i])`.
   - If at any position the types do not match, the transformation is impossible. If all positions match, it is possible.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string (which is fixed at 8). Thus, the complexity is $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a constant amount of extra space for the target string and loop variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The rule states we can transition from T1 to T2 if:
 * 1. A consonant is replaced by a consonant.
 * 2. A vowel is replaced by a vowel.
 * 
 * This implies that the "vowel-ness" or "consonant-ness" of each position 
 * in the string must be identical between the starting string S and the 
 * target string "CODETOWN".
 */

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void solve() {
    string s;
    cin >> s;
    string target = "CODETOWN";
    
    bool possible = true;
    for (int i = 0; i < 8; ++i) {
        // Check if the type (vowel/consonant) matches at each position
        if (isVowel(s[i]) != isVowel(target[i])) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
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