#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The virus starts at X and jumps by K modulo N.
 * The sequence of cities visited is:
 * X, (X+K)%N, (X+2K)%N, (X+3K)%N, ...
 * This is a sequence in a cyclic group of order N.
 * The virus will visit city Y if and only if Y is reachable from X.
 * Since N is small (up to 1000), we can simply simulate the process.
 * The virus will revisit the starting city X after at most N steps.
 * If we haven't reached Y by the time we return to X, we never will.
 */

void solve() {
    int N, K, X, Y;
    if (!(cin >> N >> K >> X >> Y)) return;

    // Use a boolean array to keep track of visited cities to detect cycles
    // or simply limit the number of jumps to N.
    vector<bool> visited(N, false);
    
    int current = X;
    bool found = false;
    
    // We can perform at most N jumps before the sequence repeats.
    for (int i = 0; i < N; ++i) {
        if (current == Y) {
            found = true;
            break;
        }
        
        // If we hit a city we've already visited and it's not Y, 
        // we are in a cycle that doesn't contain Y.
        if (visited[current]) {
            break;
        }
        
        visited[current] = true;
        current = (current + K) % N;
    }
    
    if (found) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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