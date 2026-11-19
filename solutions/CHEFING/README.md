# [Chef and Secret Ingredients (CHEFING)](https://www.codechef.com/problems/CHEFING)

- **Difficulty Rating**: 1376
- **Solved in**: 2 attempt(s)

## Problem Summary
Given $N$ strings, we need to identify the number of unique characters that appear in **every single one** of the $N$ strings. A character is considered a "secret ingredient" if it is present in all provided strings at least once.

## Intuition & Mathematical Observation
The problem asks for the intersection of the sets of characters present in each string. 

1. **Set Intersection**: If we represent each string as a set of its unique characters, we are looking for the size of the intersection of these $N$ sets.
2. **Boolean Array Approach**: Since the alphabet size is small (only 26 lowercase English letters), we can maintain a boolean array `is_special` of size 26, initialized to `true`.
3. **Filtering**: For each string, we identify which characters are present. We then perform a logical `AND` operation: if a character was previously considered "special" but is missing from the current string, we mark it as `false`.
4. **Final Count**: After processing all $N$ strings, the number of `true` values remaining in our `is_special` array represents the total count of secret ingredients.

## Complexity Analysis
- **Time Complexity**: $O(N \times L + N \times 26)$, where $N$ is the number of strings and $L$ is the average length of a string. We iterate through each character of every string once, and perform a constant-time update (26 iterations) for each string.
- **Space Complexity**: $O(1)$ (or $O(26)$), as we only use a fixed-size boolean array regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

/**
 * Problem Analysis:
 * We need to find characters present in every string.
 * 
 * Optimization:
 * 1. Use a global frequency array (or a static one) to avoid repeated allocations.
 * 2. Use fast I/O (already present).
 * 3. Instead of counting occurrences, we can use a bitmask or a boolean array 
 *    that is initialized to true for all 26 characters, then perform a logical 
 *    AND with the presence of characters in each string.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    // is_special[i] will be true if character ('a' + i) is in all strings processed so far.
    bool is_special[26];
    for (int i = 0; i < 26; ++i) is_special[i] = true;
    
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        
        bool current_present[26] = {false};
        for (char c : s) {
            current_present[c - 'a'] = true;
        }
        
        // Update the global special status
        for (int j = 0; j < 26; ++j) {
            if (!current_present[j]) {
                is_special[j] = false;
            }
        }
    }
    
    int special_ingredients = 0;
    for (int j = 0; j < 26; ++j) {
        if (is_special[j]) {
            special_ingredients++;
        }
    }
    
    cout << special_ingredients << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```