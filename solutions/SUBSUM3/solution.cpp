#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exists a non-empty subsequence whose sum is divisible by 3.
 * Let the remainders of the elements modulo 3 be r_i = A_i % 3.
 * 
 * Case 1: If any element A_i % 3 == 0, then that element itself is a subsequence 
 * with sum divisible by 3. Output: Yes.
 * 
 * Case 2: If there are at least three elements with remainder 1 (1+1+1 = 3) 
 * or at least three elements with remainder 2 (2+2+2 = 6), we can form a sum divisible by 3.
 * 
 * Case 3: If there is at least one element with remainder 1 and at least one element 
 * with remainder 2 (1+2 = 3), we can form a sum divisible by 3.
 * 
 * Generalizing:
 * We can use dynamic programming or a simple boolean array to track reachable remainders.
 * Let dp[r] be true if a subsequence with sum % 3 == r exists.
 * Since N is small (up to 100), we can use a simple DP approach.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // dp[r] will store if a subsequence with sum % 3 == r is possible
    // We use a boolean array of size 3.
    vector<bool> dp(3, false);

    for (int x : A) {
        int rem = x % 3;
        vector<bool> next_dp = dp;
        
        // Option 1: Start a new subsequence with this element
        next_dp[rem] = true;
        
        // Option 2: Add this element to existing subsequences
        for (int r = 0; r < 3; ++r) {
            if (dp[r]) {
                next_dp[(r + rem) % 3] = true;
            }
        }
        dp = next_dp;
    }

    if (dp[0]) {
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