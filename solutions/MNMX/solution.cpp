#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N distinct integers.
 * In each operation, we pick two adjacent elements, remove the larger one,
 * and add the smaller one to the cost.
 * We repeat this until only one element remains.
 * 
 * Let the minimum element in the array be 'min_val'.
 * To minimize the total cost, we want to ensure that every operation 
 * involves the minimum element as the smaller one, or at least avoid 
 * picking larger elements as the cost as much as possible.
 * 
 * Actually, consider the strategy:
 * We can always remove any element X by pairing it with the minimum element 
 * (if they are adjacent) or by pairing it with an adjacent element that 
 * eventually gets removed by the minimum element.
 * Specifically, if we have the minimum element 'm', we can use it to 
 * eliminate all other N-1 elements. For every other element A[i], we can 
 * perform an operation where A[i] is paired with 'm'. Since 'm' is the 
 * smallest, 'm' will always be the smaller element, and the cost will be 'm'.
 * 
 * Total cost = (N - 1) * min_val.
 * 
 * Since all elements are distinct, the minimum element is unique.
 * This strategy is optimal because we must perform N-1 operations to reduce 
 * the array to a single element, and each operation must cost at least 
 * the minimum element of the array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    long long min_val = -1;
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (i == 0 || val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum cost is (N-1) * min_val
    long long result = (long long)(n - 1) * min_val;
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}