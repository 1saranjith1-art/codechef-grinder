#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Base fuel economy is M km/l (for 1 person).
 * - Every extra passenger decreases fuel economy by 1 km/l.
 * - Total people = P.
 * - Extra passengers = P - 1.
 * - Effective fuel economy = M - (P - 1).
 * - Total fuel = V litres.
 * - Max distance = Effective fuel economy * V.
 * 
 * Constraints:
 * T <= 3*10^4, P <= 5, M <= 56, V <= 100.
 * The result will fit in a standard integer, but using long long is safe.
 * Time complexity per test case: O(1).
 * Total time complexity: O(T).
 */

int main() {
    // Optimize standard I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long P, M, V;
        cin >> P >> M >> V;

        // Calculate effective fuel economy
        // The driver is 1 person, so there are (P - 1) extra passengers.
        long long effective_economy = M - (P - 1);

        // Calculate maximum distance
        long long max_distance = effective_economy * V;

        cout << max_distance << "\n";
    }

    return 0;
}