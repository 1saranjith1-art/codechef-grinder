#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have 2N total players, X of whom are rated.
 * We want to minimize the number of rated players paired with other rated players.
 * 
 * Let R = X (rated players)
 * Let U = 2N - X (unrated players)
 * 
 * Each pair involving an unrated player can "absorb" one rated player without 
 * that rated player being paired with another rated player.
 * We have U unrated players, so we can form at most U pairs that contain 
 * at least one unrated player.
 * 
 * If X <= N, we can pair all X rated players with X unrated players. 
 * The number of rated players with rated opponents is 0.
 * 
 * If X > N, we have more rated players than unrated players.
 * We have U unrated players available. We can use these U unrated players to 
 * pair with U rated players.
 * Remaining rated players = X - U.
 * Since these remaining players must be paired with each other, and each pair 
 * consists of 2 rated players, the number of rated players with rated opponents 
 * is simply (X - U).
 * 
 * Substituting U = 2N - X:
 * X - (2N - X) = 2X - 2N.
 * 
 * Thus, if X <= N, answer is 0.
 * If X > N, answer is 2 * (X - N).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        if (x <= n) {
            cout << 0 << "\n";
        } else {
            // Number of rated players who must be paired with each other
            // Each pair of rated players contributes 2 to the count.
            // Number of pairs of rated players = (x - (2n - x)) / 2 = x - n
            // Total rated players with rated opponents = 2 * (x - n)
            cout << 2 * (x - n) << "\n";
        }
    }

    return 0;
}