#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each room must have at least X boys and Y girls.
 * Total capacity of each room is at most N.
 * Therefore, each room must contain at least (X + Y) people.
 * If (X + Y) > N, it is impossible to satisfy the constraints, so output -1.
 * 
 * Let k be the number of rooms.
 * We need:
 * 1. k * X <= B (Total boys must be distributed such that each room has >= X)
 * 2. k * Y <= G (Total girls must be distributed such that each room has >= Y)
 * 3. k * (X + Y) <= B + G (Total people constraint, though this is implied by 1 and 2)
 * 4. k * N >= B + G (Total capacity must be enough for all people)
 * 
 * From 1 and 2, k <= floor(B/X) and k <= floor(G/Y).
 * So, k <= min(floor(B/X), floor(G/Y)).
 * 
 * From 4, k >= ceil((B + G) / N).
 * 
 * Let min_rooms = ceil((B + G) / N).
 * Let max_rooms = min(floor(B/X), floor(G/Y)).
 * 
 * If min_rooms > max_rooms, it is impossible, output -1.
 * Otherwise, the minimum number of rooms is min_rooms.
 */

void solve() {
    long long B, G, X, Y, N;
    cin >> B >> G >> X >> Y >> N;

    // Condition: Each room needs at least X boys and Y girls.
    // Total people per room >= X + Y.
    // If X + Y > N, we cannot even form one valid room.
    if (X + Y > N) {
        cout << -1 << "\n";
        return;
    }

    // Minimum rooms required to fit all people given capacity N:
    // ceil((B + G) / N)
    long long min_rooms = (B + G + N - 1) / N;

    // Maximum rooms possible given the constraints on boys and girls:
    // Each room must have at least X boys and Y girls.
    // So we can have at most B/X rooms and G/Y rooms.
    long long max_rooms = min(B / X, G / Y);

    if (min_rooms > max_rooms) {
        cout << -1 << "\n";
    } else {
        cout << min_rooms << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}