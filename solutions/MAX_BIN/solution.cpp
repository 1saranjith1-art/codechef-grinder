#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * To maximize the decimal value of a binary string:
 * 1. The most significant bit (the leftmost bit) has the highest impact.
 * 2. If the first character is '0', changing it to '1' (Type 2 operation) is the 
 *    most effective way to increase the value, as it adds 2^(N-1).
 * 3. Adding '0's at the end of the string (Type 1 operation) effectively multiplies 
 *    the current value by 2 for each '0' added, which is always optimal for 
 *    increasing the magnitude of the number.
 * 
 * Strategy:
 * - If K > 0 and S[0] == '0', use one Type 2 operation to change S[0] to '1'. 
 *   Decrement K.
 * - Use all remaining K operations to append '0's to the end of the string.
 *   This is always better than changing internal '0's to '1's because appending 
 *   a '0' shifts all existing bits to the left, increasing their power of 2.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    // If the first bit is '0', prioritize changing it to '1'
    if (S[0] == '0' && K > 0) {
        S[0] = '1';
        K--;
    }

    // Append K zeros to the end of the string
    // Appending zeros is always optimal because it shifts the existing 
    // bits to higher powers of 2.
    string zeros(K, '0');
    cout << S << zeros << "\n";
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