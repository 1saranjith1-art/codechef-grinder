#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sold individually = 3 coins.
 * A bundle (1R, 1B, 1G) = 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 * Total coins = 10k + 3(R + B + G - 3k)
 * Total coins = 10k + 3(R + B + G) - 9k
 * Total coins = 3(R + B + G) + k
 * 
 * To maximize this, we need to maximize k.
 * Since k is the number of bundles, the maximum k is min(R, B, G).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long R, B, G;
        cin >> R >> B >> G;

        // Maximum number of bundles possible
        long long k = min({R, B, G});

        // Calculate total coins
        // Each bundle gives 10 coins, remaining gems give 3 coins each
        long long total_coins = (k * 10) + ((R - k) + (B - k) + (G - k)) * 3;

        cout << total_coins << "\n";
    }

    return 0;
}