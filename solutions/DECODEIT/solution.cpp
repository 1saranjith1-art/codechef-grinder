#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem describes a binary encoding scheme for the first 16 lowercase English letters ('a' through 'p').
 * Each character is represented by 4 bits.
 * The encoding is essentially a binary representation of the index of the character (0-15).
 * For example:
 * 'a' is index 0: 0000
 * 'b' is index 1: 0001
 * ...
 * 'j' is index 9: 1001
 * 'p' is index 15: 1111
 * 
 * Since each 4-bit block corresponds to an integer from 0 to 15, we can convert 
 * each 4-bit substring into its decimal equivalent and map it to the corresponding 
 * character ('a' + decimal_value).
 * 
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the input string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    string result = "";
    // Process the string in chunks of 4 bits
    for (int i = 0; i < n; i += 4) {
        int val = 0;
        // Convert 4-bit binary string to integer
        // bit 0: 2^3, bit 1: 2^2, bit 2: 2^1, bit 3: 2^0
        for (int j = 0; j < 4; ++j) {
            val = (val << 1) | (s[i + j] - '0');
        }
        // Map integer 0-15 to 'a'-'p'
        result += (char)('a' + val);
    }
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}