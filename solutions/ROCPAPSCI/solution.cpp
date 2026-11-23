#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to maximize wins against Roku's moves A[i].
 * Winning moves:
 * If A[i] == 'R', Chef wins with 'P'.
 * If A[i] == 'P', Chef wins with 'S'.
 * If A[i] == 'S', Chef wins with 'R'.
 * 
 * Constraint: Chef cannot make the same move twice consecutively.
 * This is a Dynamic Programming problem.
 * Let dp[i][move] be the maximum wins up to game i, where Chef plays 'move' at game i.
 * 'move' can be 0 (R), 1 (P), or 2 (S).
 * 
 * dp[i][m] = (win if m beats A[i]) + max(dp[i-1][prev_m]) where prev_m != m.
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // dp[m] stores the max wins ending with move m at the current index
    // Initialize with 0
    vector<int> dp(3, 0);

    auto get_win = [&](char move, char roku) {
        if (move == 'R' && roku == 'S') return 1;
        if (move == 'P' && roku == 'R') return 1;
        if (move == 'S' && roku == 'P') return 1;
        return 0;
    };

    auto move_to_idx = [&](char m) {
        if (m == 'R') return 0;
        if (m == 'P') return 1;
        return 2;
    };

    // Base case for the first game
    dp[0] = get_win('R', A[0]);
    dp[1] = get_win('P', A[0]);
    dp[2] = get_win('S', A[0]);

    for (int i = 1; i < N; ++i) {
        vector<int> next_dp(3, 0);
        char roku = A[i];
        
        for (int m = 0; m < 3; ++m) {
            char move_char = (m == 0 ? 'R' : (m == 1 ? 'P' : 'S'));
            int win = get_win(move_char, roku);
            
            // Chef can choose any previous move except m
            int prev_max = 0;
            for (int prev_m = 0; prev_m < 3; ++prev_m) {
                if (prev_m != m) {
                    prev_max = max(prev_max, dp[prev_m]);
                }
            }
            next_dp[m] = win + prev_max;
        }
        dp = next_dp;
    }

    cout << max({dp[0], dp[1], dp[2]}) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}