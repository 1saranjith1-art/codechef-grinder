#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Since L and V1 are integers, ceil(L / V1) can be calculated as (L + V1 - 1) / V1 using integer division.
 * 
 * Let 'w' be the integer seconds the hare waits.
 * Hare time (T_hare) = w + ceil(L / V2)
 * The reported time for the hare is ceil(T_hare) = w + ceil(L / V2).
 * 
 * The condition to win is:
 * Reported Hare Time < Reported Tortoise Time
 * w + ceil(L / V2) < ceil(L / V1)
 * 
 * We need to find the maximum integer w >= 0 such that:
 * w < ceil(L / V1) - ceil(L / V2)
 * 
 * Let X = ceil(L / V1) - ceil(L / V2).
 * We need w < X.
 * The largest integer w is X - 1.
 * If X - 1 < 0, then the hare cannot win, so output -1.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long L, V1, V2;
        cin >> L >> V1 >> V2;

        // Calculate ceil(L / V1) and ceil(L / V2)
        // Using integer arithmetic: ceil(a/b) = (a + b - 1) / b
        long long tortoise_time = (L + V1 - 1) / V1;
        long long hare_base_time = (L + V2 - 1) / V2;

        // We need w + hare_base_time < tortoise_time
        // w < tortoise_time - hare_base_time
        long long diff = tortoise_time - hare_base_time;

        if (diff <= 0) {
            cout << -1 << "\n";
        } else {
            // The largest integer w < diff is diff - 1
            cout << (diff - 1) << "\n";
        }
    }

    return 0;
}