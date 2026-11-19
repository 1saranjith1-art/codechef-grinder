#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A soldier i is attacked by their neighbors (i-1) and (i+1).
 * Let the neighbors be L = (i-1) and R = (i+1).
 * Note: Indices are circular, so for i=0, L=N-1, R=1.
 * The soldier i survives if their defense d[i] is strictly greater than 
 * the sum of attack values of any combination of neighbors that choose to attack.
 * 
 * The worst-case scenario for soldier i is that BOTH neighbors choose to attack.
 * If d[i] > (a[L] + a[R]), then soldier i is guaranteed to survive regardless 
 * of whether the neighbors choose to attack or not.
 * 
 * We need to find the maximum d[i] among all soldiers who satisfy this condition.
 * If no soldier satisfies this, output -1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> a(N), d(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    for (int i = 0; i < N; ++i) cin >> d[i];

    long long max_defense = -1;

    for (int i = 0; i < N; ++i) {
        // Identify neighbors in circular array
        int left = (i - 1 + N) % N;
        int right = (i + 1) % N;

        // The maximum possible attack power on soldier i is a[left] + a[right]
        long long max_attack = a[left] + a[right];

        // Check if the soldier is guaranteed to survive
        if (d[i] > max_attack) {
            if (d[i] > max_defense) {
                max_defense = d[i];
            }
        }
    }

    cout << max_defense << "\n";
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