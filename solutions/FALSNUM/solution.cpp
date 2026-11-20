#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a number A of length N. We need to find the smallest number W of length N+1
 * such that deleting one digit from W results in the largest possible number A.
 * 
 * To make W as small as possible:
 * 1. We want the leading digit to be as small as possible.
 * 2. If we insert a digit 'd' at index 'i' to form W, the resulting A is formed by 
 *    removing that digit. To maximize A, we want to insert the smallest possible digit 
 *    at the earliest possible position such that the resulting sequence is lexicographically 
 *    largest.
 * 
 * Case 1: If the first digit of A is '1', we can insert '0' after the first digit.
 *         Example: 123 -> 1023. Removing '0' gives 123.
 * Case 2: If the first digit of A is > '1', we can insert '1' at the very beginning.
 *         Example: 987 -> 1987. Removing '1' gives 987.
 * 
 * This strategy ensures the smallest possible W because we prioritize keeping the 
 * leading digit small and placing the insertion as early as possible.
 */

void solve() {
    string A;
    cin >> A;

    if (A[0] == '1') {
        // Insert '0' after the first digit
        string W = A.substr(0, 1) + '0' + A.substr(1);
        cout << W << "\n";
    } else {
        // Insert '1' at the beginning
        string W = '1' + A;
        cout << W << "\n";
    }
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