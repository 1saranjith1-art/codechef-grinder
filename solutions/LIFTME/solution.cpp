#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The lift starts at floor 0.
 * For each request (f_i, d_i):
 * 1. The lift moves from its current position (let's call it 'curr') to f_i.
 *    Distance traveled: |f_i - curr|
 * 2. The lift moves from f_i to d_i.
 *    Distance traveled: |d_i - f_i|
 * 3. Update 'curr' to d_i.
 * 
 * Total distance is the sum of these movements for all Q requests.
 * Since N <= 10^6 and Q <= 10^5, the total distance can exceed 2^31 - 1.
 * We must use 'long long' to store the total distance.
 * Time complexity per test case: O(Q)
 * Total time complexity: O(sum of Q), which is 10^5, well within the 1s limit.
 */

void solve() {
    int N, Q;
    if (!(cin >> N >> Q)) return;

    long long total_distance = 0;
    int current_floor = 0;

    for (int i = 0; i < Q; ++i) {
        int f, d;
        cin >> f >> d;

        // Distance to move to source floor
        total_distance += abs(f - current_floor);
        // Distance to move to destination floor
        total_distance += abs(d - f);

        // Update current floor to the destination
        current_floor = d;
    }

    cout << total_distance << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}