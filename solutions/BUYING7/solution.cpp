#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N items with prices C_i. We need to find the sum of the K most expensive items.
 * To do this, we can sort the array of prices in descending order and sum the first K elements.
 * 
 * Constraints:
 * T <= 100, N <= 100, C_i <= 100.
 * The maximum possible sum would be 100 * 100 = 10,000, which fits in a standard int.
 * However, using long long is good practice to prevent overflow in similar problems.
 * Time Complexity: O(T * N log N) due to sorting.
 * Space Complexity: O(N) to store the prices.
 */

void solve() {
    int N, K;
    if (!(cin >> N >> K)) return;
    
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
    }
    
    // Sort in descending order to easily pick the K most expensive items
    sort(C.begin(), C.end(), greater<int>());
    
    long long total_cost = 0;
    for (int i = 0; i < K; ++i) {
        total_cost += C[i];
    }
    
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}