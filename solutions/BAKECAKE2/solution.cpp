#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * For each ingredient i, we need A_i amount and we have B_i amount.
 * If A_i > B_i, we need to buy (A_i - B_i) amount.
 * If A_i <= B_i, we have enough, so we buy 0.
 * Total cost = sum of max(0, A_i - B_i) for all i from 1 to N.
 * 
 * Complexity:
 * Time: O(T * N), where T <= 100 and N <= 100. Total operations ~10^4.
 * Space: O(N) to store the ingredient requirements.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<int> a(n);
    vector<int> b(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] > b[i]) {
            total_cost += (long long)(a[i] - b[i]);
        }
    }
    cout << total_cost << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}