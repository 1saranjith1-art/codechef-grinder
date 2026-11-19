#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice starts at (0, 0). Bob starts at (X, Y).
 * After k seconds (1 <= k <= N), Alice is at some position (Ax_k, Ay_k).
 * Bob is at (X, Y) initially. After k seconds, Bob is at (Bx_k, By_k).
 * The Manhattan distance between Bob's starting position and Alice's position at time k is:
 * dist = |Ax_k - X| + |Ay_k - Y|.
 * 
 * Bob can reach Alice's position at time k if and only if:
 * 1. The Manhattan distance between Bob's start and Alice's position is <= k.
 * 2. The parity of the Manhattan distance is the same as the parity of k.
 *    (i.e., (k - dist) % 2 == 0 and k >= dist).
 * 
 * This is because in each second, Bob can change the Manhattan distance to a target 
 * point by exactly 1 or -1. To reach a point in k steps, he needs at most k steps,
 * and the parity must match because each step changes the sum of coordinates by 1.
 */

void solve() {
    int N;
    long long X, Y;
    cin >> N >> X >> Y;
    string S;
    cin >> S;

    long long ax = 0, ay = 0;
    bool possible = false;

    for (int k = 1; k <= N; ++k) {
        char move = S[k - 1];
        if (move == 'L') ax -= 1;
        else if (move == 'R') ax += 1;
        else if (move == 'U') ay += 1;
        else if (move == 'D') ay -= 1;

        long long dist = abs(ax - X) + abs(ay - Y);
        
        // Bob can reach (ax, ay) at time k if:
        // 1. He has enough time (k >= dist)
        // 2. The parity of the distance matches the time (k % 2 == dist % 2)
        if (k >= dist && (k % 2 == dist % 2)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}