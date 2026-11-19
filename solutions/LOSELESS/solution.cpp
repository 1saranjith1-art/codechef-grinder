#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let w = number of wins, t = number of ties, l = number of losses.
 * We have two equations:
 * 1) w + t + l = M
 * 2) 3*w + 1*t + 0*l = N  => 3*w + t = N
 * 
 * We want to minimize l.
 * From (1), l = M - (w + t).
 * To minimize l, we must maximize (w + t).
 * 
 * From (2), t = N - 3*w.
 * Substitute t into the expression for (w + t):
 * w + t = w + (N - 3*w) = N - 2*w.
 * 
 * So, l = M - (N - 2*w) = M - N + 2*w.
 * To minimize l, we need to minimize w.
 * 
 * Constraints on w:
 * 1) w >= 0
 * 2) t >= 0 => N - 3*w >= 0 => 3*w <= N => w <= N/3
 * 3) l >= 0 => M - N + 2*w >= 0 => 2*w >= N - M => w >= (N - M)/2
 * 
 * Combining these:
 * w_min = max(0, ceil((N - M) / 2.0))
 * 
 * Since we want to minimize l = M - N + 2*w, we simply pick the smallest valid w.
 */

void solve() {
    int M, N;
    cin >> M >> N;

    int min_l = M;
    
    // Iterate through all possible number of wins w
    // Since M is small (up to 20), a simple loop is perfectly efficient.
    for (int w = 0; w <= M; ++w) {
        int t = N - 3 * w;
        if (t >= 0) {
            int l = M - w - t;
            if (l >= 0) {
                if (l < min_l) {
                    min_l = l;
                }
            }
        }
    }
    cout << min_l << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}