#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The grid is defined as -10 <= x, y <= 10.
 * Total possible x values: -10, -9, ..., 0, ..., 9, 10 (21 values)
 * Total possible y values: -10, -9, ..., 0, ..., 9, 10 (21 values)
 * 
 * Let L, R, U, D be the boolean flags for Left, Right, Up, Down.
 * - If only L is allowed: x can be -10 to 0, y=0. Count = 11.
 * - If only R is allowed: x can be 0 to 10, y=0. Count = 11.
 * - If only U is allowed: x=0, y can be 0 to 10. Count = 11.
 * - If only D is allowed: x=0, y can be -10 to 0. Count = 11.
 * 
 * Combinations:
 * 1. L and R: x in [-10, 10], y=0. Count = 21.
 * 2. U and D: x=0, y in [-10, 10]. Count = 21.
 * 3. L and U: x in [-10, 0], y in [0, 10]. Count = 11 * 11 = 121.
 * 4. L and D: x in [-10, 0], y in [-10, 0]. Count = 11 * 11 = 121.
 * 5. R and U: x in [0, 10], y in [0, 10]. Count = 11 * 11 = 121.
 * 6. R and D: x in [0, 10], y in [-10, 0]. Count = 11 * 11 = 121.
 * 7. L, R, U: x in [-10, 10], y in [0, 10]. Count = 21 * 11 = 231.
 * 8. L, R, D: x in [-10, 10], y in [-10, 0]. Count = 21 * 11 = 231.
 * 9. L, U, D: x in [-10, 0], y in [-10, 10]. Count = 11 * 21 = 231.
 * 10. R, U, D: x in [0, 10], y in [-10, 10]. Count = 11 * 21 = 231.
 * 11. L, R, U, D: x in [-10, 10], y in [-10, 10]. Count = 21 * 21 = 441.
 */

void solve() {
    string s;
    cin >> s;
    int L = s[0] - '0';
    int R = s[1] - '0';
    int U = s[2] - '0';
    int D = s[3] - '0';

    int x_min = L ? -10 : 0;
    int x_max = R ? 10 : 0;
    int y_min = D ? -10 : 0;
    int y_max = U ? 10 : 0;

    // If only one direction is allowed, the range is 0 to 10 or -10 to 0 (11 values)
    // If opposite directions are allowed, range is -10 to 10 (21 values)
    // If perpendicular directions are allowed, it forms a quadrant (11*11 values)
    
    int x_count = (x_min == 0 && x_max == 0) ? 1 : (x_max - x_min + 1);
    int y_count = (y_min == 0 && y_max == 0) ? 1 : (y_max - y_min + 1);

    cout << x_count * y_count << "\n";
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