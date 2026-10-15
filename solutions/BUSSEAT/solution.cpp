#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N rows, each with 2 seats. Total seats = 2N.
 * People enter one by one.
 * Strategy:
 * 1. People prefer to sit in an empty row (1 person per row).
 * 2. If no empty rows are available, they sit next to somebody (filling the second seat in a row).
 * 
 * Let N be the number of rows.
 * - The first N people will each take one row (if K >= N).
 * - If K <= N, everyone gets their own row, so 0 people sit next to somebody.
 * - If K > N, the first N people occupy one seat in each of the N rows.
 * - The remaining (K - N) people must sit in the empty seat of an already occupied row.
 * - Each of these (K - N) people will be sitting next to the person who arrived earlier in that row.
 * - Additionally, the (K - N) people who arrived earlier and were already sitting in those rows 
 *   will now have someone sitting next to them.
 * - Total people sitting next to someone = (K - N) * 2.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        if (k <= n) {
            // Everyone gets their own row, no one sits next to anyone.
            cout << 0 << "\n";
        } else {
            // First N people take one seat in each row.
            // Remaining (K - N) people fill the second seat in (K - N) rows.
            // In each of these (K - N) rows, there are now 2 people.
            // Total people sitting next to someone = 2 * (K - N).
            cout << 2 * (k - n) << "\n";
        }
    }

    return 0;
}