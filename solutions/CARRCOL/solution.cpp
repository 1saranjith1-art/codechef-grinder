#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bear patrols clearings [L, R].
 * The rabbit cannot visit any clearing in the range [L, R].
 * This effectively splits the forest into two potential disconnected segments:
 * 1. Clearings [1, L-1] (if L > 1)
 * 2. Clearings [R+1, N] (if R < N)
 * 
 * Since the rabbit can move freely within any connected component of non-patrolled clearings,
 * the rabbit can collect all carrots in any one of these components.
 * The problem asks for the maximum number of carrots the rabbit can collect.
 * 
 * Therefore, we calculate:
 * - Sum of carrots in [1, L-1] (if L > 1)
 * - Sum of carrots in [R+1, N] (if R < N)
 * The answer is the maximum of these two sums.
 */

void solve() {
    int N, L, R;
    cin >> N >> L >> R;
    vector<long long> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long sum_left = 0;
    long long sum_right = 0;

    // Calculate sum of carrots in the left segment [1, L-1]
    if (L > 1) {
        for (int i = 1; i < L; ++i) {
            sum_left += A[i];
        }
    } else {
        // If no left segment exists, set to -1 so it's not chosen
        sum_left = -1;
    }

    // Calculate sum of carrots in the right segment [R+1, N]
    if (R < N) {
        for (int i = R + 1; i <= N; ++i) {
            sum_right += A[i];
        }
    } else {
        // If no right segment exists, set to -1 so it's not chosen
        sum_right = -1;
    }

    cout << max(sum_left, sum_right) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}