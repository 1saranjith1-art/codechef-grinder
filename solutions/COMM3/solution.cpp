#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: COMM3 - Communicating Transceivers
 * Logic: We have 3 points. They can communicate if the graph formed by 
 * edges (where distance <= R) is connected. 
 * For 3 nodes, this is true if at least 2 edges exist.
 */

long long distSq(long long x1, long long y1, long long x2, long long y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void solve() {
    long long R;
    cin >> R;
    long long R2 = R * R;
    
    long long x[3], y[3];
    for (int i = 0; i < 3; ++i) {
        cin >> x[i] >> y[i];
    }
    
    int edges = 0;
    // Check distance between (0,1), (1,2), and (0,2)
    if (distSq(x[0], y[0], x[1], y[1]) <= R2) edges++;
    if (distSq(x[1], y[1], x[2], y[2]) <= R2) edges++;
    if (distSq(x[0], y[0], x[2], y[2]) <= R2) edges++;
    
    // If 2 or 3 edges exist, they are connected.
    if (edges >= 2) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
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