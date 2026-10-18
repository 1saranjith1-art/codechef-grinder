#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an initial sequence X and a transformed sequence Y.
 * We need to find if there exists a pivot index i (1 <= i <= N) such that
 * if we define P = X[i], and create a list L of pairs (|X[j] - P|, X[j]),
 * sorting L according to the specified rules results in the sequence Y.
 * 
 * Constraints: N <= 100.
 * Since N is small, we can iterate through every possible pivot index i from 1 to N.
 * For each pivot, we construct the list L, sort it, and compare the resulting
 * sequence of second elements with the given sequence Y.
 * 
 * Time Complexity: O(T * N * N log N), which is well within the 1s limit for N=100.
 */

struct Point {
    int dist;
    int val;
};

bool comparePoints(const Point& a, const Point& b) {
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }
    return a.val < b.val;
}

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) cin >> X[i];
    vector<int> Y(N);
    for (int i = 0; i < N; ++i) cin >> Y[i];

    for (int i = 0; i < N; ++i) {
        int P = X[i];
        vector<Point> L(N);
        for (int j = 0; j < N; ++j) {
            L[j] = {abs(X[j] - P), X[j]};
        }

        sort(L.begin(), L.end(), comparePoints);

        bool match = true;
        for (int k = 0; k < N; ++k) {
            if (L[k].val != Y[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            cout << (i + 1) << "\n";
            return;
        }
    }

    cout << -1 << "\n";
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