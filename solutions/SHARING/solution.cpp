#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice has A cookies, Bob has B cookies. A > B.
 * Let x be the number of cookies Alice gives to Bob.
 * After the transfer:
 * Alice has A - x cookies.
 * Bob has B + x cookies.
 * For them to be equal: A - x = B + x
 * A - B = 2x
 * x = (A - B) / 2
 * 
 * For x to be a valid number of cookies (an integer), (A - B) must be even.
 * Also, x must be positive (since A > B, A - B > 0, so x > 0).
 * Additionally, Alice must have enough cookies to give, so x <= A.
 * Since x = (A - B) / 2 and A > B, x is always less than A.
 * 
 * Therefore, the condition is: (A - B) % 2 == 0.
 * If true, output (A - B) / 2.
 * Else, output -1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but the instructions mention handling multiple test cases.
    // Given the constraints and standard competitive programming patterns:
    int A, B;
    if (!(cin >> A >> B)) return 0;

    if ((A - B) % 2 == 0) {
        cout << (A - B) / 2 << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}