#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. The length Ni must be odd for a unique center to exist.
 *    If Ni is even, it's impossible to have an equal number of parts on both sides.
 * 2. The first element H[0] must be 1.
 * 3. The last element H[Ni-1] must be 1.
 * 4. The sequence must increase by 1 until the middle element (index Ni/2).
 * 5. The sequence must decrease by 1 from the middle element to the end.
 * 
 * Time Complexity: O(Ni) per test case, total O(S * Ni).
 * Space Complexity: O(Ni) to store the heights.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    // Condition 1: Length must be odd
    if (N % 2 == 0) {
        cout << "no" << "\n";
        return;
    }

    // Condition 2: Start and end must be 1
    if (H[0] != 1 || H[N - 1] != 1) {
        cout << "no" << "\n";
        return;
    }

    int mid = N / 2;

    // Condition 3 & 4: Check increasing and decreasing pattern
    // Left side: H[i] should be i + 1
    for (int i = 0; i <= mid; ++i) {
        if (H[i] != i + 1) {
            cout << "no" << "\n";
            return;
        }
    }

    // Right side: H[i] should be N - i
    for (int i = mid + 1; i < N; ++i) {
        if (H[i] != N - i) {
            cout << "no" << "\n";
            return;
        }
    }

    cout << "yes" << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int S;
    if (!(cin >> S)) return 0;
    while (S--) {
        solve();
    }
    return 0;
}