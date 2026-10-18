#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A bishop moves along diagonals.
 * Two cells (x1, y1) and (x2, y2) are on the same diagonal if:
 * 1. x1 + y1 == x2 + y2 (anti-diagonal)
 * 2. x1 - y1 == x2 - y2 (main diagonal)
 * 
 * If they are on the same diagonal, the bishop reaches in 1 move.
 * If they are not on the same diagonal, we check if they are reachable.
 * A bishop can only reach squares of the same color as the starting square.
 * The color of a square (x, y) is determined by (x + y) % 2.
 * If (x1 + y1) % 2 != (x2 + y2) % 2, it is impossible (-1).
 * If they are the same color and not on the same diagonal, it takes exactly 2 moves.
 */

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    // Check if same diagonal
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << 1 << "\n";
    } 
    // Check if same color
    else if ((x1 + y1) % 2 == (x2 + y2) % 2) {
        cout << 2 << "\n";
    } 
    // Different colors, impossible for a bishop
    else {
        cout << -1 << "\n";
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