# [Rock Paper Scissors (ROCPAPSCI)](https://www.codechef.com/problems/ROCPAPSCI)

- **Difficulty Rating**: 1220
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef is playing a game of Rock-Paper-Scissors against Roku for $N$ rounds. Roku's moves are given as a string $A$. Chef wants to maximize the total number of wins. The constraint is that Chef cannot play the same move twice in two consecutive rounds.

## Intuition & Mathematical Observation
This problem can be modeled using **Dynamic Programming**. Since the choice of the current move depends only on the move made in the previous round (due to the constraint), we can maintain the maximum wins achieved ending with each possible move ('R', 'P', or 'S').

1.  **State Definition**: Let `dp[m]` be the maximum number of wins Chef can have after the current round, given that Chef played move `m` in this round.
2.  **Transitions**: For each round $i$, if Chef chooses move `m`, the number of wins is:
    `dp_new[m] = (1 if m beats A[i] else 0) + max(dp_old[prev_m])` for all `prev_m != m`.
3.  **Base Case**: For the first round, `dp[m]` is simply 1 if `m` beats `A[0]`, and 0 otherwise.
4.  **Optimization**: Since we only need the values from the previous round, we can use two vectors of size 3 to store the DP states, keeping the space complexity constant.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of rounds. We iterate through the string once, and for each character, we perform a constant number of operations (checking 3 possible moves).
- **Space Complexity**: $O(1)$, as we only store a fixed-size array of length 3 regardless of the input size $N$.

## Solution Code

```cpp
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
 */

void solve() {
    int N;
    cin >> N;
    string A;
    cin >> A;

    // dp[m] stores the max wins ending with move m at the current index
    // 0: R, 1: P, 2: S
    vector<int> dp(3, 0);

    auto get_win = [&](char move, char roku) {
        if (move == 'R' && roku == 'S') return 1;
        if (move == 'P' && roku == 'R') return 1;
        if (move == 'S' && roku == 'P') return 1;
        return 0;
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
```