#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have a right-angled triangle (or two) formed by the ladder sides and the ground.
 * Let B be the base (separation), LS be the length of the left side, and RS be the length of the right side.
 * Let H be the height of the apex of the ladder from the ground.
 * 
 * Case 1: Minimum RS
 * This occurs when the LS is the hypotenuse of a right triangle with base B and height H.
 * H^2 + B^2 = LS^2  => H = sqrt(LS^2 - B^2)
 * Then, for the RS, we have RS^2 = H^2 + 0^2 (if RS is vertical, but the problem implies 
 * the apex is fixed at height H). Actually, the minimum RS occurs when the apex is 
 * as low as possible. If LS is the hypotenuse, H = sqrt(LS^2 - B^2).
 * The minimum RS is when the RS is vertical, so RS = H = sqrt(LS^2 - B^2).
 * 
 * Case 2: Maximum RS
 * This occurs when the LS is vertical, forming a right triangle with base B and hypotenuse RS.
 * RS^2 = B^2 + LS^2 => RS = sqrt(B^2 + LS^2)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        double b, ls;
        cin >> b >> ls;

        // Minimum RS: sqrt(LS^2 - B^2)
        // Maximum RS: sqrt(LS^2 + B^2)
        double min_rs = sqrt(max(0.0, ls * ls - b * b));
        double max_rs = sqrt(ls * ls + b * b);

        cout << fixed << setprecision(5) << min_rs << " " << max_rs << "\n";
    }

    return 0;
}