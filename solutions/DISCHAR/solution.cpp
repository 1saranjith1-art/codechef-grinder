#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find the size of the largest subsequence with all distinct characters.
 * Since a subsequence maintains the relative order of characters, if we have a string
 * like "aba", we can pick 'a' and 'b' to get "ab", which has distinct characters.
 * 
 * Key Insight:
 * To maximize the number of distinct characters in a subsequence, we simply need
 * to count how many unique characters exist in the original string.
 * If a character appears multiple times, we can only include it once in our 
 * subsequence to maintain the "distinct" property. Since we can pick any 
 * occurrence of a character, we can always include every unique character 
 * present in the string at least once.
 * 
 * Complexity:
 * Time: O(N) per test case, where N is the length of the string.
 * Space: O(1) auxiliary space (using a boolean array of size 26).
 */

void solve() {
    string s;
    cin >> s;
    
    // Use a boolean array to track which characters have appeared
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
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    
    return 0;
}