#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let N = 2^k * m, where m is an odd integer.
 * The odd divisors of N are exactly the divisors of m.
 * Let d(m) be the number of divisors of m. Then A = d(m).
 * Since m is odd, m >= 1, so A must be at least 1.
 * If A = 0, it's impossible because 1 is always an odd divisor of any N.
 * 
 * The even divisors of N are of the form 2^i * d, where 1 <= i <= k and d is a divisor of m.
 * The number of such divisors is B = k * d(m) = k * A.
 * 
 * Case 1: A = 0.
 * Impossible, as 1 is always an odd divisor. Output: No.
 * 
 * Case 2: A > 0.
 * We need to find if there exists k >= 0 such that k * A = B.
 * - If B = 0:
 *   This implies k = 0. N = 2^0 * m = m.
 *   Any odd m has A divisors. Since we can choose m to have any number of divisors A >= 1
 *   (e.g., m = 3^(A-1)), this is always possible. Output: Yes.
 * - If B > 0:
 *   We need k * A = B. This is possible if and only if B is divisible by A.
 *   Since A >= 1, we just check if B % A == 0. Output: Yes if B % A == 0, else No.
 */

void solve() {
    long long A, B;
    cin >> A >> B;

    if (A == 0) {
        cout << "No" << "\n";
    } else {
        if (B == 0) {
            cout << "Yes" << "\n";
        } else {
            if (B % A == 0) {
                cout << "Yes" << "\n";
            } else {
                cout << "No" << "\n";
            }
        }
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