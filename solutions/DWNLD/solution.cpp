#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N intervals, each with duration Ti and data rate Di.
 * The first K minutes are free.
 * We need to calculate the total cost for the remaining minutes.
 * 
 * Strategy:
 * Iterate through each interval (Ti, Di).
 * If K >= Ti, it means the entire interval is free. Subtract Ti from K.
 * If K < Ti, it means the first K minutes of this interval are free, 
 * and the remaining (Ti - K) minutes are charged at Di dollars per minute.
 * After this, K becomes 0, and all subsequent intervals are fully charged.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    long long total_cost = 0;
    for (int i = 0; i < N; ++i) {
        int T, D;
        cin >> T >> D;
        
        if (K >= T) {
            // Entire interval is free
            K -= T;
        } else {
            // Part of the interval is free, part is charged
            // The charged duration is (T - K)
            int charged_minutes = T - K;
            total_cost += (long long)charged_minutes * D;
            // After this, all remaining minutes are charged
            K = 0;
        }
    }
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int TC;
    cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}