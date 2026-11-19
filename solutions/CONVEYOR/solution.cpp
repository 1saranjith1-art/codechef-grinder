#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem: CONVEYOR
 * Logic:
 * To reach the left end (0), all slots from 1 to P must be 'L'.
 * To reach the right end (N+1), all slots from P to N must be 'R'.
 * We calculate the number of changes needed for both paths and take the minimum.
 */

void solve() {
    int N, P;
    cin >> N >> P;
    string S;
    cin >> S;

    // S is 0-indexed, so slot i is S[i-1]
    
    // Cost to go Left: Need all slots from 1 to P to be 'L'
    int cost_left = 0;
    for (int i = 0; i < P; ++i) {
        if (S[i] == 'R') {
            cost_left++;
        }
    }

    // Cost to go Right: Need all slots from P to N to be 'R'
    int cost_right = 0;
    for (int i = P - 1; i < N; ++i) {
        if (S[i] == 'L') {
            cost_right++;
        }
    }

    cout << min(cost_left, cost_right) << endl;
}

int main() {
    // Optimize I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}