#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We start with N. We have two operations:
 * 1. N = N + 1
 * 2. N = next_multiple_of_5(N)
 * 
 * Since N is small (up to 100), we can use Breadth-First Search (BFS) 
 * to find the shortest path to a multiple of 3.
 * 
 * BFS state: current value of N.
 * Transitions:
 * - N -> N + 1
 * - N -> ((N / 5) + 1) * 5
 * 
 * We want the minimum operations to reach any N such that N % 3 == 0.
 */

void solve() {
    int N;
    cin >> N;

    if (N % 3 == 0) {
        cout << 0 << "\n";
        return;
    }

    // dist[i] stores minimum operations to reach i
    // Since N <= 100, the reachable numbers won't exceed a small bound.
    // Even if we jump to 105, 110, etc., it's well within limits.
    vector<int> dist(500, -1);
    queue<int> q;

    q.push(N);
    dist[N] = 0;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (curr % 3 == 0) {
            cout << dist[curr] << "\n";
            return;
        }

        // Operation 1: Add 1
        int next1 = curr + 1;
        if (next1 < 500 && dist[next1] == -1) {
            dist[next1] = dist[curr] + 1;
            q.push(next1);
        }

        // Operation 2: Next multiple of 5
        int next2 = ((curr / 5) + 1) * 5;
        if (next2 < 500 && dist[next2] == -1) {
            dist[next2] = dist[curr] + 1;
            q.push(next2);
        }
    }
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