# [Schrodinger Smiley (SMILEY)](https://www.codechef.com/problems/SMILEY)

- **Difficulty Rating**: 1371
- **Solved in**: 3 attempt(s)

## Problem Summary
The goal is to count the number of "smileys" in a given string $S$. A smiley is defined as a sequence starting with a colon `:`, followed by one or more closing parentheses `)`, and ending with another colon `:`. Crucially, the sequence cannot contain any opening parentheses `(` between the two colons.

## Intuition & Mathematical Observation
The constraint that no `(` can exist between the two colons is the key to the problem. This means that any valid smiley must exist entirely within a substring that does not contain the character `(`.

1. **Segmentation**: We can split the string into segments using `(` as a delimiter. Any valid smiley must be contained within one of these segments.
2. **State Tracking**: Within each segment (which consists only of `:` and `)`), we need to identify patterns of `: ) ... ) :`.
3. **Greedy Approach**: 
   - We iterate through the segment and keep track of the most recent colon encountered.
   - If we encounter a `)`, we mark that a bracket has been seen since the last colon.
   - If we encounter another `:`, and we have already seen a `)` since the previous `:`, we have successfully formed a smiley. We increment our count and reset the state to look for the next smiley starting from this current colon.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We traverse the string exactly once to process segments and characters.
- **Space Complexity**: $O(1)$ (excluding the input string storage), as we only use a few integer and boolean variables to track the state.

## Solution Code

```cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * Logic:
 * 1. Split the string by '('.
 * 2. For each segment, we look for valid smileys.
 * 3. A segment is a sequence of ':' and ')'.
 * 4. A smiley is defined as :...: with at least one ')' inside.
 * 5. Within a segment, we can maintain the state:
 *    - 'last_colon_idx': the index of the most recent ':'
 *    - 'has_bracket': boolean, true if a ')' has been seen since 'last_colon_idx'
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long total_smileys = 0;
    int start = 0;
    
    // Process segments separated by '('
    for (int i = 0; i <= n; ++i) {
        if (i == n || s[i] == '(') {
            // Process segment s[start...i-1]
            int last_colon = -1;
            bool has_bracket = false;
            
            for (int j = start; j < i; ++j) {
                if (s[j] == ':') {
                    if (has_bracket) {
                        total_smileys++;
                    }
                    last_colon = j;
                    has_bracket = false; // Reset bracket status for the next potential smiley
                } else if (s[j] == ')') {
                    if (last_colon != -1) {
                        has_bracket = true;
                    }
                }
            }
            start = i + 1;
        }
    }
    cout << total_smileys << "\n";
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