#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to construct a palindrome of length N with exactly X distinct characters.
 * 
 * A palindrome is determined by its first ceil(N/2) characters.
 * Let K = ceil(N/2). These K characters must contain exactly X distinct characters.
 * 
 * Constraints:
 * 1. We can use at most 26 distinct characters.
 * 2. The number of distinct characters X must satisfy X <= K.
 *    If X > ceil(N/2), it is impossible because the second half is a mirror of the first.
 * 
 * Construction Strategy:
 * 1. If X > (N + 1) / 2, output -1.
 * 2. Otherwise, fill the first ceil(N/2) positions using X distinct characters.
 *    To ensure we use exactly X characters, we can use the first X-1 characters as 
 *    'a', 'b', ..., and fill the remaining positions of the first half with the X-th character.
 * 3. Mirror the first half to form the full palindrome.
 */

void solve() {
    int N, X;
    cin >> N >> X;

    int half_len = (N + 1) / 2;

    if (X > half_len) {
        cout << -1 << "\n";
        return;
    }

    string s(N, ' ');
    // Fill the first half
    for (int i = 0; i < half_len; ++i) {
        if (i < X - 1) {
            s[i] = (char)('a' + i);
        } else {
            s[i] = (char)('a' + X - 1);
        }
    }

    // Mirror to the second half
    for (int i = 0; i < N / 2; ++i) {
        s[N - 1 - i] = s[i];
    }

    cout << s << "\n";
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