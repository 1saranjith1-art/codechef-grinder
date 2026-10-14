#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with lower health becomes 0, and the player with higher health
 * reduces by the amount of the lower health.
 * 
 * We want to know if there exists an order of fights such that A > 0 at the end.
 * 
 * Let's analyze the fights:
 * 1. Bob and Claudio fight first:
 *    The winner (the one with more health) will have health |B - C|.
 *    The loser will have 0.
 * 2. Anna fights the winner of the first match:
 *    Anna's health will be A - min(A, |B - C|).
 * 3. Anna fights the loser of the first match:
 *    Anna's health will be (A - min(A, |B - C|)) - min(A - min(A, |B - C|), 0).
 *    Since the loser of the first match has 0 health, the second fight with Anna
 *    results in 0 reduction for Anna.
 * 
 * Essentially, Anna needs to survive the fight against the "stronger" opponent 
 * between Bob and Claudio. The net health Anna has after fighting both is:
 * A - min(A, |B - C|).
 * Anna has positive health if A > |B - C|.
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // The result of the fight between B and C is that one becomes 0
    // and the other becomes abs(B - C).
    // Anna then fights the survivor.
    // Anna survives if A > abs(B - C).
    
    long long survivor_BC = abs(B - C);
    
    if (A > survivor_BC) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}