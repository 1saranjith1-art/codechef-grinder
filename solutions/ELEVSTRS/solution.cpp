#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Stairs:
 *    - Distance = N * sqrt(2)
 *    - Velocity = V1
 *    - Time_stairs = (N * sqrt(2)) / V1
 * 
 * 2. Elevator:
 *    - The elevator starts at ground, goes to N (distance N), then back to ground (distance N).
 *    - Total distance = 2 * N
 *    - Velocity = V2
 *    - Time_elevator = (2 * N) / V2
 * 
 * To compare Time_stairs < Time_elevator:
 * (N * sqrt(2)) / V1 < (2 * N) / V2
 * sqrt(2) / V1 < 2 / V2
 * sqrt(2) * V2 < 2 * V1
 * 
 * Squaring both sides (since both sides are positive):
 * 2 * V2^2 < 4 * V1^2
 * V2^2 < 2 * V1^2
 * 
 * Alternatively, we can just use double precision floating point arithmetic 
 * to compare the times directly, as N, V1, V2 are small (up to 100).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        double n, v1, v2;
        cin >> n >> v1 >> v2;

        // Time taken for stairs: distance / velocity
        double time_stairs = (n * sqrt(2.0)) / v1;
        
        // Time taken for elevator: 
        // Elevator travels N meters up (to get Chef) and N meters down (to ground)
        double time_elevator = (2.0 * n) / v2;

        if (time_stairs < time_elevator) {
            cout << "Stairs" << "\n";
        } else {
            cout << "Elevator" << "\n";
        }
    }

    return 0;
}