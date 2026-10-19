#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X strings of "01" and Y strings of "10".
 * Let's denote "01" as A and "10" as B.
 * Each A contributes 1 to f(S) internally (0->1).
 * Each B contributes 1 to f(S) internally (1->0).
 * Total internal transitions = X + Y.
 * 
 * When we concatenate two strings, we might add an extra transition at the boundary:
 * - A + A: "01" + "01" -> "0101". Boundary is '1' to '0', transition added.
 * - A + B: "01" + "10" -> "0110". Boundary is '1' to '1', no transition.
 * - B + A: "10" + "01" -> "1001". Boundary is '0' to '0', no transition.
 * - B + B: "10" + "10" -> "1010". Boundary is '0' to '1', transition added.
 * 
 * We want to minimize the number of boundary transitions.
 * We have X blocks of A and Y blocks of B.
 * We can alternate them as much as possible to avoid transitions.
 * If we arrange them as A, B, A, B, ... or B, A, B, A, ...
 * The number of boundaries is (X + Y - 1).
 * 
 * If |X - Y| <= 1:
 * We can alternate perfectly (e.g., ABAB or BABA).
 * Total transitions = (X + Y) + 0 = X + Y.
 * 
 * If |X - Y| > 1:
 * We will have to place some identical blocks next to each other.
 * For example, if X > Y + 1, we must have at least (X - Y - 1) boundaries of type A+A.
 * Each A+A adds 1 transition.
 * Total transitions = (X + Y) + (X - Y - 1) = 2X - 1.
 * Similarly, if Y > X + 1, total transitions = (X + Y) + (Y - X - 1) = 2Y - 1.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (abs(X - Y) <= 1) {
        cout << X + Y << "\n";
    } else if (X > Y) {
        cout << 2 * X - 1 << "\n";
    } else {
        cout << 2 * Y - 1 << "\n";
    }
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