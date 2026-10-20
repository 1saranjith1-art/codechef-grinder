#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Total work in home-hours = (A1 + A2 + A3 + A4 + A5) * P
 * Total available hours in a week = 5 days * 24 hours/day = 120 hours.
 * If total work > 120, Chef must work on weekends.
 */

void solve() {
    int A[5];
    int P;
    int sum_A = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> A[i];
        sum_A += A[i];
    }
    cin >> P;

    if (sum_A * P > 120) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
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