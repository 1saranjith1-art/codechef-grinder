#include <iostream>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * Center is (cx, cy) = ((N+1)/2, (N+1)/2).
 * Diagonal moves: (x, y) -> (x±1, y±1). These moves change both x and y by 1,
 * so (x - y) remains constant modulo 2.
 * Horizontal/Vertical moves: (x, y) -> (x±1, y) or (x, y±1). These change
 * the parity of (x - y).
 * 
 * To reach (cx, cy) from (xs, ys):
 * If (xs - cx) and (ys - cy) have the same parity, then (xs - ys) has the same 
 * parity as (cx - cy). Since cx = cy, (cx - cy) = 0 (even).
 * Therefore, if (xs - ys) is even, cost is 0.
 * If (xs - ys) is odd, we need 1 move to change the parity.
 */

void solve() {
    long long N, xs, ys;
    if (!(cin >> N >> xs >> ys)) return;
    
    long long cx = (N + 1) / 2;
    long long cy = (N + 1) / 2;
    
    // Calculate the absolute differences
    long long dx = abs(xs - cx);
    long long dy = abs(ys - cy);
    
    // If both differences have the same parity, we can reach the center 
    // using only diagonal moves (cost 0). Otherwise, we need 1 move.
    if (dx % 2 == dy % 2) {
        cout << 0 << "\n";
    } else {
        cout << 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}