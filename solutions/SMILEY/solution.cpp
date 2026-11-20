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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}