#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * We want to maximize earnings.
 * 
 * Since Type 2 sessions are 2 hours long, we can take at most N/2 sessions of Type 2.
 * Let k be the number of Type 2 sessions (0 <= k <= N/2).
 * The remaining (N - 2*k) hours will be filled with Type 1 sessions.
 * Total earnings = k * Y + (N - 2*k) * X.
 * 
 * We want to maximize this expression.
 * Notice that if 2*X >= Y, it is always better or equal to take two Type 1 sessions 
 * instead of one Type 2 session. If 2*X < Y, it is better to take as many Type 2 
 * sessions as possible.
 * 
 * Actually, we can simply calculate the earnings for the maximum possible number 
 * of Type 2 sessions and fill the remainder with Type 1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // Number of 2-hour sessions we can fit
        long long num_type2 = n / 2;
        long long remaining_hours = n % 2;

        // Option 1: Maximize Type 2 sessions
        long long earnings_max_type2 = (num_type2 * y) + (remaining_hours * x);

        // Option 2: All Type 1 sessions
        long long earnings_all_type1 = n * x;

        // The answer is the maximum of these two strategies
        cout << max(earnings_max_type2, earnings_all_type1) << "\n";
    }

    return 0;
}