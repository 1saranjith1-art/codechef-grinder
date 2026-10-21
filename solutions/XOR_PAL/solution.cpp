#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to make the string a palindrome. A string is a palindrome if A[i] == A[N-1-i] for all i.
 * Let's look at pairs (A[i], A[N-1-i]).
 * If A[i] == A[N-1-i], these positions are already "palindromic".
 * If A[i] != A[N-1-i], these positions are "mismatched".
 * 
 * Let 'diff' be the number of indices i < N/2 such that A[i] != A[N-1-i].
 * Each operation can fix at most one mismatched pair.
 * Specifically, if we have a mismatch (0, 1), we can perform an operation to make both 0 or both 1.
 * Thus, we need at least 'diff' operations to fix all mismatches.
 * 
 * After fixing all 'diff' mismatches, we have a palindrome.
 * If N is odd, the middle element doesn't affect the palindrome property.
 * If N is even, we might need more operations if we have pairs that are already equal but could be changed.
 * However, the problem asks for the minimum operations.
 * If we have 'diff' mismatches, we can fix them in 'diff' operations.
 * If 'diff' is 0, the string is already a palindrome (0 operations).
 * If 'diff' > 0, we can resolve all mismatches in 'diff' operations.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    int diff = 0;
    for (int i = 0; i < N / 2; ++i) {
        if (A[i] != A[N - 1 - i]) {
            diff++;
        }
    }

    // Each operation can fix one pair of mismatched characters.
    // If we have 'diff' pairs that are different, we need exactly 'diff' operations
    // to make them all match.
    // The result is simply ceil(diff / 2.0) if we consider we can fix two mismatches 
    // at once, but the operation definition says we change A[i] and A[j] to A[i] ^ A[j].
    // Actually, one operation on a mismatched pair (0, 1) makes them (1, 1) or (0, 0).
    // So one operation fixes exactly one mismatched pair.
    
    cout << (diff + 1) / 2 << "\n";
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