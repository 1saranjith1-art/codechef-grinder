#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The bus has N rows, each with M seats.
 * Seat X is in row R.
 * To find R:
 * Since row i contains seats (i-1)*M + 1 to i*M,
 * we can calculate R using integer division:
 * R = (X - 1) / M + 1.
 * 
 * If we enter from the front, we walk through rows 1, 2, ..., R.
 * The number of rows walked is R.
 * 
 * If we enter from the back, we walk through rows N, N-1, ..., R.
 * The number of rows walked is (N - R + 1).
 * 
 * We need the minimum of these two values: min(R, N - R + 1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;

        // Calculate the row number R (1-indexed)
        // Using long long to prevent any potential overflow, 
        // though constraints N, M <= 100 fit in int.
        long long r = (x - 1) / m + 1;

        // Distance from front: r
        // Distance from back: n - r + 1
        long long dist_front = r;
        long long dist_back = n - r + 1;

        // Output the minimum of the two distances
        cout << min(dist_front, dist_back) << "\n";
    }

    return 0;
}