#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem: HATTRICK
 * Logic: We are given 6 inputs representing balls in an over.
 * A hattrick occurs if there are 3 consecutive 'W's.
 * We can check indices (0,1,2), (1,2,3), (2,3,4), and (3,4,5).
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check for 3 consecutive 'W's
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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