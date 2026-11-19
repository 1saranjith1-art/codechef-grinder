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