#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N lights.
 * C_i = 1 (Red), C_i = 2 (Blue), C_i = 0 (Undecided).
 * We need to set all 0s to 1 or 2 such that the total count of 1s equals the total count of 2s.
 * This implies the total number of lights N must be even. If N is odd, it's impossible.
 * Let R be the number of lights already set to Red (1).
 * Let B be the number of lights already set to Blue (2).
 * Let U be the number of lights undecided (0).
 * We need to choose k lights to be Red and (U - k) lights to be Blue,
 * such that (R + k) = (B + U - k).
 * 2k = B + U - R
 * k = (B + U - R) / 2
 * 
 * For a solution to exist:
 * 1. N must be even.
 * 2. (B + U - R) must be even (which is guaranteed if N is even, since R + B + U = N).
 * 3. 0 <= k <= U, where k = (B + U - R) / 2.
 */

void solve() {
    int N;
    cin >> N;
    int R = 0, B = 0, U = 0;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        if (c == 1) R++;
        else if (c == 2) B++;
        else U++;
    }

    // A balanced configuration requires equal number of Red and Blue lights.
    // Total lights N must be even.
    if (N % 2 != 0) {
        cout << "No" << "\n";
        return;
    }

    // We need R + k = B + (U - k)
    // 2k = B + U - R
    // k = (B + U - R) / 2
    // Since R + B + U = N, then B + U = N - R
    // k = (N - R - R) / 2 = (N - 2R) / 2 = N/2 - R
    
    int k = (N / 2) - R;

    // Check if k is a valid number of lights to turn Red
    if (k >= 0 && k <= U) {
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