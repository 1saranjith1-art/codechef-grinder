#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Option 1 (No Bribe): Cost = N * 100
 * Option 2 (Bribe): Cost = K + (N * 60)
 * We need to find the minimum of these two values.
 * Constraints: N <= 10, K <= 1000. 
 * The values fit well within standard integer types, but long long is safe.
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long N, K;
    if (cin >> N >> K) {
        long long cost_no_bribe = N * 100;
        long long cost_with_bribe = K + (N * 60);

        cout << min(cost_no_bribe, cost_with_bribe) << endl;
    }

    return 0;
}