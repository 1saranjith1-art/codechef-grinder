#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Logic:
 * Each pair of yellow cards causes a send-off.
 * Each red card causes a send-off.
 * A red card can "absorb" one yellow card (by resetting the count).
 * Total send-offs = R + (Y - min(Y, R)) / 2.
 */

void solve() {
    int R, Y;
    if (!(cin >> R >> Y)) return;

    int absorbed = min(Y, R);
    int remaining_y = Y - absorbed;
    int sendoffs = R + (remaining_y / 2);
    
    cout << sendoffs << "\n";
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