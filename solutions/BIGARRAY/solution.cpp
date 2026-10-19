#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * We are looking for an index x such that:
 * (Sum of all elements except A[x]) = S
 * (TotalSum - x) = S
 * Therefore, x = TotalSum - S.
 * 
 * Constraints:
 * 1 <= x <= N
 * 1 <= N <= 10^9
 * 1 <= S <= 10^18
 * 
 * Since N can be 10^9, TotalSum can be approximately (10^9 * 10^9) / 2 = 5 * 10^17.
 * This fits within a 64-bit signed integer (long long in C++).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate total sum of 1 to N
        // Use long long to prevent overflow
        long long total_sum = n * (n + 1) / 2;

        // The equation is: total_sum - x = s
        // So, x = total_sum - s
        long long x = total_sum - s;

        // Check if x is a valid index (1 <= x <= N)
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}