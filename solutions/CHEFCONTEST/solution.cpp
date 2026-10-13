#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef's penalty = X + (P * 10)
 * Chefina's penalty = Y + (Q * 10)
 * We compare these two values.
 * Constraints: X, Y, P, Q <= 100. Max penalty = 100 + 1000 = 1100.
 * Standard 'int' is perfectly sufficient.
 */

void solve() {
    int X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    int chef_penalty = X + (P * 10);
    int chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}