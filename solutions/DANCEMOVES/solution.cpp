#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Chef starts at X, target Y.
 * Moves: +2 (Moonwalk), -1 (Slide).
 * 
 * If X >= Y:
 * We only use the slide move (-1).
 * Moves = X - Y.
 * 
 * If X < Y:
 * Let D = Y - X.
 * We need 2a - b = D, where a = moonwalks, b = slides.
 * Total moves = a + b.
 * Substituting b = 2a - D: Total = 3a - D.
 * To minimize, we need the smallest 'a' such that 2a >= D.
 * If D is even: a = D/2, b = 0. Total = D/2.
 * If D is odd: a = (D+1)/2, b = 1. Total = (D+1)/2 + 1.
 */

void solve() {
    long long X, Y;
    if (!(cin >> X >> Y)) return;
    
    if (X >= Y) {
        cout << (X - Y) << "\n";
    } else {
        long long D = Y - X;
        if (D % 2 == 0) {
            cout << (D / 2) << "\n";
        } else {
            // D is odd, e.g., D=1: a=1, b=1, total=2. (1+1)/2 + 1 = 2. Correct.
            // D=3: a=2, b=1, total=3. (3+1)/2 + 1 = 3. Correct.
            cout << (D + 1) / 2 + 1 << "\n";
        }
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