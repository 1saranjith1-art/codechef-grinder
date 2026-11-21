#include <bits/stdc++.h>
using namespace std;

/**
 * Strategy:
 * For N < 4, no solution exists (N=2, 3).
 * For N >= 4, we can print all even numbers followed by all odd numbers.
 * Example N=4: 2, 4, 1, 3. |4-2|=2, |1-4|=3, |3-1|=2. (Valid)
 * Example N=5: 2, 4, 1, 3, 5. |4-2|=2, |1-4|=3, |3-1|=2, |5-3|=2. (Valid)
 * Example N=6: 2, 4, 6, 1, 3, 5. |4-2|=2, |6-4|=2, |1-6|=5, |3-1|=2, |5-3|=2. (Valid)
 */

void solve() {
    int N;
    cin >> N;

    if (N < 4) {
        cout << -1 << "\n";
        return;
    }

    // Print all even numbers
    for (int i = 2; i <= N; i += 2) {
        cout << i << " ";
    }
    // Print all odd numbers
    for (int i = 1; i <= N; i += 2) {
        cout << i << (i + 2 > N ? "" : " ");
    }
    cout << "\n";
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