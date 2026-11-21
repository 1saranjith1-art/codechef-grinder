#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the minimum time to pluck all apples. 
 * Each operation allows us to pick a subset of trees with the same number of apples 
 * and reduce them to a value present in another tree. 
 * Effectively, each distinct value in the input array represents a group that 
 * must be processed. The minimum time required is exactly the number of 
 * distinct values present in the input.
 * 
 * Complexity:
 * Time: O(N log N) due to sorting.
 * Space: O(N) to store the apple counts.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    vector<long long> apples(n);
    for (int i = 0; i < n; ++i) {
        cin >> apples[i];
    }
    
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    
    // Sort the array to bring identical values together
    sort(apples.begin(), apples.end());
    
    // Count distinct elements
    int distinct_count = 1;
    for (int i = 1; i < n; ++i) {
        if (apples[i] != apples[i - 1]) {
            distinct_count++;
        }
    }
    
    cout << distinct_count << "\n";
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