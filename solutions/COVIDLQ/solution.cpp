#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N representing spots. 1 means occupied, 0 means empty.
 * Social distancing is followed if every pair of people is at least 6 feet apart.
 * This means if there is a person at index i and another person at index j (i < j),
 * then j - i must be >= 6.
 * 
 * Algorithm:
 * Keep track of the index of the last person seen.
 * Iterate through the array. If we encounter a person (A[i] == 1):
 * 1. If this is not the first person seen, check if (current_index - last_index) < 6.
 * 2. If it is < 6, social distancing is violated (return "NO").
 * 3. Update last_index to current_index.
 * If we finish the loop without violations, return "YES".
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(1) auxiliary space.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int last_pos = -10; // Initialize with a value such that distance is > 6
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        if (A[i] == 1) {
            if (i - last_pos < 6) {
                possible = false;
                break;
            }
            last_pos = i;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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