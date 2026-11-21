#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A string P of length N is a palindrome if P[i] == P[N-1-i] for all 0 <= i < N.
 * Given S, we need to determine if there is exactly one way to fill the '?'
 * such that the resulting string is a palindrome.
 * 
 * For each pair of indices (i, N-1-i):
 * 1. If both S[i] and S[N-1-i] are '?', we have 26 choices (a-z) for this pair.
 *    If there is at least one such pair, there are multiple palindromes, so NO.
 * 2. If one is '?' and the other is a character, the '?' is forced to be that character.
 * 3. If both are characters, they must match (guaranteed by problem statement).
 * 
 * Special case: If N is odd, the middle element (index N/2) is its own mirror.
 * If S[N/2] is '?', it can be any of the 26 characters.
 * 
 * Conclusion:
 * The palindrome is uniquely determined if and only if every pair (i, N-1-i)
 * has at least one fixed character, AND if N is odd, the middle element is fixed.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    bool unique = true;
    
    // Check pairs (i, N-1-i)
    for (int i = 0; i < N / 2; ++i) {
        if (S[i] == '?' && S[N - 1 - i] == '?') {
            unique = false;
            break;
        }
    }

    // Check middle element if N is odd
    if (N % 2 != 0) {
        if (S[N / 2] == '?') {
            unique = false;
        }
    }

    if (unique) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}