#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: COUNTAB
 * The task is to count the occurrences of 'a' and 'b' in a given string S of length N.
 * Time Complexity: O(N) per test case, where N is the length of the string.
 * Space Complexity: O(N) to store the string.
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    long long count_a = 0;
    long long count_b = 0;

    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }

    cout << count_a << " " << count_b << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}