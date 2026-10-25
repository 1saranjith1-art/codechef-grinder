#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each household consumes 'x' liters of mandatory freshwater.
 * Each household consumes 'y' liters of greywater, which is reduced to floor(y/2).
 * Total consumption per household = x + floor(y/2).
 * Total consumption for H households = H * (x + floor(y/2)).
 * We need to check if this total consumption <= C.
 * 
 * Constraints:
 * H, x, y <= 10, C <= 100.
 * The maximum possible consumption is 10 * (10 + 10) = 200, which fits in a standard int.
 * Using long long is safe practice to prevent overflow in competitive programming.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long H, x, y, C;
        cin >> H >> x >> y >> C;

        // Calculate consumption per household
        // floor(y/2) is equivalent to y/2 in integer division
        long long consumption_per_household = x + (y / 2);
        
        // Calculate total consumption for all households
        long long total_consumption = H * consumption_per_household;

        // Check if total consumption is within the available capacity C
        if (total_consumption <= C) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}